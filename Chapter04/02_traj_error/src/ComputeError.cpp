#include "sophus/se3.hpp"
#include "TrajType.h"

float ComputeRMSE(const TrajectoryType &ground_truth, const TrajectoryType &estimated)
{
    float rmse = 0;
    for (std::size_t i = 0; i < ground_truth.size(); i++)
    {
        Sophus::SE3f p1 = estimated[i], p2 = ground_truth[i];
        float error = (p2.inverse() * p1).log().norm();
        rmse += error * error;
    }
    rmse = sqrt(rmse / float(ground_truth.size()));

    return rmse;
}