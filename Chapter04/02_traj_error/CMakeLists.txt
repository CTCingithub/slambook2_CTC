cmake_minimum_required(VERSION 2.8)
project(TrjectorError)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Eigen, Sophus and Pangolin
find_package(Eigen3 REQUIRED)
find_package(Sophus REQUIRED)
find_package(Pangolin REQUIRED)
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${EIGEN3_INCLUDE_DIR}
    ${Sophus_INCLUDE_DIRS}
    ${Pangolin_INCLUDE_DIRS}
)

option(USE_UBUNTU_20 "Set to ON if you are using Ubuntu 20.04" OFF)
if(USE_UBUNTU_20)
    message("You are using Ubuntu 20.04, fmt::fmt will be linked")
    find_package(fmt REQUIRED)
    set(FMT_LIBRARIES fmt::fmt)
endif()

add_executable(traj_error src/TrajectoryError.cpp)
target_link_libraries(traj_error
    Sophus::Sophus
    ${Pangolin_LIBRARIES}
    ${FMT_LIBRARIES}
)

add_library(ReadData SHARED src/ReadTraj.cpp)
link_directories(
    /usr/local/include
    /usr/local/lib
)
target_link_libraries(ReadData
    # Sophus::Sophus
    # ${FMT_LIBRARIES}
    ${Sophus_LIBRARIES}
    ${EIGEN3_LIBRARIES}
    ${PROJECT_SOURCE_DIR}/include
)