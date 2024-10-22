#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;

int main(int argc, char **argv)
{
    // 设置输出精度为3位小数
    cout.precision(3);
    // Eigen/Geometry 模块提供了各种旋转和平移的表示
    // 3D 旋转矩阵直接使用 Matrix3d 或 Matrix3f
    Matrix3d rotation_matrix = Matrix3d::Identity();
    cout << "Rotation matrix = \n"
         << rotation_matrix << endl;
    // 旋转向量使用 AngleAxis, 它底层不直接是Matrix，但运算可以当作矩阵（因为重载了运算符）
    AngleAxisd rotation_vector(M_PI / 4, Vector3d(0, 0, 1)); // 沿Z轴旋转45度
    // 旋转向量无法直接输出，只能转换成矩阵输出
    cout << "rotation vector = \n"
         << rotation_vector.matrix() << endl;
    cout << rotation_vector.angle() << endl
         << rotation_vector.axis().transpose() << endl;

    // 直接赋值
    rotation_matrix = rotation_vector.toRotationMatrix();
    cout << "rotation matrix = \n"
         << rotation_matrix << endl;

    // 使用AngleAxis进行坐标变换
    Vector3d v(1, 0, 0);
    Vector3d v_rotated = rotation_vector * v;
    cout << "(1,0,0) after rotation (by angle axis) = " << v_rotated.transpose() << endl;
    // 或者用旋转矩阵
    v_rotated = rotation_matrix * v;
    cout << "(1,0,0) after rotation (by matrix) = " << v_rotated.transpose() << endl;

    // 将旋转居住转换为欧拉角
    Vector3d euler_angles = rotation_matrix.eulerAngles(0, 1, 2); // RPY角
    cout << "Roll Pitch Yaw = " << euler_angles.transpose() << endl
         << "Yaw Pitch Roll = " << rotation_matrix.eulerAngles(2, 1, 0).transpose() << endl;

    // 使用Eigen::Isometry实现欧氏变换矩阵
    Isometry3d T = Isometry3d::Identity();
    cout << "T = \n"
         << T.matrix() << endl;

    // 旋转
    T.rotate(rotation_vector);
    // T.rotate(rotation_matrix);
    cout << "After rotation with rotation_vector or rotation_matrix,\nT =\n"
         << T.matrix() << endl;
    // 平移
    T.pretranslate(Vector3d(1, 3, 4));
    cout << "After translation,\nT =\n"
         << T.matrix() << endl;

    // 使用齐次变换矩阵进行坐标变换
    Vector3d v_transformed = T * v;
    cout << "v_transformed = " << v_transformed.transpose() << endl;

    // 对于仿射和射影变换，使用 Eigen::Affine3d 和 Eigen::Projective3d 即可，略

    // 四元数
    // 可以直接把AngleAxis赋值给四元数，反之亦然
    Quaterniond q = Quaterniond(rotation_matrix);
    cout << "Quaternion from rotation_matrix: " << q.coeffs().transpose() << endl;
    cout << "Quaternion from rotation_vector: " << Quaterniond(rotation_vector).coeffs().transpose() << endl;

    // 使用四元数进行坐标变换
    v_rotated = q * v;
    cout << "(1,0,0) after rotation with quaternion: " << v_rotated.transpose() << endl;
    // 用常规向量乘法表示，则应该如下计算
    cout << "Which should be equal to " << (q * Quaterniond(0, 1, 0, 0) * q.inverse()).coeffs().transpose() << endl;

    return 0;
}