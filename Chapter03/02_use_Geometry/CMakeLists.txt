cmake_minimum_required( VERSION 2.8 )
project( geometry )

# ����Eigenͷ�ļ�
include_directories( "/usr/include/eigen3" )

add_executable(eigenGeometry src/eigenGeometry.cpp)
