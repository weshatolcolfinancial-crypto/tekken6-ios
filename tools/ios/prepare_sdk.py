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
    print(f"Discovered MoltenVK framework candidates: {[str(c) for c in framework_candidates]}")
    for fw in framework_candidates:
        if "ios" in str(fw).lower() or "iphone" in str(fw).lower():
            target_fw_dir = mvk_dir / "ios-arm64"
            target_fw_dir.mkdir(exist_ok=True)
            dst = target_fw_dir / "MoltenVK.framework"
            if not dst.exists():
                import shutil
                shutil.copytree(fw, dst)
            print(f"[OK] Organized iOS MoltenVK framework at: {dst}")
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
            "        add_library(vulkan_loader_stub INTERFACE)\n"
            "        add_library(Vulkan::Loader ALIAS vulkan_loader_stub)\n"
            "    endif()\n"
            "endif()\n"
        )
        if "vulkan_loader_stub" not in content:
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

    # 4. Patch root CMakeLists.txt to define REX_PLATFORM_IOS at the top
    root_cmake = sdk_dir / "CMakeLists.txt"
    if root_cmake.exists():
        content = root_cmake.read_text(encoding="utf-8")
        if "add_compile_definitions(REX_PLATFORM_IOS=1)" not in content:
            insertion = (
                "if(IOS)\n"
                "    add_compile_definitions(REX_PLATFORM_IOS=1)\n"
                "endif()\n\n"
            )
            content = insertion + content
            root_cmake.write_text(content, encoding="utf-8")
            print("[OK] Added REX_PLATFORM_IOS definition to top of root CMakeLists.txt.")

    # 5. Patch memory_posix.cpp: Use vm_region_64 and Mach memory entries on iOS
    mem_cpp = sdk_dir / "src" / "core" / "memory_posix.cpp"
    if mem_cpp.exists():
        content = mem_cpp.read_text(encoding="utf-8")
        if "mach_vm_region" not in content or "vm_region_64" not in content:
            # Replace <mach/mach_vm.h> with iOS vm_region_64 wrapper
            content = re.sub(
                r'#include\s*<mach/mach_vm\.h>',
                '#include <TargetConditionals.h>\n'
                '#if (defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE) || defined(REX_PLATFORM_IOS) || defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__)\n'
                '#include <mach/vm_map.h>\n'
                'static inline kern_return_t mach_vm_region(vm_map_t task, mach_vm_address_t* address, '
                'mach_vm_size_t* size, vm_region_flavor_t flavor, vm_region_info_t info, '
                'mach_msg_type_number_t* info_count, mach_port_t* object_name) {\n'
                '  return vm_region_64(task, reinterpret_cast<vm_address_t*>(address), '
                'reinterpret_cast<vm_size_t*>(size), flavor, info, info_count, object_name);\n}\n'
                '#else\n#include <mach/mach_vm.h>\n#endif',
                content
            )

            # Patch CreateFileMappingHandle for Mach memory entry
            create_code = (
                'FileMappingHandle CreateFileMappingHandle(const std::filesystem::path& path, size_t length,\n'
                '                                          PageAccess access, bool commit) {\n'
                '#if (defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE) || defined(REX_PLATFORM_IOS) || defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__)\n'
                '  (void)path; (void)access; (void)commit;\n'
                '  memory_object_size_t entry_size = length;\n'
                '  mach_port_t entry = MACH_PORT_NULL;\n'
                '  const kern_return_t kr = mach_make_memory_entry_64(\n'
                '      mach_task_self(), &entry_size, 0,\n'
                '      MAP_MEM_NAMED_CREATE | VM_PROT_READ | VM_PROT_WRITE, &entry, MACH_PORT_NULL);\n'
                '  if (kr != KERN_SUCCESS || entry_size < length) {\n'
                '    if (entry != MACH_PORT_NULL) mach_port_deallocate(mach_task_self(), entry);\n'
                '    return kFileMappingHandleInvalid;\n'
                '  }\n'
                '  return static_cast<FileMappingHandle>(entry);\n'
                '#endif\n'
            )
            content = re.sub(
                r'FileMappingHandle CreateFileMappingHandle\([^\)]+\)\s*\{',
                create_code,
                content
            )

            # Patch CloseFileMappingHandle
            close_code = (
                'void CloseFileMappingHandle(FileMappingHandle handle, const std::filesystem::path& path) {\n'
                '#if (defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE) || defined(REX_PLATFORM_IOS) || defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__)\n'
                '  (void)path;\n'
                '  mach_port_deallocate(mach_task_self(), static_cast<mach_port_t>(handle));\n'
                '  return;\n'
                '#endif\n'
            )
            content = re.sub(
                r'void CloseFileMappingHandle\([^\)]+\)\s*\{',
                close_code,
                content
            )

            # Patch MapFileView
            map_code = (
                '#if (defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE) || defined(REX_PLATFORM_IOS) || defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__)\n'
                '  {\n'
                '    vm_address_t address = reinterpret_cast<vm_address_t>(base_address);\n'
                '    const kern_return_t kr = vm_map(\n'
                '        mach_task_self(), &address, length, 0,\n'
                '        base_address ? (VM_FLAGS_FIXED | VM_FLAGS_OVERWRITE) : VM_FLAGS_ANYWHERE,\n'
                '        static_cast<mem_entry_name_port_t>(handle), file_offset, FALSE,\n'
                '        static_cast<vm_prot_t>(ToPosixProtectFlags(access)),\n'
                '        VM_PROT_READ | VM_PROT_WRITE, VM_INHERIT_NONE);\n'
                '    if (kr != KERN_SUCCESS) return nullptr;\n'
                '    if (base_address && reinterpret_cast<void*>(address) != base_address) {\n'
                '      munmap(reinterpret_cast<void*>(address), length);\n'
                '      return nullptr;\n'
                '    }\n'
                '    return reinterpret_cast<void*>(address);\n'
                '  }\n'
                '#endif\n\n'
                '  int flags = MAP_SHARED;'
            )
            content = re.sub(
                r'int flags = MAP_SHARED;',
                map_code,
                content,
                count=1
            )

            mem_cpp.write_text(content, encoding="utf-8")
            print("[OK] Patched memory_posix.cpp for iOS Mach VM.")

    # 6. Patch xmemory.cpp
    xmem_cpp = sdk_dir / "src" / "system" / "xmemory.cpp"
    if xmem_cpp.exists():
        content = xmem_cpp.read_text(encoding="utf-8")
        if "rex::memory::MapFileView(mapping_" not in content:
            mmap_call = (
                '#if REX_PLATFORM_IOS\n'
                '    void* result = rex::memory::MapFileView(mapping_, target_address, view_size,\n'
                '                                            rex::memory::PageAccess::kReadWrite, file_offset);\n'
                '    if (!result) result = MAP_FAILED;\n'
                '#else\n'
                '    void* result = mmap(target_address, view_size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_FIXED,\n'
                '                        mapping_, file_offset);\n'
                '#endif'
            )
            content = re.sub(
                r'void\*\s+result\s*=\s*mmap\(target_address,\s*view_size,\s*PROT_READ\s*\|\s*PROT_WRITE,\s*MAP_SHARED\s*\|\s*MAP_FIXED,\s*mapping_,\s*file_offset\);',
                mmap_call,
                content
            )
            xmem_cpp.write_text(content, encoding="utf-8")
            print("[OK] Patched xmemory.cpp for iOS MapFileView.")

    # 7. Patch filesystem_posix.cpp for LiveContainer dlfcn path resolution
    fs_cpp = sdk_dir / "src" / "core" / "filesystem_posix.cpp"
    if fs_cpp.exists():
        content = fs_cpp.read_text(encoding="utf-8")
        if "#include <dlfcn.h>" not in content:
            content = "#include <dlfcn.h>\n" + content
        if "dladdr" not in content:
            dladdr_hook = (
                'std::filesystem::path GetExecutableFolder() {\n'
                '#if REX_PLATFORM_IOS\n'
                '  Dl_info info{};\n'
                '  if (dladdr(reinterpret_cast<const void*>(&GetExecutableFolder), &info) && info.dli_fname) {\n'
                '    return std::filesystem::path(info.dli_fname).parent_path();\n'
                '  }\n'
                '#endif\n'
            )
            content = re.sub(
                r'std::filesystem::path GetExecutableFolder\(\)\s*\{',
                dladdr_hook,
                content
            )
            fs_cpp.write_text(content, encoding="utf-8")
            print("[OK] Patched filesystem_posix.cpp for LiveContainer Frameworks/ dladdr path.")


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
