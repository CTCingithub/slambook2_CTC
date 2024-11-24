#include <iostream>
#include <fstream>
#include <sophus/se3.hpp>
#include <Eigen/Core>
#include "TrajType.h"

TrajectoryType ReadTrajectory(const std::string &file)
{
    std::ifstream fin(file);
    TrajectoryType traj;
    if (!fin)
    {
        std::cerr << "Cannot open file: " << file << std::endl;
        return traj;
    }

    while (!fin.eof())
    {
        float time, tx, ty, tz, qx, qy, qz, qw;
        fin >> time >> tx >> ty >> tz >> qx >> qy >> qz >> qw;
        Sophus::SE3f Pose(Eigen::Quaternionf(qw, qx, qy, qz), Eigen::Vector3f(tx, ty, tz));
        traj.push_back(Pose);
    }
    return traj;
}