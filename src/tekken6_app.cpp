#include "tekken6_app.h"
#include <cstdio>
#include <cstdlib>
#include <filesystem>

#if __has_include(<rex/rex_app.h>)

void Tekken6App::OnConfigurePaths(rex::PathConfig& paths) {
    rex::ReXApp::OnConfigurePaths(paths);
    
    // Configure retail game directory (Documents/game on iOS)
    const char* home = getenv("HOME");
    std::filesystem::path gameRoot;
    if (home) {
        gameRoot = std::filesystem::path(home) / "Documents" / "game";
    } else {
        gameRoot = "game";
    }
    
    paths.game_data_root = gameRoot;
    TekkenLog("[Tekken 6 App] Configured retail game data root: %s", paths.game_data_root.string().c_str());
}

void Tekken6App::OnPreSetup(rex::RuntimeConfig& config) {
    rex::ReXApp::OnPreSetup(config);
    
    // Initialize Tekken 6 resolution, ProMotion 120Hz, and mid-assembly hooks
    Tekken6InitHooks();
    
    // Configure retail title ID and GPU plugin
    config.title_id = 0x4E4D07FC; // Tekken 6 Retail Title ID
    config.gpu_plugin = "xenos";
    
    TekkenLog("[Tekken 6 App] OnPreSetup complete. Title ID: 0x%08X", config.title_id);
}

void Tekken6App::OnPreLaunchModule() {
    rex::ReXApp::OnPreLaunchModule();
    
    // Mount retail archives (DINF_300.BIN & DATA301-320)
    const char* home = getenv("HOME");
    std::string gameDir = home ? (std::string(home) + "/Documents/game") : "game";
    Tekken6MountGameData(gameDir.c_str());
    
    TekkenLog("[Tekken 6 App] OnPreLaunchModule complete. Mounted %u archives, %u assets.",
              Tekken6GetMountedArchiveCount(), Tekken6GetTotalAssetCount());
}

void Tekken6App::OnPostSetup() {
    rex::ReXApp::OnPostSetup();
    TekkenLog("[Tekken 6 App] OnPostSetup complete. Retail Xbox 360 engine initialized.");
}

void Tekken6App::OnShutdown() {
    TekkenLog("[Tekken 6 App] OnShutdown initiated.");
    rex::ReXApp::OnShutdown();
}

#if defined(REX_DEFINE_APP)
REX_DEFINE_APP(tekken6, Tekken6App::Create)
#endif

#else

// Standalone fallback initialization
extern "C" void Tekken6AppInit() {
    Tekken6InitHooks();
}

#endif
