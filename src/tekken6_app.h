#pragma once

#include <filesystem>
#include <functional>
#include <optional>
#include <string>
#include <memory>

#if __has_include(<imgui.h>) && __has_include(<rex/rex_app.h>)
#include <rex/cvar.h>
#include <rex/filesystem.h>
#include <rex/rex_app.h>
#include <rex/runtime.h>
#include <rex/system/kernel_state.h>
#include <rex/system/user_module.h>
#include <rex/system/interfaces/graphics.h>
#include <rex/logging.h>
#endif

#if __has_include("recompiled/tekken6_init.h")
#include "recompiled/tekken6_init.h"
#elif __has_include("tekken6_init.h")
#include "tekken6_init.h"
#endif

#include "tekken6_hooks.h"

#if __has_include(<imgui.h>) && __has_include(<rex/rex_app.h>)
class Tekken6App : public rex::ReXApp {
public:
  using rex::ReXApp::ReXApp;

  static std::unique_ptr<rex::ui::WindowedApp> Create(rex::ui::WindowedAppContext& ctx) {
#if TEKKEN6_WITH_GAME
    return std::unique_ptr<Tekken6App>(new Tekken6App(ctx, "tekken6", PPCImageConfig));
#else
    rex::PPCImageInfo dummy{};
    return std::unique_ptr<Tekken6App>(new Tekken6App(ctx, "tekken6", dummy));
#endif
  }

  void OnConfigurePaths(rex::PathConfig& paths) override;
  void OnPreSetup(rex::RuntimeConfig& config) override;
  void OnPreLaunchModule() override;
  void OnPostSetup() override;
  void OnShutdown() override;
};
#endif
