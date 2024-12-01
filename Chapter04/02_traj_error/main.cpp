#include <iostream>
#include "TrajType.h"
#include "ProcessData.h"
#include "RMSE.h"
#include "VisualizeTraj.h"

std::string groundtruth_file = "../data/groundtruth.txt";
std::string estimation_file = "../data/estimated.txt";

int main(int argc, char **argv)
{
    // Read trajectory data
    TrajectoryType groundtruth_data = ReadTrajectory(groundtruth_file);
    TrajectoryType estimation_data = ReadTrajectory(estimation_file);

    // Check data size
    assert(!groundtruth_data.empty() && !estimation_data.empty());
    assert(groundtruth_data.size() == estimation_data.size());

    // Calculate RMSE
    float error = ComputeRMSE(groundtruth_data, estimation_data);
    std::cout << "RMSE: " << error << std::endl;

    // Visualization of ground truth and estimated trajectories
    DrawTraj(groundtruth_data, estimation_data);

    return 0;
}