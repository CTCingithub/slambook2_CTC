#ifndef RMSE_H
#define RMSE_H

#include "sophus/se3.hpp"
#include "TrajType.h"

float ComputeRMSE(const TrajectoryType &ground_truth, const TrajectoryType &estimated);

#endif