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
find_package(Ceres REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(absl REQUIRED)

# Build shared library

# Build executable files
add_executable(01_hello_world examples/01_hello_world.cpp)
target_link_libraries(01_hello_world
    ceres
)

add_executable(02_numeric_derivative examples/02_numeric_derivative.cpp)
target_link_libraries(02_numeric_derivative
    ceres
)

add_executable(03_analytic_derivative examples/03_analytic_derivative.cpp)
target_link_libraries(03_analytic_derivative
    ceres
)

add_executable(04_powell examples/04_powell.cpp)
target_link_libraries(04_powell
    ceres
    absl::log_initialize
    absl::flags
    absl::flags_parse
)

add_executable(05_curve_fitting
    examples/05_curve_fitting.cpp
    src/curve_data.cpp
)
target_link_libraries(05_curve_fitting
    ceres
)

add_executable(06_robust_curve_fitting
    examples/06_robust_curve_fitting.cpp
    src/curve_data.cpp
)
target_link_libraries(06_robust_curve_fitting
    ceres
)