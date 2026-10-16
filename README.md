# Tekken 6 Recompiled for iOS

<div align="center">

**The Xbox 360 retail release of *Tekken 6* (World Multi-Language: En, Ja, Fr, De, Es, It, Ko, Ru), statically recompiled and running natively on iPhone and iPad with ProMotion 120Hz support.**

![Platform](https://img.shields.io/badge/Platform-iOS%20%7C%20iPadOS%2016%2B-black?logo=apple&logoColor=white)
![Architecture](https://img.shields.io/badge/Arch-ARM64%20(Apple%20Silicon)-orange)
![Graphics](https://img.shields.io/badge/Graphics-Metal%20%2F%20MoltenVK-blue?logo=vulkan)
![Refresh Rate](https://img.shields.io/badge/Display-ProMotion%20120Hz%20%7C%2060Hz-brightgreen)

</div>

---

## ⚡ What is This?

This is **not an emulator**. Tekken 6's Xbox 360 PowerPC bytecode is statically translated ahead-of-time (AOT) into native C++ using the **ReXGlue SDK** and compiled directly into Apple Silicon ARM64 machine code.

- **Graphics:** The Xbox 360 Xenos GPU commands are translated into Vulkan and rendered natively through Apple's **Metal** API using **MoltenVK**.
- **ProMotion 120Hz:** Full support for Apple ProMotion displays (iPhone 13 Pro/14 Pro/15 Pro/16 Pro and iPad Pro) enabled via `CADisableMinimumFrameDurationOnPhone` and dynamic `CAFrameRateRange`.
- **Overhauled Fighting Controls:** True Namco Noir / Vewlix arcade 2x2 matrix with an 18° thumb sweep arc, rapid macro triggers (1+2, 3+4, 1+3, 2+4, RAGE), and an 8-way illuminated D-Pad.
- **Physical Gamepad Support:** Native `GameController.framework` integration for PlayStation DualSense / DualShock 4, Xbox Wireless Controllers, and mobile grips (Backbone One, Razer Kishi).
- **Persistent File & Live On-Screen Logging:** Real-time log capture streaming to `~/Documents/tekken6.log`, crash capture to `~/Documents/crash.log`, and an on-screen live terminal log drawer accessed via `[LOGS]`.

---

## 🎮 Overhauled Controls Layout

### Authentic Arcade 2x2 Matrix (18° Ergonomic Thumb Arc)
On arcade fightsticks (Namco Noir cab layout), Tekken's punch buttons (`LP` and `RP`) sit on the top row, and kick buttons (`LK` and `RK`) sit on the bottom row, slanted along the thumb's natural articulation arc:

```
           [ LP (1) ]    [ RP (2) ]
              (X)           (Y)
          [ LK (3) ]    [ RK (4) ]
              (A)           (B)
```

| Button | Tekken Notation | Xbox 360 | Theme Color | Action |
|:---|:---|:---|:---|:---|
| **LP (1)** | Left Punch | **X** | Cyan (`#00E5FF`) | High punch, jabs, string starter |
| **RP (2)** | Right Punch | **Y** | Gold (`#FFD600`) | High punch, launcher |
| **LK (3)** | Left Kick | **A** | Emerald (`#00E676`) | Low / mid kick |
| **RK (4)** | Right Kick | **B** | Crimson (`#FF1744`) | High / launcher kick |
| **1+2** | LP + RP | **LB** | Violet | Power crush / special moves |
| **3+4** | LK + RK | **LT** | Violet | Stance / jumping attacks |
| **1+3** | Throw 1 | **RT** | Violet | Left throw |
| **2+4** | Throw 2 | **RB** | Violet | Right throw |
| **RAGE** | 1+2+3+4 | Macro | Orange/Red | Rage Arts / Rage Drive |
| **◀ ▲ ▼ ▶** | 8-Way Stick | D-Pad | Dynamic Glow | Directional movement with diagonal illumination |

### System Top Bar Controls
- **`120Hz` / `60Hz`:** Toggle ProMotion refresh rate on the fly.
- **`16:9` / `FULL`:** Switch between pixel-perfect 16:9 pillarbox and borderless 19.5:9 ultrawide.
- **`SIZE`:** Instant layout size cycling (`NORMAL` -> `LARGE` -> `SMALL`).
- **`OPACITY`:** Dynamic touch button transparency (`100%` -> `75%` -> `50%` -> `25%`).
- **`[LOGS]`:** Slides open the on-screen live terminal drawer with one tap.
- **`HIDE` / `SHOW`:** Toggles on-screen controls visibility (also auto-hides when a physical gamepad connects).

---

## 📋 Diagnostics & Log Subsystem

### 1. Persistent File Logs (In iOS Files App)
All startup traces, file scans, Metal initialization steps, and guest runtime logs are written in real-time to:
- **`On My iPhone/iPad > Tekken 6 > tekken6.log`**: Complete execution log.
- **`On My iPhone/iPad > Tekken 6 > crash.log`**: Uncaught exceptions and Mach signal crash traces.

### 2. On-Screen Live Log Terminal
Tap the cyan **`[LOGS]`** button in the top bar anytime to open the terminal overlay:
- Auto-scrolls with live engine events.
- **`COPY`**: Copies all logs directly to the iOS clipboard.
- **`RELOAD`**: Refreshes logs from disk.
- **`CLEAR`**: Resets log file and buffer.

---

## 🛠️ Game Setup & Running Modes

### 1. Where to Place Game Files
1. Open the iOS **Files** app on your device.
2. Go to: **On My iPhone/iPad > Tekken 6 > game**
3. Place your retail Tekken 6 files there:
   - `default.xex` (Title ID: `4E4D07E6`)
   - Asset directories (`sound/`, `ui/`, `stage/`, `motion/`, `character/`)
   - Or your dumped `.iso` image.
4. Open the Tekken 6 app; it will automatically scan, verify, and display the Combat Dashboard!

### 2. Running Modes
- **Host Diagnostic & Viewport Test Mode (`TEKKEN6_WITH_GAME=0`):**
  If built without embedded guest code, the app verifies all game assets, activates the Metal presentation pipeline, displays live 120 FPS / frame time pacing, and allows full interactive testing of the overhauled touch controls and physical controllers.
- **Full AOT Native Gameplay Mode (`TEKKEN6_WITH_GAME=1`):**
  To compile the complete game into the IPA, trigger the GitHub Actions workflow **Build Tekken 6 iOS IPA** and supply your direct download link for `default.xex` in the `xex_url` field. The cloud builder translates the Xenon PowerPC binary into native ARM64 C++ code and packages the complete standalone IPA!

---

## 🚀 Building the Project

### Method A: Automated Cloud Build via GitHub Actions (Recommended)
1. Fork or push this repository to GitHub.
2. Go to **Actions** -> **Build Tekken 6 iOS IPA** -> **Run workflow**.
3. (Optional) In the `xex_url` field, paste a direct download URL for your dumped `default.xex`.
4. Click **Run workflow**. Once finished, download the `Tekken6-iOS-IPA` artifact.

### Method B: Local Build (macOS with Xcode 16+)
```bash
# 1. Prepare ReXGlue SDK and MoltenVK for iOS
python3 tools/ios/prepare_sdk.py

# 2. Translate default.xex into native C++
python3 tools/ios/generate_code.py

# 3. Configure and build with CMake
cd ios
cmake --preset ios
cmake --build --preset ios --target ipa
# Output: ios/build-ios/Tekken6.ipa
```

---

## 📦 Sideloading onto iPhone or iPad

1. Install **LiveContainer**, **SideStore**, or **TrollStore** on your iOS device.
2. Transfer `Tekken6.ipa` to your device and install it through your sideloading tool.
3. Open the **Files** app on iOS, navigate to `Tekken 6 > game`, and copy your game files.
4. Launch Tekken 6 and enjoy the overhauled arcade controls and 120Hz ProMotion responsiveness!
