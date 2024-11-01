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

# For overriding options for box2d
if(POLICY CMP0077)
    cmake_policy(SET CMP0077 NEW)
endif()

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(SFML)


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



add_executable(${PROJECT_NAME}
        src/main.cpp
)


target_link_libraries(${PROJECT_NAME} PRIVATE
        sfml-graphics
        ImGui-SFML::ImGui-SFML
        box2d
)

# For debugging
message(STATUS "----------------------------------------------------")
message(STATUS "CMAKE_CXX_STANDARD is set to: ${CMAKE_CXX_STANDARD}")
message(STATUS "CMAKE_BUILD_TYPE is set to: ${CMAKE_BUILD_TYPE}")
message(STATUS "CMAKE_INSTALL_PREFIX is set to: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "CMAKE_ARCHIVE_OUTPUT_DIRECTORY is set to: ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message(STATUS "CMAKE_RUNTIME_OUTPUT_DIRECTORY is set to: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "----------------------------------------------------")
