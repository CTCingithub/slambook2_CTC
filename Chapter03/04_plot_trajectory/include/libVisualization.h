#ifndef VISUALIZATION_H__
#define VISUALIZATION_H__

#include <pangolin/pangolin.h>
#include <vector>
#include <Eigen/Core>
#include <Eigen/Geometry>

void DrawTrajectory(std::vector<Eigen::Isometry3d, Eigen::aligned_allocator<Eigen::Isometry3d>>);

#endif