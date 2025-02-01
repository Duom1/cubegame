:: Genrated using chatGPT
@echo off
set BUILD_DIR=build

:: Create and navigate to the build directory
if not exist %BUILD_DIR% mkdir %BUILD_DIR%
cd %BUILD_DIR%

:: Run CMake
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -G"NMake Makefiles"

:: Copy the compile_commands.json file back to the original directory
if exist compile_commands.json copy compile_commands.json ..

:: Return to the original directory
cd ..
