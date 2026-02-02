#!/bin/bash

# Exit on error
set -e

# Create build directory if it doesn't exist
if [ ! -d "build" ]; then
    echo "Build directory not found. Creating it..."
    mkdir -p build
fi

# Navigate to build directory
cd build

# Run cmake to configure
echo "Configuring with CMake..."
cmake ..

# Build the project
echo "Building project..."
cmake --build .

# Go back to project root
cd ..

# Create bin directory if it doesn't exist
if [ ! -d "bin" ]; then
    echo "Bin directory not found. Creating it..."
    mkdir -p bin
fi

# Check if executable exists
if [ ! -f "bin/NeuralNetwork" ]; then
    echo "Error: Executable 'NeuralNetwork' not found in bin directory!"
    exit 1
fi

# Navigate to bin directory and run executable
cd bin
echo "Running NeuralNetwork..."
./NeuralNetwork
