#pragma once

#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

// Resolution scale multipliers: 1 = original (1024x576), 2 = 720p/1080p, 3 = high Retina
extern uint32_t g_tekken_render_width;
extern uint32_t g_tekken_render_height;
extern uint32_t g_tekken_offscreen_width;
extern uint32_t g_tekken_offscreen_height;
extern bool g_tekken_enable_promotion_120hz;

void Tekken6InitHooks();

// Mid-assembly hooks defined in tekken6_config.toml
void Tekken6StartupWait(void* context);
void ApplyTekkenInternalResolution(void* context);
void ApplyTekkenOffscreenResolution(void* context);

#ifdef __cplusplus
}
#endif
