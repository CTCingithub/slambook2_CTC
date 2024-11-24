#ifndef TRAJTYPE_H
#define TRAJTYPE_H

#include <vector>
#include <Eigen/Core>
#include <sophus/se3.hpp>

// 定义TrajectoryType为包含Sophus::SE3d对象的向量
typedef std::vector<Sophus::SE3d, Eigen::aligned_allocator<Sophus::SE3d>> TrajectoryType;

#endif // TRAJTYPE_H
