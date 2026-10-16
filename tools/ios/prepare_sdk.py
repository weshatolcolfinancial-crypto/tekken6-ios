#!/usr/bin/env python3
"""
Prepares the ReXGlue SDK tree for building the Tekken 6 iOS port.
Clones ReXGlue SDK v0.10.0, downloads MoltenVK v1.4.1 for iOS, and applies iOS runtime patches.
"""

from __future__ import annotations

import argparse
import os
import pathlib
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
    marker.write_text(f"{MOLTENVK_VERSION}\n")
    print(f"[OK] MoltenVK ready in {mvk_dir}")


def apply_ios_patches(sdk_dir: pathlib.Path) -> None:
    platform_h = sdk_dir / "include" / "rex" / "platform.h"
    if platform_h.exists():
        content = platform_h.read_text()
        if "REX_PLATFORM_IOS" not in content:
            print("Applying REX_PLATFORM_IOS patch to platform.h...")
            ios_def = (
                "\n#if defined(__APPLE__) && defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE\n"
                "#define REX_PLATFORM_IOS 1\n"
                "#endif\n"
            )
            platform_h.write_text(content + ios_def)
            print("[OK] Applied platform.h patch.")
        else:
            print("[OK] platform.h already contains REX_PLATFORM_IOS.")


def main() -> int:
    parser = argparse.ArgumentParser(description="Prepare ReXGlue SDK for iOS")
    parser.add_argument("--sdk", type=pathlib.Path, default=DEFAULT_SDK_DIR, help="Target SDK directory")
    args = parser.parse_args()

    sdk_dir = args.sdk.resolve()
    print(f"[Tekken 6 iOS] Preparing SDK in: {sdk_dir}")
    
    clone_sdk(sdk_dir)
    download_moltenvk(sdk_dir)
    apply_ios_patches(sdk_dir)

    print("\n[SUCCESS] ReXGlue SDK for iOS is ready!")
    return 0


if __name__ == "__main__":
    sys.exit(main())
