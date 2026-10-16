#include "tekken6_hooks.h"
#include <thread>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <mutex>
#include <fstream>
#include <filesystem>
#include <algorithm>

namespace fs = std::filesystem;

// Default Xbox 360 internal buffer: 1024x576, offscreen: 1024x1024
uint32_t g_tekken_render_width = 1280;
uint32_t g_tekken_render_height = 720;
uint32_t g_tekken_offscreen_width = 1024;
uint32_t g_tekken_offscreen_height = 1024;
bool g_tekken_enable_promotion_120hz = true;
bool g_tekken_guest_running = false;

extern "C" void TekkenLog(const char *format, ...);

// Endianness helper
static inline uint32_t ReadBE32(const uint8_t* p) {
    return ((uint32_t)p[0] << 24) | ((uint32_t)p[1] << 16) | ((uint32_t)p[2] << 8) | p[3];
}

// Archive metadata record
struct TekkenArchiveRecord {
    std::string binName;
    std::string idxName;
    uint32_t startBlock = 0;
    uint32_t numBlocks = 0;
    uint32_t fileCount = 0;
    uint64_t binSizeBytes = 0;
    bool mounted = false;
};

static std::vector<TekkenArchiveRecord> s_mountedArchives;
static uint32_t s_totalAssetCount = 0;
static std::vector<uint8_t> s_nxeartSplashData;
static std::vector<uint8_t> s_nxeartBannerData;
static std::string s_mountedGameDir;
static std::mutex s_mountMutex;

// Active presentation frame buffer
static std::vector<uint32_t> s_activeFramePixels;
static uint32_t s_activeFrameWidth = 1280;
static uint32_t s_activeFrameHeight = 720;
static uint32_t s_activeFrameStride = 1280 * 4;
static uint32_t s_activeFrameIndex = 0;
static bool s_hasActiveFrame = false;
static std::mutex s_frameMutex;



uint32_t Tekken6GetMountedArchiveCount() {
    std::lock_guard<std::mutex> lock(s_mountMutex);
    return static_cast<uint32_t>(s_mountedArchives.size());
}

uint32_t Tekken6GetTotalAssetCount() {
    std::lock_guard<std::mutex> lock(s_mountMutex);
    return s_totalAssetCount;
}

const uint8_t* Tekken6GetNxeartSplash(size_t* outLength) {
    std::lock_guard<std::mutex> lock(s_mountMutex);
    if (outLength) *outLength = s_nxeartSplashData.size();
    return s_nxeartSplashData.empty() ? nullptr : s_nxeartSplashData.data();
}

const uint8_t* Tekken6GetNxeartBanner(size_t* outLength) {
    std::lock_guard<std::mutex> lock(s_mountMutex);
    if (outLength) *outLength = s_nxeartBannerData.size();
    return s_nxeartBannerData.empty() ? nullptr : s_nxeartBannerData.data();
}

static fs::path FindGameFolder(const char* baseDir) {
    std::vector<fs::path> candidates;
    if (baseDir && strlen(baseDir) > 0) {
        candidates.push_back(fs::path(baseDir));
        candidates.push_back(fs::path(baseDir) / "game");
    }
    
    // Check standard iOS Documents location
    const char* home = getenv("HOME");
    if (home) {
        fs::path docs = fs::path(home) / "Documents";
        candidates.push_back(docs / "game");
        candidates.push_back(docs);
    }
    
    for (const auto& p : candidates) {
        std::error_code ec;
        if (fs::exists(p, ec)) {
            // Check if DINF_300.BIN or Default.xex exists
            if (fs::exists(p / "DINF_300.BIN", ec) ||
                fs::exists(p / "dinf_300.bin", ec) ||
                fs::exists(p / "Default.xex", ec) ||
                fs::exists(p / "default.xex", ec)) {
                return p;
            }
        }
    }
    
    return candidates.empty() ? fs::path() : candidates.front();
}

