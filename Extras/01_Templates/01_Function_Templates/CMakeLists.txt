cmake_minimum_required(VERSION 3.5)

# Avoid std::optional not declared error
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

project(Function_Templates)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Eigen dependency
include_directories(
    "/usr/include/eigen3"
    ${PROJECT_SOURCE_DIR}/include
)

# Build shared library

# Build executable files
add_executable(01_GetMax_NoHeader examples/01_GetMax_NoHeader.cpp)
add_executable(02_GetMax_Header examples/02_GetMax_Header.cpp)
add_executable(03_GetMax_auto examples/03_GetMax_auto.cpp)