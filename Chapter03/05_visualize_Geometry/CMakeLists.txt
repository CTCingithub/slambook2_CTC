cmake_minimum_required( VERSION 2.8 )
project( visualizeGeometry )

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 添加Eigen头文件
include_directories( "/usr/include/eigen3" )

# 添加Pangolin依赖
find_package(Pangolin)
include_directories(${Pangolin_INCLUDE_DIRS})

add_executable(visualizeGeometry src/visualizeGeometry.cpp)

target_link_libraries(visualizeGeometry ${Pangolin_LIBRARIES})
