#include <iostream>
#include <queue>
#include "Eigen/Dense"
#include "02_struct.h"

int main(int argc, char *argv[])
{
    std::queue<RobotPose> robot_queue; // 创建一个队列，存储RobotPose结构体

    robot_queue.push(
        RobotPose(Eigen::Vector3d(1.0, 2.0, 0.5),
                  Eigen::Quaterniond(1, 0, 0, 0)));

    robot_queue.push(
        RobotPose(Eigen::Vector3d(3.0, 4.0, 1.0),
                  Eigen::Quaterniond(
                      Eigen::AngleAxisd(M_PI / 2, Eigen::Vector3d::UnitZ()))));

    RobotPose frontPose = robot_queue.front();
    std::cout << "Front position: " << frontPose.position.transpose() << std::endl;

    return 0;
}
