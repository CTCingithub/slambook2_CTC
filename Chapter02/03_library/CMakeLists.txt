# Declare minimum CMake version
cmake_minimum_required(VERSION 2.8)

# Set Cmake project name
project(HelloSLAM)

# Add static library
add_library(hello libHelloSLAM.cpp)