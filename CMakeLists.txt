cmake_minimum_required(VERSION 3.12)
project(evolution LANGUAGES CXX)

# Set project directories
# this is where the compiled and linked binary will go
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
# and this is where the compiled components will be stored ready for linking
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE})

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
include(cmake/compiler-flags.cmake)
set(CMAKE_CXX_STANDARD 17)

enable_testing()

# For overriding options for box2d
if(POLICY CMP0077)
    cmake_policy(SET CMP0077 NEW)
endif()

include(FetchContent)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})


FetchContent_Declare(
        ImGui
        GIT_REPOSITORY https://github.com/ocornut/imgui
        GIT_TAG v1.89.9-docking
)
FetchContent_MakeAvailable(ImGui)
FetchContent_GetProperties(ImGui SOURCE_DIR IMGUI_DIR)
set(IMGUI_SFML_FIND_SFML OFF)
include_directories(${imgui_SOURCE_DIR})


FetchContent_Declare(
        ImGui-SFML
        GIT_REPOSITORY https://github.com/SFML/imgui-sfml
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(ImGui-SFML)


FetchContent_Declare(
    box2d
    GIT_REPOSITORY https://github.com/erincatto/box2d.git
    GIT_TAG v3.0.0
)
set(BOX2D_BUILD_UNIT_TESTS OFF CACHE BOOL "Disable Box2D unit tests")
set(BOX2D_BUILD_TESTBED OFF CACHE BOOL "Disable Box2D testbed")
FetchContent_MakeAvailable(box2d)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)
enable_testing()

# For debugging
message(STATUS "----------------------------------------------------")
message(STATUS "CMAKE_CXX_STANDARD is set to: ${CMAKE_CXX_STANDARD}")
message(STATUS "CMAKE_BUILD_TYPE is set to: ${CMAKE_BUILD_TYPE}")
message(STATUS "CMAKE_INSTALL_PREFIX is set to: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "CMAKE_ARCHIVE_OUTPUT_DIRECTORY is set to: ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message(STATUS "CMAKE_RUNTIME_OUTPUT_DIRECTORY is set to: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "----------------------------------------------------")

add_subdirectory(src/common)
add_subdirectory(src/tests/common)
add_subdirectory(src/simulation)
add_subdirectory(src/tests/simulation)
add_subdirectory(src/road)
add_subdirectory(src/tests/road)
add_subdirectory(src/evolution)
add_subdirectory(src/tests/evolution)
add_subdirectory(src/app)