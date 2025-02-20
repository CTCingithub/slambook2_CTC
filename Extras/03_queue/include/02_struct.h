#include "Eigen/Dense"

struct RobotPose
{
    Eigen::Vector3d position;
    Eigen::Quaterniond orientation;

    // ���캯��
    RobotPose(const Eigen::Vector3d& pos, const Eigen::Quaterniond& ori):
        position(pos), orientation(ori) {}
};
