cmake_minimum_required( VERSION 2.8 )
project( PlotTrajectory )

set(CMAKE_BUILD_TYPE Debug)

find_package(Pangolin REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

# 生成可执行文件路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${Pangolin_INCLUDE_DIRS}
    "/usr/include/eigen3"
)

file(GLOB SRC_LIST ${PROJECT_SOURCE_DIR}/src/*.cpp)

link_directories(${PROJECT_SOURCE_DIR}/lib)

add_library(PlotTraj SHARED SRC_LIST)
add_subdirectory(${PROJECT_SOURCE_DIR}/src)