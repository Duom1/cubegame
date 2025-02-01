#!/bin/sh
# Genrated using chatGPT

# Define the build directory
BUILD_DIR="build"

# Create and enter the build directory
mkdir -p "$BUILD_DIR" && cd "$BUILD_DIR"

# Run CMake with the specified option
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

# Copy the compile_commands.json file back to the original directory
cp compile_commands.json ..

# Return to the original directory
cd ..
