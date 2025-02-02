cmake_minimum_required(VERSION 3.31.5)
project(CubeGame)

# Some settings
set(RAYLIB_VERSION 5.5)
set(IMGUI_VERSION v1.91.8)
set(RLIMGUI_VERSION main)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Getting libs
include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib
    GIT_TAG ${RAYLIB_VERSION}
)
FetchContent_MakeAvailable(raylib)

set(IMGUI_DIR ${CMAKE_BINARY_DIR}/_deps/imgui-src/)
FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui
    GIT_TAG ${IMGUI_VERSION}
)
FetchContent_MakeAvailable(imgui)

set(RLIMGUI_DIR ${CMAKE_BINARY_DIR}/_deps/rlimgui-src/)
FetchContent_Declare(
    rlimgui
    GIT_REPOSITORY https://github.com/raylib-extras/rlImGui
    GIT_TAG ${RLIMGUI_VERSION}
)
FetchContent_MakeAvailable(rlimgui)

# Compilation and linking
include_directories(src)
include_directories(${IMGUI_DIR} ${RLIMGUI_DIR})
set(
    SOURCES
    src/main.cpp
    src/cubegame.cpp 
    ${IMGUI_DIR}/imgui.cpp 
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${RLIMGUI_DIR}/rlImGui.cpp
)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
