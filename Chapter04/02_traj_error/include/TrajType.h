#ifndef TRAJTYPE_H
#define TRAJTYPE_H

#include <vector>
#include <Eigen/Core>
#include <sophus/se3.hpp>

// ����TrajectoryTypeΪ����Sophus::SE3d���������
typedef std::vector<Sophus::SE3d, Eigen::aligned_allocator<Sophus::SE3d>> TrajectoryType;

#endif // TRAJTYPE_H
