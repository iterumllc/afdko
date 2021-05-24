cmake_minimum_required(VERSION 3.14)

project(afdko)

if(SKBUILD)
    find_package(PythonExtensions REQUIRED)
endif()

# RelWithDebInfo builds an optimized binary but includes debugging symbols
# Other common possibilities are "Debug" and "Release"
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Build type configuration" FORCE)
endif()

message(STATUS "Build type is ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_STANDARD 11)

# Antlr 4 configuration
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
add_definitions(-DANTLR4CPP_STATIC)
set(ANTLR4_WITH_STATIC_CRT OFF)
include(ExternalAntlr4Cpp)
set(ANTLR4_TAG tags/4.9.2)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(WIN32)
    add_compile_definitions(CTL_CDECL=__cdecl CDECL=__cdecl
        OS=os_windowsNT ISP=isp_i80486 _CRT_SECURE_NO_DEPRECATE
        $<$<CONFIG:Release>:NDEBUG>)
endif()

add_subdirectory(c/shared/source)
add_subdirectory(c/detype1/source)
add_subdirectory(c/mergefonts/source)
add_subdirectory(c/rotatefont/source)
add_subdirectory(c/sfntdiff/source)
add_subdirectory(c/sfntedit/source)
add_subdirectory(c/spot/source)
add_subdirectory(c/tx/source)
add_subdirectory(c/type1/source)
add_subdirectory(c/makeotf)
