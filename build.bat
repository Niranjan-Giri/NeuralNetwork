@echo off
setlocal enabledelayedexpansion

REM Create build directory if it doesn't exist
if not exist "build" (
    echo Build directory not found. Creating it...
    mkdir build
)

REM Navigate to build directory
cd build

REM Run cmake to configure
echo Configuring with CMake...
cmake ..
if errorlevel 1 (
    echo Error: CMake configuration failed!
    exit /b 1
)

REM Build the project
echo Building project...
cmake --build .
if errorlevel 1 (
    echo Error: Build failed!
    exit /b 1
)

REM Go back to project root
cd ..

REM Create bin directory if it doesn't exist
if not exist "bin" (
    echo Bin directory not found. Creating it...
    mkdir bin
)

REM Check if executable exists
if not exist "bin\NeuralNetwork.exe" (
    echo Error: Executable 'NeuralNetwork.exe' not found in bin directory!
    exit /b 1
)

REM Navigate to bin directory and run executable
cd bin
echo Running NeuralNetwork...
NeuralNetwork.exe

endlocal
