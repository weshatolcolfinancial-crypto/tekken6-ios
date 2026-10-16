#!/usr/bin/env python3
"""
Translates the Tekken 6 Xbox 360 executable (default.xex) into native C++
using the ReXGlue SDK CLI tool according to tekken6_manifest.toml.
"""

from __future__ import annotations

import argparse
import os
import pathlib
import subprocess
import sys

ROOT = pathlib.Path(__file__).resolve().parents[2]
SDK_DIR = ROOT.parent / "rexglue-sdk-ios"
DEFAULT_XEX = ROOT / "game" / "default.xex"
MANIFEST = ROOT / "tekken6_manifest.toml"


def main() -> int:
    parser = argparse.ArgumentParser(description="Generate Tekken 6 C++ code for iOS")
    parser.add_argument("--xex", type=pathlib.Path, default=DEFAULT_XEX, help="Path to default.xex")
    parser.add_argument("--sdk", type=pathlib.Path, default=SDK_DIR, help="ReXGlue SDK directory")
    args = parser.parse_args()

    xex_path = args.xex.resolve()
    if not xex_path.exists():
        print(f"Error: Executable not found at {xex_path}")
        print("Please place your retail Tekken 6 default.xex in 'game/default.xex'.")
        return 1

    sdk_dir = args.sdk.resolve()
    
    # Locate rexglue executable
    rexglue_bin = None
    for cand in [
        sdk_dir / "out" / "rexglue",
        sdk_dir / "build" / "rexglue",
        sdk_dir / "out" / "linux-amd64" / "rexglue",
        sdk_dir / "out" / "mac-arm64" / "rexglue",
        sdk_dir / "out" / "windows-amd64" / "rexglue.exe"
    ]:
        if cand.exists():
            rexglue_bin = cand
            break

    if not rexglue_bin:
        print("ReXGlue host binary not found. Building host rexglue tool...")
        build_dir = sdk_dir / "build-host"
        subprocess.run(["cmake", "-S", str(sdk_dir), "-B", str(build_dir), "-DCMAKE_BUILD_TYPE=Release"], check=True)
        subprocess.run(["cmake", "--build", str(build_dir), "--target", "rexglue"], check=True)
        rexglue_bin = build_dir / "rexglue"

    print(f"Generating C++ source code using {rexglue_bin}...")
    subprocess.run([str(rexglue_bin), "codegen", str(MANIFEST)], cwd=ROOT, check=True)
    
    print("\n[SUCCESS] Code generation complete! Sources written to ios/generated/default/")
    return 0


if __name__ == "__main__":
    sys.exit(main())
