#pragma once

#include <cstdint>

#ifdef __cplusplus
namespace rex::ppc {
union Register;
}

// Mid-assembly hooks called by recompiled PPC guest code
void Tekken6StartupWait(rex::ppc::Register& r11);
void ApplyTekkenInternalResolution(rex::ppc::Register& r11, rex::ppc::Register& r10);
void ApplyTekkenOffscreenResolution(rex::ppc::Register& r3, rex::ppc::Register& r4, rex::ppc::Register& r5);

extern "C" {
#endif

// Resolution scale multipliers: 1 = original (1024x576), 2 = 720p/1080p, 3 = high Retina
extern uint32_t g_tekken_render_width;
extern uint32_t g_tekken_render_height;
extern uint32_t g_tekken_offscreen_width;
extern uint32_t g_tekken_offscreen_height;
extern bool g_tekken_enable_promotion_120hz;
extern bool g_tekken_guest_running;

void Tekken6InitHooks();
void Tekken6SetResolutionPreset(int preset);
bool Tekken6StartGuestEngine(const char* gameDirectory);

#ifdef __cplusplus
}
#endif
