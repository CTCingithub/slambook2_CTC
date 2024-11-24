// #include <iostream>
// #include <fstream>
// #include <unistd.h>
// #include <Eigen/Core>
// #include <pangolin/pangolin.h>
// #include "sophus/se3.hpp"
#include "TrajType.h"
#include "ProcessData.h"

std::string groundtruth_file = "../data/groundtruth.txt";
std::string estimation_file = "../data/estimated.txt";

int main(int argc, char **argv)
{
    TrajectoryType groundtruth=ReadTrajectory(groundtruth_file);
    return 0;
}