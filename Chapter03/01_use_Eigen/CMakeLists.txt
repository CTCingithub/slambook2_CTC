cmake_minimum_required(VERSION 2.8)
project(useEigen)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-O3")

# ����Eigenͷ�ļ�
include_directories("/usr/include/eigen3")
add_executable(eigenMatrix src/eigenMatrix.cpp)