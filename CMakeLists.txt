cmake_minimum_required(VERSION 3.10)
project(CubeGame)

# Some settings
set(RAYLIB_VERSION 5.5)

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

# Souces and includes
include_directories(src)
set(SOURCES src/main.cpp src/cubegame.cpp)

# COmpiling and linking
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
