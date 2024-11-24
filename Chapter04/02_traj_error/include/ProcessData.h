#ifndef PROCESSDATA_H
#define PROCESSDATA_H

#include <iostream>
#include <fstream>
#include <sophus/se3.hpp>
#include <Eigen/Core>
#include "TrajType.h"
using namespace std;

TrajectoryType ReadTrajectory(const string &file);

#endif
