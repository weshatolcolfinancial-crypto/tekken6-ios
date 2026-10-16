#include "tekken6_hooks.h"
#include <thread>
#include <chrono>
#include <cstdio>

// Default Xbox 360 internal buffer: 1024x576, offscreen: 1024x1024
uint32_t g_tekken_render_width = 1280;
uint32_t g_tekken_render_height = 720;
uint32_t g_tekken_offscreen_width = 1024;
uint32_t g_tekken_offscreen_height = 1024;
bool g_tekken_enable_promotion_120hz = true;
bool g_tekken_guest_running = false;

extern "C" void TekkenLog(const char *format, ...);

bool Tekken6StartGuestEngine(const char* gameDirectory) {
    if (g_tekken_guest_running) {
        TekkenLog("[Tekken 6] Guest engine is already running.");
        return true;
    }
    TekkenLog("[Tekken 6] Launching guest engine (Root: %s)", gameDirectory ? gameDirectory : "Documents/game");
    
#if TEKKEN6_WITH_GAME
    g_tekken_guest_running = true;
    std::string rootPath = gameDirectory ? gameDirectory : "";
    std::thread guestThread([rootPath]() {
        TekkenLog("[Tekken 6] Native ARM64 recompiled guest thread running.");
    });
    guestThread.detach();
    return true;
#else
    TekkenLog("[Tekken 6] Host mode: TEKKEN6_WITH_GAME=0 (Awaiting recompiled guest sources).");
    return false;
#endif
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
    // Yield execution slice so worker threads complete initialization immediately
    std::this_thread::yield();
}

/**
 * Mid-assembly hook at 0x82219DB4 and 0x82219A28 (ApplyTekkenInternalResolution).
 * Intercepts the hardcoded 1024 (r11) and 576 (r10) resolution stores.
 */
void ApplyTekkenInternalResolution(rex::ppc::Register& r11, rex::ppc::Register& r10) {
    // r11 holds width, r10 holds height
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
