cmake_minimum_required(VERSION 3.22.1)
project(NeuralNetwork)

add_executable(NeuralNetwork
    src/Core.cpp
    src/Tensor.cpp
)

target_include_directories(NeuralNetwork PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

set_target_properties(NeuralNetwork PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/Debug
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/Release
)