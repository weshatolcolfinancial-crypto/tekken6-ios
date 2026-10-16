# =============================================================================
#  Tekken 6 Recompiled - iOS Native App (arm64, iOS 16.0+)
#  Supports ProMotion 120Hz, GameController, MoltenVK on Metal
# =============================================================================

cmake_minimum_required(VERSION 3.25)
project(tekken6_ios LANGUAGES C CXX OBJC OBJCXX ASM)

if(NOT IOS)
    message(FATAL_ERROR "This build is configured for iOS. Run: cmake --preset ios")
endif()

set(TEKKEN6_REPO "${CMAKE_CURRENT_SOURCE_DIR}/.." CACHE PATH "Tekken 6 repository root")
set(TEKKEN6_SDK "${TEKKEN6_REPO}/../rexglue-sdk-ios" CACHE PATH "ReXGlue SDK prepared for iOS")
set(TEKKEN6_BUNDLE_ID "com.tekken6.ios" CACHE STRING "App bundle identifier")
set(TEKKEN6_GEN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/generated/default" CACHE PATH "Generated guest code")

get_filename_component(TEKKEN6_REPO "${TEKKEN6_REPO}" ABSOLUTE)
get_filename_component(TEKKEN6_SDK "${TEKKEN6_SDK}" ABSOLUTE)

# Locate MoltenVK framework in prepared SDK
set(MOLTENVK_DIR "${TEKKEN6_SDK}/.tekken6-ios/MoltenVK")
if(NOT EXISTS "${MOLTENVK_DIR}")
    # Fallback to general SDK cache
    set(MOLTENVK_DIR "${TEKKEN6_SDK}/.nfsmw-ios/MoltenVK")
endif()

# Check for static libMoltenVK.a
set(MOLTENVK_STATIC_LIB "${MOLTENVK_DIR}/ios-arm64/libMoltenVK.a")
if(NOT EXISTS "${MOLTENVK_STATIC_LIB}")
    file(GLOB_RECURSE STATIC_CANDS "${MOLTENVK_DIR}/*libMoltenVK.a")
    foreach(c ${STATIC_CANDS})
        if("${c}" MATCHES "ios")
            set(MOLTENVK_STATIC_LIB "${c}")
            break()
        endif()
    endforeach()
endif()

find_library(MOLTENVK_FRAMEWORK MoltenVK
    PATHS "${MOLTENVK_DIR}/ios-arm64" "${MOLTENVK_DIR}" "${TEKKEN6_SDK}"
    PATH_SUFFIXES ios-arm64
    NO_CMAKE_FIND_ROOT_PATH
)

if(NOT MOLTENVK_FRAMEWORK OR NOT EXISTS "${MOLTENVK_FRAMEWORK}")
    file(GLOB_RECURSE MOLTENVK_CANDIDATES
        "${MOLTENVK_DIR}/*MoltenVK.framework"
        "${TEKKEN6_SDK}/*MoltenVK.framework"
    )
    foreach(cand ${MOLTENVK_CANDIDATES})
        if(IS_DIRECTORY "${cand}" AND ("${cand}" MATCHES "ios" OR "${cand}" MATCHES "arm64"))
            set(MOLTENVK_FRAMEWORK "${cand}")
            break()
        endif()
    endforeach()
endif()

if(EXISTS "${MOLTENVK_STATIC_LIB}")
    message(STATUS "Selected Static MoltenVK: ${MOLTENVK_STATIC_LIB}")
endif()
if(MOLTENVK_FRAMEWORK)
    message(STATUS "Selected MoltenVK Framework: ${MOLTENVK_FRAMEWORK}")
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)

set(REXGLUE_ENABLE_TRACY OFF CACHE BOOL "" FORCE)
set(REXGLUE_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(REXGLUE_USE_VULKAN ON CACHE BOOL "" FORCE)
set(REXGLUE_USE_D3D12 OFF CACHE BOOL "" FORCE)
set(BUILD_LOADER OFF CACHE BOOL "" FORCE)
set(ENABLE_WERROR OFF CACHE BOOL "" FORCE)

if(EXISTS "${TEKKEN6_SDK}/CMakeLists.txt")
    add_subdirectory("${TEKKEN6_SDK}" rexglue-sdk EXCLUDE_FROM_ALL)
endif()

# Configure Info.plist with ProMotion and GameController keys
set(EXECUTABLE_NAME "Tekken6")
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/Info.plist.in"
    "${CMAKE_CURRENT_BINARY_DIR}/Info.plist"
    @ONLY
)

# Application Sources
set(APP_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.mm"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/AppDelegate.mm"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ViewController.mm"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/TouchOverlayView.mm"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/GameControllerManager.mm"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/TekkenLogger.mm"
    "${TEKKEN6_REPO}/src/tekken6_hooks.cpp"
)

# Generated game recompilation code (if default.xex was processed)
set(TEKKEN6_WITH_GAME OFF)
if(EXISTS "${TEKKEN6_REPO}/src/recompiled/sources.cmake")
    set(TEKKEN6_GEN_DIR "${TEKKEN6_REPO}/src/recompiled")
    set(TEKKEN6_WITH_GAME ON)
    include("${TEKKEN6_GEN_DIR}/sources.cmake")
    list(APPEND APP_SOURCES ${GENERATED_SOURCES})
    message(STATUS "Including recompiled Tekken 6 guest code from ${TEKKEN6_GEN_DIR}")
elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/generated/default/sources.cmake")
    set(TEKKEN6_GEN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/generated/default")
    set(TEKKEN6_WITH_GAME ON)
    include("${TEKKEN6_GEN_DIR}/sources.cmake")
    list(APPEND APP_SOURCES ${GENERATED_SOURCES})
    message(STATUS "Including recompiled Tekken 6 guest code from ${TEKKEN6_GEN_DIR}")
else()
    message(STATUS "No pre-generated code found at ${TEKKEN6_GEN_DIR}. Building probe harness.")
endif()

# iOS Application Target
add_executable(Tekken6 MACOSX_BUNDLE ${APP_SOURCES})

target_include_directories(Tekken6 PRIVATE
    "${TEKKEN6_REPO}/src"
    "${TEKKEN6_REPO}/src/recompiled"
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${TEKKEN6_SDK}/include"
    "${TEKKEN6_GEN_DIR}"
)

target_compile_definitions(Tekken6 PRIVATE
    REX_PLATFORM_IOS=1
    TEKKEN6_PROMOTION_120HZ=1
    $<$<BOOL:${TEKKEN6_WITH_GAME}>:TEKKEN6_WITH_GAME=1>
    $<$<NOT:$<BOOL:${TEKKEN6_WITH_GAME}>>:TEKKEN6_WITH_GAME=0>
)

target_compile_options(Tekken6 PRIVATE
    "$<$<COMPILE_LANGUAGE:OBJC,OBJCXX>:-fobjc-arc>"
)

# Link Apple System Frameworks
target_link_libraries(Tekken6 PRIVATE
    "-framework UIKit"
    "-framework Foundation"
    "-framework QuartzCore"
    "-framework Metal"
    "-framework GameController"
    "-framework AudioToolbox"
    "-framework AVFoundation"
    "-framework UniformTypeIdentifiers"
)

if(TARGET rex::runtime)
    target_link_libraries(Tekken6 PRIVATE rex::runtime)
endif()

# If rexruntime is a shared library, ensure it is copied into Frameworks/
if(TARGET rexruntime)
    get_target_property(REX_LIB_TYPE rexruntime TYPE)
    if(REX_LIB_TYPE STREQUAL "SHARED_LIBRARY")
        add_custom_command(TARGET Tekken6 POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_BUNDLE_DIR:Tekken6>/Frameworks"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:rexruntime>" "$<TARGET_BUNDLE_DIR:Tekken6>/Frameworks/"
            COMMENT "Embedding librexruntime.dylib into Tekken6.app/Frameworks"
        )
    endif()
endif()

if(EXISTS "${MOLTENVK_STATIC_LIB}")
    target_link_libraries(Tekken6 PRIVATE "${MOLTENVK_STATIC_LIB}")
    target_link_libraries(Tekken6 PRIVATE "-framework IOSurface")
elseif(MOLTENVK_FRAMEWORK)
    target_link_libraries(Tekken6 PRIVATE "${MOLTENVK_FRAMEWORK}")
endif()

if(MOLTENVK_FRAMEWORK AND EXISTS "${MOLTENVK_FRAMEWORK}")
    add_custom_command(TARGET Tekken6 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_BUNDLE_DIR:Tekken6>/Frameworks"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${MOLTENVK_FRAMEWORK}" "$<TARGET_BUNDLE_DIR:Tekken6>/Frameworks/MoltenVK.framework"
        COMMENT "Embedding MoltenVK.framework into Tekken6.app/Frameworks"
    )
endif()

# Embed App Icons, Arena Background & iTunesArtwork into Tekken6.app
add_custom_command(TARGET Tekken6 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/assets/icons" "$<TARGET_BUNDLE_DIR:Tekken6>"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_CURRENT_SOURCE_DIR}/assets/tekken6_bg.jpg" "$<TARGET_BUNDLE_DIR:Tekken6>/tekken6_bg.jpg"
    COMMENT "Embedding app icons and arena background into Tekken6.app"
)

set_target_properties(Tekken6 PROPERTIES
    MACOSX_BUNDLE YES
    MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_BINARY_DIR}/Info.plist"
    MACOSX_BUNDLE_BUNDLE_NAME "Tekken 6"
    MACOSX_BUNDLE_GUI_IDENTIFIER "${TEKKEN6_BUNDLE_ID}"
    XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER "${TEKKEN6_BUNDLE_ID}"
    XCODE_ATTRIBUTE_TARGETED_DEVICE_FAMILY "1,2" # iPhone & iPad
    XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET "16.0"
    XCODE_ATTRIBUTE_ENABLE_BITCODE "NO"
    XCODE_ATTRIBUTE_CODE_SIGNING_ALLOWED "NO" # Sideloading via LiveContainer/SideStore
    BUILD_WITH_INSTALL_RPATH TRUE
    INSTALL_RPATH "@executable_path/Frameworks;@loader_path/Frameworks"
)

# Custom target to package the app into an IPA for LiveContainer / SideStore
add_custom_target(ipa
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_CURRENT_BINARY_DIR}/Payload"
    COMMAND ${CMAKE_COMMAND} -E copy_directory "$<TARGET_BUNDLE_DIR:Tekken6>" "${CMAKE_CURRENT_BINARY_DIR}/Payload/Tekken6.app"
    COMMAND zip -qr "Tekken6.ipa" Payload
    COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_CURRENT_BINARY_DIR}/Payload"
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
    DEPENDS Tekken6
    COMMENT "Packaging Tekken6.app into Tekken6.ipa for sideloading"
)
