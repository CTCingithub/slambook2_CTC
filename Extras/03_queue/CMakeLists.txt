cmake_minimum_required(VERSION 3.5)

# Avoid std::optional not declared error
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

project(Function_Templates)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Dependency
include_directories(
    "/usr/include/eigen3"
    ${PROJECT_SOURCE_DIR}/include
)
find_package(Eigen3 REQUIRED PATHS)

# Build shared library

# Build executable files
add_executable(01_hello_world examples/01_hello_world.cpp)
target_link_libraries(01_hello_world
)

add_executable(02_use_struct examples/02_use_struct.cpp)
target_link_libraries(02_use_struct
)
