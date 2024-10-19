# Declare minimum CMake version
cmake_minimum_required(VERSION 2.8)

# Set Cmake project name
project(HelloSLAM)

# Add shared library
add_library(hello_shared SHARED libHelloSLAM.cpp)