#pragma once

#include <cstdint>
#include <cstddef>

#ifndef TEKKEN_INPUT_BUTTONS_DEFINED
#define TEKKEN_INPUT_BUTTONS_DEFINED
// Xbox 360 gamepad button bitmask matching ReXGlue input state
enum TekkenInputButtons : uint32_t {
    BTN_DPAD_UP        = 1 << 0,
    BTN_DPAD_DOWN      = 1 << 1,
    BTN_DPAD_LEFT      = 1 << 2,
    BTN_DPAD_RIGHT     = 1 << 3,
    BTN_START          = 1 << 4,
    BTN_BACK           = 1 << 5,
    BTN_LEFT_THUMB     = 1 << 6,
    BTN_RIGHT_THUMB    = 1 << 7,
    BTN_LEFT_SHOULDER  = 1 << 8,  // LB (1+2 Macro)
    BTN_RIGHT_SHOULDER = 1 << 9,  // RB (2+4 Macro)
    BTN_A              = 1 << 12, // LK (3 - Left Kick)
    BTN_B              = 1 << 13, // RK (4 - Right Kick)
    BTN_X              = 1 << 14, // LP (1 - Left Punch)
    BTN_Y              = 1 << 15, // RP (2 - Right Punch)
    BTN_LEFT_TRIGGER   = 1 << 16, // LT (3+4 Macro)
    BTN_RIGHT_TRIGGER  = 1 << 17, // RT (1+3 Macro)
    BTN_RAGE_MACRO     = BTN_LEFT_SHOULDER | BTN_RIGHT_SHOULDER | BTN_LEFT_TRIGGER | BTN_RIGHT_TRIGGER, // 1+2+3+4
};
#endif

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

// Game Asset Extraction and Mounting Subsystem
bool Tekken6MountGameData(const char* gameDirectory);
const uint8_t* Tekken6GetNxeartSplash(size_t* outLength);
const uint8_t* Tekken6GetNxeartBanner(size_t* outLength);
uint32_t Tekken6GetMountedArchiveCount();
uint32_t Tekken6GetTotalAssetCount();

// Metal Presentation Pipeline Bridge
bool Tekken6GetActiveFrame(void** outPixels, uint32_t* outWidth, uint32_t* outHeight, uint32_t* outStride, uint32_t* outFrameIndex);
void Tekken6SetActiveFrame(const void* pixels, uint32_t width, uint32_t height, uint32_t stride);

// Input bridge for touch overlay and physical gamepads
void Tekken6UpdateInput(uint32_t buttons, float stickX, float stickY);

#ifdef __cplusplus
}
#endif
