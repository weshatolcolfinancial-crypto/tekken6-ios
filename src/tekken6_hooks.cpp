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

// ReXGlue PPC context structure layout helper (registers r0..r31)
struct PPCContext {
    uint64_t r[32];
    // Additional state truncated as we only access GPRs in these hooks
};

void Tekken6InitHooks() {
    printf("[Tekken 6 iOS] Initializing runtime hooks...\n");
    printf("[Tekken 6 iOS] Target internal 3D render resolution: %ux%u\n", g_tekken_render_width, g_tekken_render_height);
    printf("[Tekken 6 iOS] ProMotion 120Hz presentation mode: %s\n", g_tekken_enable_promotion_120hz ? "ENABLED" : "LOCKED 60Hz");
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

extern "C" {

/**
 * Mid-assembly hook at 0x8251C1FC (Tekken6StartupWait).
 * Tekken 6 spins waiting on secondary thread initialization queues.
 * Yielding the thread prevents CPU starvation and watchdog timeouts on Apple Silicon Mach kernels.
 */
void Tekken6StartupWait(void* context) {
    // Yield execution slice so worker threads complete initialization immediately
    std::this_thread::yield();
}

/**
 * Mid-assembly hook at 0x82219DB4 and 0x82219A28 (ApplyTekkenInternalResolution).
 * Intercepts the hardcoded 1024 (r11) and 576 (r10) resolution stores.
 */
void ApplyTekkenInternalResolution(void* context) {
    if (!context) return;
    PPCContext* ctx = reinterpret_cast<PPCContext*>(context);
    
    // r11 holds width, r10 holds height
    if (g_tekken_render_width > 0 && g_tekken_render_height > 0) {
        ctx->r[11] = static_cast<uint64_t>(g_tekken_render_width);
        ctx->r[10] = static_cast<uint64_t>(g_tekken_render_height);
    }
}

/**
 * Mid-assembly hook at 0x821AB410 (ApplyTekkenOffscreenResolution).
 * Offscreen target 0x20000004 width & height (r4, r5).
 */
void ApplyTekkenOffscreenResolution(void* context) {
    if (!context) return;
    PPCContext* ctx = reinterpret_cast<PPCContext*>(context);
    
    if (g_tekken_offscreen_width > 0 && g_tekken_offscreen_height > 0) {
        ctx->r[4] = static_cast<uint64_t>(g_tekken_offscreen_width);
        ctx->r[5] = static_cast<uint64_t>(g_tekken_offscreen_height);
    }
}

} // extern "C"
