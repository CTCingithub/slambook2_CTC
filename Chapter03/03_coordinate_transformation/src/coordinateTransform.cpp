#include <iostream>
#include <vector>
#include <algorithm>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;

int main(int argc, char **argv)
{
    Quaternionf q1(0.35, 0.2, 0.3, 0.1), q2(-0.5, 0.4, -0.1, 0.2); // 两机器人的姿态
    cout << "q_1 = " << q1.coeffs().transpose() << endl;
    cout << "Corresponding to a rotation matrix:\n"
         << q1.matrix() << endl;
    cout << "\nq_2 = " << q2.coeffs().transpose() << endl;
    cout << "Corresponding to a rotation matrix:\n"
         << q2.matrix() << endl;

    Vector3f t1(0.3, 0, 0.1), t2(-0.1, 0.5, 0.7); // 两机器人在世界坐标系中的位置
    Vector3f p1(0.5, 0, 0.5);                     // p向量在第一个机器人坐标系中的位置
    cout << "\nt_1 = " << t1.transpose() << endl;
    cout << "t_2 = " << t2.transpose() << endl;
    cout << "p1 = " << p1.transpose() << endl;

    Isometry3f T1w(q1), T2w(q2);
    T1w.pretranslate(t1);
    T2w.pretranslate(t2);
    cout << "\nT1w = \n"
         << T1w.matrix() << endl;
    cout << "\nT2w = \n"
         << T2w.matrix() << endl;

    Vector3f p2 = T2w * T1w.inverse() * p1;
    cout << "\np2 = " << p2.transpose() << endl;

    return 0;
}