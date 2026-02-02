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

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(Test 
    test/tensor_test.cpp
    src/Tensor.cpp
)

target_include_directories(Test PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(Test
    gtest_main
)

enable_testing()
add_test(NAME Test COMMAND Test)

set_target_properties(Test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/Debug
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/Release
)