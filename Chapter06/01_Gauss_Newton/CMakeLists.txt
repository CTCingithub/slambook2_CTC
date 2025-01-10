cmake_minimum_required(VERSION 3.5)

# Avoid std::optional not declared error
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

# Set project name before using ${PROJECT_SOURCE_DIR},
# otherwise it will direct to /usr/bin
project(Gauss_Newton_Iteration)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

find_package(Eigen3 REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(OpenCV REQUIRED)
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${EIGEN3_INCLUDE_DIR}
    ${YAML_CPP_INCLUDE_DIR}
    ${OpenCV_INCLUDE_DIRS}
)

# Compile .so files
add_library(gendata SHARED src/GetData.cpp)
target_link_libraries(gendata
    yaml-cpp
    ${OpenCV_LIBS}
)
add_library(gaussnewton SHARED src/IterateGN.cpp)
target_link_libraries(gaussnewton
    yaml-cpp
    ${EIGEN3_LIBRARIES}
)

add_executable(GaussNewtonExample main.cpp)
target_link_libraries(GaussNewtonExample
    gendata
    gaussnewton
)
