cmake_minimum_required(VERSION 3.5)
cmake_policy(VERSION 3.5)
project(PlotTrajectory)

set(CMAKE_BUILD_TYPE Debug)

find_package(Pangolin REQUIRED)
find_package(Eigen3 REQUIRED)

# 生成可执行文件路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 生成库文件路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${Pangolin_INCLUDE_DIRS}
)


link_directories(${Pangolin_LIBRARY_DIRS})

add_executable(plotTrajectory
    src/plotTrajectory.cpp)
target_link_libraries(plotTrajectory
    ${Pangolin_LIBRARIES}
    PlotTraj
)

add_library(PlotTraj SHARED src/Visualization.cpp)
target_link_libraries(PlotTraj
    ${Pangolin_LIBRARIES}
)