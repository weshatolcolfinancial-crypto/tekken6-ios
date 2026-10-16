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
- **Fighting Game Touch Overlay:** Purpose-built touch controls with an 8-way directional D-pad, the classic Tekken 4-button attack diamond (LP, RP, LK, RK), and instant one-tap macro triggers (1+2, 3+4, 1+3, 2+4).
- **Physical Gamepad Support:** Native `GameController.framework` integration for PlayStation DualSense / DualShock 4, Xbox Wireless Controllers, and mobile grips (Backbone One, Razer Kishi).

---

## 🎮 Controls

### Touch Layout
| Button | Tekken Notation | Xbox 360 Equivalent | Action |
|:---|:---|:---|:---|
| **◀ ▲ ▼ ▶** | Directional / Pad | D-Pad / Left Thumbstick | Movement, Crouch, Sidestep, Jump |
| **LP (1)** | Left Punch | **X** | High punch, combo starter |
| **RP (2)** | Right Punch | **Y** | High punch, launcher |
| **LK (3)** | Left Kick | **A** | Low / mid kick |
| **RK (4)** | Right Kick | **B** | High / launcher kick |
| **1+2** | LP + RP | **LB** (Left Bumper) | Power crush / special moves |
| **3+4** | LK + RK | **LT** (Left Trigger) | Stance / jumping attacks |
| **1+3** | Throw 1 | **RT** (Right Trigger) | Left grab / throw |
| **2+4** | Throw 2 | **RB** (Right Bumper) | Right grab / throw |
| **START** | Start | Start | Pause / Menu |
| **SELECT** | Back | Back | Practice Reset |

> *Touch controls automatically hide when a physical Bluetooth controller is connected.*

---

## 📱 ProMotion 120Hz & Improvements

1. **Input Latency Reduction:**
   By configuring `CADisableMinimumFrameDurationOnPhone` in `Info.plist` and pairing `CADisplayLink` with `preferredFrameRateRange = (60, 120, 120)`, presentation synchronization is halved to 8.33ms intervals, significantly reducing touch-to-screen response time.
2. **Mach Thread Starvation Fix:**
   Tekken 6 contains a background thread synchronization loop (`Tekken6StartupWait` at `0x8251C1FC`). Our custom midasm hook inserts `std::this_thread::yield()`, eliminating CPU starvation and startup freezes on Apple Silicon Mach kernels.
3. **Internal Resolution Scaling:**
   Original Xbox 360 internal framebuffer was 1024x576. Our runtime hooks allow scaling up to 720p or 1080p for crisp character rendering on high-DPI Super Retina XDR displays.

---

## 🛠️ Requirements & Setup

### Game Requirements
You need your own legally dumped copy of the **retail Xbox 360 Tekken 6 ISO**:
- **Scene Release:** `Tekken 6 (World) (En,Ja,Fr,De,Es,It,Ko,Ru)`
- **Title ID:** `4E4D07E6`

Extract `default.xex` and place it in the `game/` folder.

---

## 🚀 Building the Project

### Method A: Automated Cloud Build via GitHub Actions (Recommended)
1. Push this repository to your GitHub account.
2. Navigate to the **Actions** tab -> **Build Tekken 6 iOS IPA**.
3. (Optional) Provide a direct download URL for your dumped `default.xex`.
4. Click **Run workflow**.
5. Once completed, download `Tekken6.ipa` from the workflow summary or Releases page.

### Method B: Local Build (macOS with Xcode 16+)
```bash
# 1. Prepare ReXGlue SDK and MoltenVK for iOS
python3 tools/ios/prepare_sdk.py

# 2. Place your default.xex in game/default.xex and generate guest code
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
2. Transfer `Tekken6.ipa` to your device and install it through your chosen sideloading app.
3. Open the **Files** app on iOS, find the **Tekken 6** folder, and place your extracted game assets (`game/` or game ISO).
4. Launch the app and enjoy fighting at 60 FPS / 120 Hz!
