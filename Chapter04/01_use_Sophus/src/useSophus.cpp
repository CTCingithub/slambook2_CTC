#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include "sophus/se3.hpp"

int main(int argc, char **argv)
{
    std::cout.precision(3);
    std::cout << "M_PI = " << M_PI << std::endl;
    std::cout << "========================SO3 & so3========================" << std::endl;
    // Rotation matrix of rotation pi/2 around Z axis
    Eigen::Matrix3f R = Eigen::AngleAxisf(M_PI / 2, Eigen::Vector3f(0, 0, 1)).toRotationMatrix();
    std::cout << "R = \n"
              << R << std::endl;
    // Quaternion
    Eigen::Quaternionf q(R);
    std::cout << "q.T = \n"
              << q.coeffs().transpose() << std::endl;
    // Convert to Sophus::SO3*
    Sophus::SO3f SO3_R(R);
    Sophus::SO3f SO3_q(q);
    std::cout << "SO(3) from matrix:\n"
              << SO3_R.matrix() << std::endl;
    std::cout << "SO(3) from quaternion:\n"
              << SO3_q.matrix() << std::endl;

    // Obtain corresponding so3 with logititude map
    Eigen::Vector3f so3 = SO3_R.log();
    std::cout << "so3.T = \n"
              << so3.transpose() << std::endl;
    // hat for vector to skew-symmetric matrix
    std::cout << "so3 hat = \n"
              << Sophus::SO3f::hat(so3).transpose() << std::endl;
    // vee for skew-symmetric matrix to vector, vee is the abbreviation of vectorization
    std::cout << "so3 vee.T = \n"
              << Sophus::SO3f::vee(Sophus::SO3f::hat(so3)).transpose() << std::endl;

    // Update incremental disturbance model for so3
    Eigen::Vector3f update_so3(1e-4, 0, 0);
    std::cout << "update_so3.T = \n"
              << (update_so3).transpose() << std::endl;
    Sophus::SO3f SO3_updated = Sophus::SO3f::exp(update_so3) * SO3_R;
    std::cout << "SO(3) updated:\n"
              << SO3_updated.matrix() << std::endl;

    std::cout << "========================SE3 & se3========================" << std::endl;
    Eigen::Vector3f t(1, 0, 0);
    Sophus::SE3f SE3_Rt(R, t); // Create SE3 from rotation matrix and translation
    Sophus::SE3f SE3_qt(q, t); // Create SE3 from quaternion and translation
    std::cout << "SE3 from R,t = \n"
              << SE3_Rt.matrix() << std::endl;
    std::cout << "SE3 from q,t = \n"
              << SE3_qt.matrix() << std::endl;

    typedef Eigen::Matrix<float, 6, 1> Vector6f;
    Vector6f se3 = SE3_Rt.log();
    std::cout << "se3.T = \n"
              << se3.transpose() << std::endl;
    std::cout << "se3 hat = \n"
              << Sophus::SE3f::hat(se3) << std::endl;
    std::cout << "se3 hat vee = \n"
              << Sophus::SE3f::vee(Sophus::SE3f::hat(se3)).transpose() << std::endl;

    // Update incremental disturbance model for se3
    Vector6f update_se3;
    update_se3.setZero();
    update_se3(0, 0) = 1e-2;
    std::cout << "update_se3.T = \n"
              << update_se3.transpose() << std::endl;
    Sophus::SE3f SE3_updated = Sophus::SE3f::exp(update_se3) * SE3_Rt;
    std::cout << "SE3 updated = \n"
              << SE3_updated.matrix() << std::endl;

    return 0;
}