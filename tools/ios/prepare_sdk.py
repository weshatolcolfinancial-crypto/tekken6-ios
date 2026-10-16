#!/usr/bin/env python3
"""
Prepares the ReXGlue SDK tree for building the Tekken 6 iOS port.
Clones ReXGlue SDK v0.10.0, downloads MoltenVK v1.4.1 for iOS, and applies iOS runtime/CMake patches.
"""

from __future__ import annotations

import argparse
import os
import pathlib
import re
import subprocess
import sys
import tarfile
import urllib.request

ROOT = pathlib.Path(__file__).resolve().parents[2]
DEFAULT_SDK_DIR = ROOT.parent / "rexglue-sdk-ios"

MOLTENVK_VERSION = "v1.4.1"
MOLTENVK_URL = (
    f"https://github.com/KhronosGroup/MoltenVK/releases/download/"
    f"{MOLTENVK_VERSION}/MoltenVK-ios.tar"
)


def run_cmd(cmd: list[str], cwd: pathlib.Path | None = None) -> None:
    print(f"==> Running: {' '.join(str(c) for c in cmd)}")
    subprocess.run(cmd, cwd=cwd, check=True)


def clone_sdk(sdk_dir: pathlib.Path) -> None:
    if (sdk_dir / "CMakeLists.txt").exists():
        print(f"[OK] SDK already exists at {sdk_dir}")
        return

    print(f"Cloning ReXGlue SDK into {sdk_dir}...")
    run_cmd([
        "git", "clone", "--recurse-submodules", "--depth", "1",
        "-b", "v0.10.0",
        "https://github.com/rexglue/rexglue-sdk.git",
        str(sdk_dir)
    ])


def download_moltenvk(sdk_dir: pathlib.Path) -> None:
    mvk_dir = sdk_dir / ".tekken6-ios" / "MoltenVK"
    marker = mvk_dir / f"{MOLTENVK_VERSION}.ready"
    if marker.exists():
        print(f"[OK] MoltenVK {MOLTENVK_VERSION} already installed.")
        return

    mvk_dir.mkdir(parents=True, exist_ok=True)
    tar_path = mvk_dir / "MoltenVK-ios.tar"
    print(f"Downloading MoltenVK from {MOLTENVK_URL}...")
    urllib.request.urlretrieve(MOLTENVK_URL, tar_path)

    print("Extracting MoltenVK...")
    with tarfile.open(tar_path, "r") as tar:
        tar.extractall(mvk_dir)

    tar_path.unlink()
    
    # Locate MoltenVK.framework inside extracted package and organize for CMake
    framework_candidates = list(mvk_dir.rglob("MoltenVK.framework"))
    for fw in framework_candidates:
        if "ios" in str(fw).lower() or "iphone" in str(fw).lower():
            target_fw_dir = mvk_dir / "ios-arm64"
            target_fw_dir.mkdir(exist_ok=True)
            dst = target_fw_dir / "MoltenVK.framework"
            if not dst.exists():
                import shutil
                shutil.copytree(fw, dst)
            break

    marker.write_text(f"{MOLTENVK_VERSION}\n")
    print(f"[OK] MoltenVK ready in {mvk_dir}")


