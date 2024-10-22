cmake_minimum_required( VERSION 2.8 )
project( CoordinateTransform )

include_directories("/usr/include/eigen3")
add_executable(coordinateTransform src/coordinateTransform.cpp)
