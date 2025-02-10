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
add_executable(01_Stack_NoHeader examples/01_Stack_NoHeader.cpp)