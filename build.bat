@echo off
setlocal

:: Create build directory if it doesn't exist
if not exist build (
    mkdir build
)

cd build

:: Run cmake to configure the project
cmake ..

:: Check for passed argument and build accordingly
if "%1" == "-release" (
    cmake --build . --config Release
) else if "%1" == "-debug" (
    cmake --build . --config Debug
) else (
    :: No argument passed, just build the solution with default configuration
    cmake --build .
)

endlocal