def apply_ios_patches(sdk_dir: pathlib.Path) -> None:
    print("[Tekken 6 iOS] Applying iOS patches to ReXGlue SDK...")

    # 1. Patch platform.h
    platform_h = sdk_dir / "include" / "rex" / "platform.h"
    if platform_h.exists():
        content = platform_h.read_text(encoding="utf-8")
        if "REX_PLATFORM_IOS" not in content:
            ios_def = (
                "\n#if defined(__APPLE__) && defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE\n"
                "#define REX_PLATFORM_IOS 1\n"
                "#endif\n"
            )
            platform_h.write_text(content + ios_def, encoding="utf-8")
            print("[OK] Applied platform.h patch.")

    # 2. Patch thirdparty/CMakeLists.txt: Do NOT build desktop vulkan-loader / MoltenVK on iOS
    tp_cmake = sdk_dir / "thirdparty" / "CMakeLists.txt"
    if tp_cmake.exists():
        content = tp_cmake.read_text(encoding="utf-8")
        
        # Replace unconditional vulkan-loader / moltenvk with NOT IOS check
        content = re.sub(
            r'add_subdirectory\s*\(\s*vulkan-loader\s*\)',
            'if(NOT IOS)\n    add_subdirectory(vulkan-loader)\nendif()',
            content
        )
        content = re.sub(
            r'add_subdirectory\s*\(\s*moltenvk\s*\)',
            'if(NOT IOS)\n    add_subdirectory(moltenvk)\nendif()',
            content
        )

        # Guard set_target_properties or target_* on vulkan/moltenvk if target does not exist or on iOS
        content = re.sub(
            r'(set_target_properties\s*\(\s*vulkan\b[\s\S]*?\))',
            r'if(TARGET vulkan AND NOT IOS)\n\1\nendif()',
            content
        )
        content = re.sub(
            r'(set_target_properties\s*\(\s*moltenvk\b[\s\S]*?\))',
            r'if(TARGET moltenvk AND NOT IOS)\n\1\nendif()',
            content
        )

        # On iOS, define interface stub targets for vulkan and Vulkan::Loader so linking succeeds
        ios_stubs = (
            "\nif(IOS)\n"
            "    if(NOT TARGET vulkan)\n"
            "        add_library(vulkan INTERFACE)\n"
            "    endif()\n"
            "    if(NOT TARGET Vulkan::Loader)\n"
            "        add_library(Vulkan::Loader INTERFACE)\n"
            "    endif()\n"
            "endif()\n"
        )
        if "add_library(Vulkan::Loader INTERFACE)" not in content:
            content = ios_stubs + content

        tp_cmake.write_text(content, encoding="utf-8")
        print("[OK] Patched thirdparty/CMakeLists.txt for iOS Vulkan targets.")

    # 3. Patch thirdparty/vulkan-loader: On iOS, MoltenVK framework is used directly, not desktop vulkan-loader
    for vk_cmake in [
        sdk_dir / "thirdparty" / "vulkan-loader" / "CMakeLists.txt",
        sdk_dir / "thirdparty" / "vulkan-loader" / "loader" / "CMakeLists.txt"
    ]:
        if vk_cmake.exists():
            content = vk_cmake.read_text(encoding="utf-8")
            if "if(IOS)" not in content:
                content = "if(IOS)\n    return()\nendif()\n\n" + content
                vk_cmake.write_text(content, encoding="utf-8")
                print(f"[OK] Added iOS guard to {vk_cmake.name}")

    # 4. Patch root CMakeLists.txt to define REX_PLATFORM_IOS
    root_cmake = sdk_dir / "CMakeLists.txt"
    if root_cmake.exists():
        content = root_cmake.read_text(encoding="utf-8")
        if "REX_PLATFORM_IOS" not in content:
            insertion = (
                "\nif(IOS)\n"
                "    add_compile_definitions(REX_PLATFORM_IOS=1)\n"
                "endif()\n"
            )
            content = content + insertion
            root_cmake.write_text(content, encoding="utf-8")
            print("[OK] Added REX_PLATFORM_IOS definition to root CMakeLists.txt.")


def main() -> int:
    parser = argparse.ArgumentParser(description="Prepare ReXGlue SDK for iOS")
    parser.add_argument("--sdk", type=pathlib.Path, default=DEFAULT_SDK_DIR, help="Target SDK directory")
    args = parser.parse_args()

    sdk_dir = args.sdk.resolve()
    print(f"[Tekken 6 iOS] Preparing SDK in: {sdk_dir}")
    
    clone_sdk(sdk_dir)
    download_moltenvk(sdk_dir)
    apply_ios_patches(sdk_dir)

    print("\n[SUCCESS] ReXGlue SDK for iOS is completely configured and patched!")
    return 0


if __name__ == "__main__":
    sys.exit(main())