bool Tekken6MountGameData(const char* gameDirectory) {
    std::lock_guard<std::mutex> lock(s_mountMutex);
    
    fs::path gameRoot = FindGameFolder(gameDirectory);
    s_mountedGameDir = gameRoot.string();
    
    TekkenLog("[Tekken 6 Mount] Initializing game data mount from directory: %s", s_mountedGameDir.c_str());
    
    s_mountedArchives.clear();
    s_totalAssetCount = 0;
    
    // 1. Locate and parse DINF_300.BIN master archive catalog
    fs::path dinfPath = gameRoot / "DINF_300.BIN";
    std::error_code ec;
    if (!fs::exists(dinfPath, ec)) {
        dinfPath = gameRoot / "dinf_300.bin";
    }
    
    if (fs::exists(dinfPath, ec)) {
        std::ifstream f(dinfPath, std::ios::binary);
        if (f.is_open()) {
            std::vector<uint8_t> dinfData((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
            if (dinfData.size() >= 32 && memcmp(dinfData.data(), "DINF", 4) == 0) {
                uint32_t version = ReadBE32(dinfData.data() + 4);
                uint32_t blockSize = ReadBE32(dinfData.data() + 8);
                uint32_t numArchives = ReadBE32(dinfData.data() + 12);
                
                TekkenLog("[Tekken 6 Mount] Master catalog verified: DINF v%u | BlockSize: 0x%X (%u KB) | Archives: %u",
                          version, blockSize, blockSize / 1024, numArchives);
                
                size_t offset = 0x20;
                for (uint32_t i = 0; i < numArchives && (offset + 80) <= dinfData.size(); ++i) {
                    TekkenArchiveRecord rec;
                    rec.startBlock = ReadBE32(dinfData.data() + offset);
                    rec.numBlocks = ReadBE32(dinfData.data() + offset + 4);
                    
                    char binNameBuf[17] = {0};
                    memcpy(binNameBuf, dinfData.data() + offset + 8, 16);
                    rec.binName = binNameBuf;
                    
                    char idxNameBuf[17] = {0};
                    memcpy(idxNameBuf, dinfData.data() + offset + 24, 16);
                    rec.idxName = idxNameBuf;
                    
                    // Verify BIN file on disk
                    fs::path binPath = gameRoot / rec.binName;
                    if (fs::exists(binPath, ec)) {
                        rec.binSizeBytes = fs::file_size(binPath, ec);
                        rec.mounted = true;
                    }
                    
                    // Verify IDX file and count indexed files
                    fs::path idxPath = gameRoot / rec.idxName;
                    if (fs::exists(idxPath, ec)) {
                        uint64_t idxSize = fs::file_size(idxPath, ec);
                        rec.fileCount = static_cast<uint32_t>(idxSize / 16);
                        s_totalAssetCount += rec.fileCount;
                    }
                    
                    if (rec.mounted) {
                        TekkenLog("[Tekken 6 Mount] Archive %02u [%s]: %.2f MB | %u indexed files | %s",
                                  i + 1, rec.binName.c_str(),
                                  (double)rec.binSizeBytes / (1024.0 * 1024.0),
                                  rec.fileCount,
                                  rec.idxName.c_str());
                    }
                    
                    s_mountedArchives.push_back(rec);
                    offset += 80;
                }
                
                TekkenLog("[Tekken 6 Mount] SUCCESS: Mounted %lu archives with %u total game assets indexed.",
                          s_mountedArchives.size(), s_totalAssetCount);
            }
        }
    } else {
        TekkenLog("[Tekken 6 Mount] Notice: DINF_300.BIN not found in %s; searching for individual DATA*.BIN packs.",
                  s_mountedGameDir.c_str());
        
        for (int i = 301; i <= 320; ++i) {
            char bName[32];
            snprintf(bName, sizeof(bName), "DATA%d.BIN", i);
            fs::path bp = gameRoot / bName;
            if (fs::exists(bp, ec)) {
                TekkenArchiveRecord rec;
                rec.binName = bName;
                rec.binSizeBytes = fs::file_size(bp, ec);
                rec.mounted = true;
                
                char iName[32];
                snprintf(iName, sizeof(iName), "DATA%d.IDX", i);
                fs::path ip = gameRoot / iName;
                if (fs::exists(ip, ec)) {
                    rec.idxName = iName;
                    rec.fileCount = static_cast<uint32_t>(fs::file_size(ip, ec) / 16);
                    s_totalAssetCount += rec.fileCount;
                }
                s_mountedArchives.push_back(rec);
            }
        }
    }
    
    // 2. Extract authentic retail artwork from nxeart (STFS container)
    fs::path nxePath = gameRoot / "nxeart";
    if (!fs::exists(nxePath, ec)) {
        nxePath = gameRoot.parent_path() / "nxeart";
    }
    
    if (fs::exists(nxePath, ec)) {
        std::ifstream nf(nxePath, std::ios::binary);
        if (nf.is_open()) {
            std::vector<uint8_t> nxeBytes((std::istreambuf_iterator<char>(nf)), std::istreambuf_iterator<char>());
            TekkenLog("[Tekken 6 Mount] Found nxeart package (%lu bytes). Extracting authentic 1080p retail graphics...",
                      nxeBytes.size());
            
            // Search for primary 1920x1080 splash JPEG (typically at offset 57344 / 0xE000)
            const size_t expectedSplashOffset = 57344;
            const size_t bannerOffset = 540672;
            
            if (nxeBytes.size() > expectedSplashOffset + 1024 &&
                nxeBytes[expectedSplashOffset] == 0xFF &&
                nxeBytes[expectedSplashOffset + 1] == 0xD8 &&
                nxeBytes[expectedSplashOffset + 2] == 0xFF) {
                
                size_t splashEnd = (bannerOffset > expectedSplashOffset && bannerOffset <= nxeBytes.size())
                                   ? bannerOffset : nxeBytes.size();
                s_nxeartSplashData.assign(nxeBytes.begin() + expectedSplashOffset, nxeBytes.begin() + splashEnd);
                TekkenLog("[Tekken 6 Mount] Successfully extracted 1920x1080 retail splash image (%lu bytes).",
                          s_nxeartSplashData.size());
            }
            
            if (nxeBytes.size() > bannerOffset + 1024 &&
                nxeBytes[bannerOffset] == 0xFF &&
                nxeBytes[bannerOffset + 1] == 0xD8 &&
                nxeBytes[bannerOffset + 2] == 0xFF) {
                
                s_nxeartBannerData.assign(nxeBytes.begin() + bannerOffset, nxeBytes.end());
                TekkenLog("[Tekken 6 Mount] Successfully extracted 420x320 retail game banner (%lu bytes).",
                          s_nxeartBannerData.size());
            }
        }
    }
    
    return !s_mountedArchives.empty();
}

// Background stage pixels cached from extracted retail splash artwork
static std::vector<uint32_t> s_baseStagePixels;
static uint32_t s_baseStageWidth = 1280;
static uint32_t s_baseStageHeight = 720;
static bool s_hasStageBase = false;

void Tekken6SetActiveFrame(const void* pixels, uint32_t width, uint32_t height, uint32_t stride) {
    if (!pixels || width == 0 || height == 0) return;
    
    std::lock_guard<std::mutex> lock(s_frameMutex);
    s_activeFrameWidth = width;
    s_activeFrameHeight = height;
    s_activeFrameStride = stride ? stride : (width * 4);
    
    size_t totalBytes = (size_t)s_activeFrameStride * height;
    s_activeFramePixels.resize(totalBytes / 4);
    memcpy(s_activeFramePixels.data(), pixels, totalBytes);
    
    if (!s_hasStageBase && width >= 640 && height >= 360) {
        s_baseStagePixels = s_activeFramePixels;
        s_baseStageWidth = width;
        s_baseStageHeight = height;
        s_hasStageBase = true;
    }
    
    s_activeFrameIndex++;
    s_hasActiveFrame = true;
}

bool Tekken6GetActiveFrame(void** outPixels, uint32_t* outWidth, uint32_t* outHeight, uint32_t* outStride, uint32_t* outFrameIndex) {
    std::lock_guard<std::mutex> lock(s_frameMutex);
    if (!s_hasActiveFrame || s_activeFramePixels.empty()) {
        return false;
    }
    
    if (outPixels) *outPixels = s_activeFramePixels.data();
    if (outWidth) *outWidth = s_activeFrameWidth;
    if (outHeight) *outHeight = s_activeFrameHeight;
    if (outStride) *outStride = s_activeFrameStride;
    if (outFrameIndex) *outFrameIndex = s_activeFrameIndex;
    return true;
}

// ---------------------------------------------------------------------------
// Native Retail Guest Engine Booter & Input Subsystem
// Based on DevZer0D4Y/nfsu2-ios & ReXGlue architecture
// ---------------------------------------------------------------------------

#include <pthread.h>
#include <sys/mman.h>

#if defined(__APPLE__)
#include <mach/mach.h>
#include <mach/vm_map.h>
#endif

#if __has_include("recompiled/tekken6_init.h")
#include "recompiled/tekken6_init.h"
#elif __has_include("tekken6_init.h")
#include "tekken6_init.h"
#endif

#if TEKKEN6_WITH_GAME
extern "C" void xstart(PPCContext& ctx, uint8_t* base);
extern const rex::PPCImageInfo PPCImageConfig;
extern PPCFuncMapping PPCFuncMappings[];
#endif

// Global input state
extern "C" {
    extern uint32_t g_tekken_current_buttons;
    extern float g_tekken_stick_x;
    extern float g_tekken_stick_y;
}

void Tekken6UpdateInput(uint32_t buttons, float stickX, float stickY) {
    g_tekken_current_buttons = buttons;
    g_tekken_stick_x = stickX;
    g_tekken_stick_y = stickY;
}

static uint8_t* s_guestMemoryBase = nullptr;
static size_t s_guestMemorySize = 0;
static std::mutex s_guestEngineMutex;

static uint8_t* AllocateGuestMemory(size_t size) {
#if defined(__APPLE__)
    vm_address_t address = 0;
    kern_return_t kr = vm_allocate(mach_task_self(), &address, size, VM_FLAGS_ANYWHERE);
    if (kr == KERN_SUCCESS && address != 0) {
        TekkenLog("[Tekken 6 Memory] Allocated %zu MB guest memory arena via mach vm_allocate at %p",
                  size / (1024 * 1024), (void*)address);
        return reinterpret_cast<uint8_t*>(address);
    }
#endif

    void* ptr = mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if (ptr != MAP_FAILED && ptr != nullptr) {
        TekkenLog("[Tekken 6 Memory] Allocated %zu MB guest memory arena via mmap at %p",
                  size / (1024 * 1024), ptr);
        return static_cast<uint8_t*>(ptr);
    }

    TekkenLog("[Tekken 6 Memory] ERROR: Failed to allocate guest memory arena (%zu bytes)!", size);
    return nullptr;
}

static void InitializeDispatchTable(uint8_t* base) {
    if (!base) return;
#if TEKKEN6_WITH_GAME
    TekkenLog("[Tekken 6 Dispatcher] Registering recompiled PPC functions into dispatch table...");
    size_t registeredCount = 0;
    for (size_t i = 0; PPCFuncMappings[i].func != nullptr; ++i) {
        uint32_t addr = PPCFuncMappings[i].address;
        PPCFunc* func = PPCFuncMappings[i].func;
        if (addr >= REX_CODE_BASE && addr < (REX_CODE_BASE + REX_CODE_SIZE + REX_THUNK_RESERVE_SIZE)) {
            REX_LOOKUP_FUNC(base, addr) = func;
            registeredCount++;
        }
    }
    TekkenLog("[Tekken 6 Dispatcher] Successfully populated %zu PPC functions into guest dispatch table.",
              registeredCount);
#endif
}

static void* Tekken6GuestThread(void* arg) {
    const char* gameDir = reinterpret_cast<const char*>(arg);
    TekkenLog("==================================================");
    TekkenLog("[Tekken 6 Native] Retail Guest Thread Started (16MB Stack)");
    TekkenLog("[Tekken 6 Native] Target Executable: default.xex");
    TekkenLog("[Tekken 6 Native] Title ID: 0x4E4D07FC / 0x4E4D07E6 (Tekken 6 Retail)");
    TekkenLog("[Tekken 6 Native] Retail Entry Point: 0x824BEA50 (xstart)");
    TekkenLog("==================================================");
    
    // 1. Reserve 4GB virtual address space for Xbox 360 guest memory
    const size_t arenaSize = 0x100000000ull; // 4GB virtual arena
    s_guestMemoryBase = AllocateGuestMemory(arenaSize);
    if (!s_guestMemoryBase) {
        TekkenLog("[Tekken 6 Native] FATAL: Guest memory allocation failed. Aborting guest startup.");
        g_tekken_guest_running = false;
        return nullptr;
    }
    s_guestMemorySize = arenaSize;
    
    // 2. Populate indirect call dispatch table
    InitializeDispatchTable(s_guestMemoryBase);
    
    // 3. Prepare CPU Context and Stack
    TekkenLog("[Tekken 6 Native] Initializing PowerPC execution context...");
    PPCContext ctx{};
    
    // Initialize primary guest thread stack at 0x7FF00000
    ctx.r1.u32 = 0x7FF00000;
    REX_STORE_U32(ctx.r1.u32, 0); // Null frame terminator
    ctx.r13.u32 = 0x82000000;    // Small Data Area base pointer
    
    TekkenLog("[Tekken 6 Native] Transferring control to retail entry point xstart at 0x824BEA50...");
    
#if TEKKEN6_WITH_GAME
    try {
        xstart(ctx, s_guestMemoryBase);
        TekkenLog("[Tekken 6 Native] Retail guest execution completed.");
    } catch (const std::exception& ex) {
        TekkenLog("[Tekken 6 Native] Exception in recompiled guest execution: %s", ex.what());
    } catch (...) {
        TekkenLog("[Tekken 6 Native] Unknown exception caught during guest execution.");
    }
#else
    TekkenLog("[Tekken 6 Native] Notice: TEKKEN6_WITH_GAME is 0. Running in native probe harness mode.");
#endif

    g_tekken_guest_running = false;
    return nullptr;
}

bool Tekken6StartGuestEngine(const char* gameDirectory) {
    std::lock_guard<std::mutex> lock(s_guestEngineMutex);
    if (g_tekken_guest_running) {
        TekkenLog("[Tekken 6] Native retail guest engine is already active.");
        return true;
    }
    
    TekkenLog("[Tekken 6] Booting retail Xbox 360 game on iOS (Root: %s)",
              gameDirectory ? gameDirectory : "Documents/game");
    
    // 1. Mount retail archives and extract retail graphics
    Tekken6MountGameData(gameDirectory);
    
    g_tekken_guest_running = true;
    
    // 2. Launch dedicated guest execution thread with 16MB stack (same as nfsu2-ios)
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setstacksize(&attr, 16u * 1024 * 1024);
    
    pthread_t th;
    int rc = pthread_create(&th, &attr, Tekken6GuestThread, (void*)gameDirectory);
    pthread_attr_destroy(&attr);
    
    if (rc != 0) {
        TekkenLog("[Tekken 6] FATAL: Failed to spawn guest execution thread (rc=%d)", rc);
        g_tekken_guest_running = false;
        return false;
    }
    
    pthread_detach(th);
    TekkenLog("[Tekken 6] Native retail guest booter successfully dispatched.");
    return true;
}

void Tekken6InitHooks() {
    printf("[Tekken 6 iOS] Initializing runtime hooks...\n");
    TekkenLog("[Tekken 6 iOS] Initializing runtime hooks (Resolution: %ux%u, ProMotion: %s)",
              g_tekken_render_width, g_tekken_render_height,
              g_tekken_enable_promotion_120hz ? "120Hz" : "60Hz");
}

void Tekken6SetResolutionPreset(int preset) {
    switch (preset) {
        case 1: // 720p (Recommended for 120Hz ProMotion stability and low thermals)
            g_tekken_render_width = 1280;
            g_tekken_render_height = 720;
            g_tekken_offscreen_width = 1024;
            g_tekken_offscreen_height = 1024;
            break;
        case 2: // 1080p (Crisp high-resolution mode for iPad Pro / iPhone Pro Max)
            g_tekken_render_width = 1920;
            g_tekken_render_height = 1080;
            g_tekken_offscreen_width = 1536;
            g_tekken_offscreen_height = 1536;
            break;
        case 0: // Original Xbox 360 native buffer
        default:
            g_tekken_render_width = 1024;
            g_tekken_render_height = 576;
            g_tekken_offscreen_width = 1024;
            g_tekken_offscreen_height = 1024;
            break;
    }
    printf("[Tekken 6 iOS] Resolution preset updated to %ux%u\n", g_tekken_render_width, g_tekken_render_height);
}

#if __has_include(<rex/ppc.h>)
#include <rex/ppc.h>
#else
namespace rex::ppc {
union Register {
  int8_t s8;
  uint8_t u8;
  int16_t s16;
  uint16_t u16;
  int32_t s32;
  uint32_t u32;
  int64_t s64;
  uint64_t u64;
};
}
#endif

/**
 * Mid-assembly hook at 0x8251C1FC (Tekken6StartupWait).
 * Tekken 6 spins waiting on secondary thread initialization queues.
 * Yielding the thread prevents CPU starvation and watchdog timeouts on Apple Silicon Mach kernels.
 */
void Tekken6StartupWait(rex::ppc::Register& r11) {
    (void)r11;
    std::this_thread::yield();
}

/**
 * Mid-assembly hook at 0x82219DB4 and 0x82219A28 (ApplyTekkenInternalResolution).
 * Intercepts the hardcoded 1024 (r11) and 576 (r10) resolution stores.
 */
void ApplyTekkenInternalResolution(rex::ppc::Register& r11, rex::ppc::Register& r10) {
    if (g_tekken_render_width > 0 && g_tekken_render_height > 0) {
        r11.u64 = static_cast<uint64_t>(g_tekken_render_width);
        r10.u64 = static_cast<uint64_t>(g_tekken_render_height);
    }
}

/**
 * Mid-assembly hook at 0x821AB410 (ApplyTekkenOffscreenResolution).
 * Offscreen target 0x20000004 width & height (r4, r5).
 */
void ApplyTekkenOffscreenResolution(rex::ppc::Register& r3, rex::ppc::Register& r4, rex::ppc::Register& r5) {
    (void)r3;
    if (g_tekken_offscreen_width > 0 && g_tekken_offscreen_height > 0) {
        r4.u64 = static_cast<uint64_t>(g_tekken_offscreen_width);
        r5.u64 = static_cast<uint64_t>(g_tekken_offscreen_height);
    }
}
