cmake_minimum_required(VERSION 3.5)

# Avoid std::optional not declared error
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(TrjectorError)

set(CMAKE_BUILD_TYPE Debug)
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

# Compiile .so files
add_library(ReadData SHARED src/ReadTraj.cpp)
target_link_libraries(ReadData
    ${EIGEN3_LIBRARIES}
    ${Sophus_LIBRARIES}
    ${FMT_LIBRARIES}
)
add_library(GetRMSE SHARED src/ComputeError.cpp)
target_link_libraries(GetRMSE
    ${Sophus_LIBRARIES}
)
add_library(Visualization SHARED src/PlotTraj.cpp)
target_link_libraries(Visualization
    ${Pangolin_LIBRARIES}
)

add_executable(traj_error main.cpp)
target_link_libraries(traj_error
    ReadData
    GetRMSE
    Visualization
)