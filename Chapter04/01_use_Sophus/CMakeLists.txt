cmake_minimum_required(VERSION 2.8)
project(useSophus)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 添加Eigen头文件
include_directories( "/usr/include/eigen3" )

# 为使用 sophus，需要使用find_package命令找到它
find_package(Sophus REQUIRED)
include_directories(${Sophus_INCLUDE_DIRS})

add_executable(useSophus src/useSophus.cpp)
target_link_libraries(useSophus Sophus::Sophus)