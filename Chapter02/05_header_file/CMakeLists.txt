# Declare minimum CMake version
cmake_minimum_required(VERSION 2.8)

# Set Cmake project name
project(HelloSLAM)

# Set build type
set(CMAKE_BUILD_TYPE "Debug")

# Add header files
include_directories(include)

# Add shared library
add_library(hello_shared SHARED src/libHelloSLAM.cpp)

add_executable(useHello src/useHello.cpp)
target_link_libraries(useHello hello_shared)
