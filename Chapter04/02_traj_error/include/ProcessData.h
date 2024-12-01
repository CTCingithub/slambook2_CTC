#ifndef PROCESSDATA_H
#define PROCESSDATA_H

#include <iostream>
#include <fstream>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include "sophus/se3.hpp"
#include "TrajType.h"

TrajectoryType ReadTrajectory(const std::string &file);

#endif
