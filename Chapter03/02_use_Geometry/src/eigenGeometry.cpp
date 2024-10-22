#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;

int main(int argc, char **argv)
{
    // �����������Ϊ3λС��
    cout.precision(3);
    // Eigen/Geometry ģ���ṩ�˸�����ת��ƽ�Ƶı�ʾ
    // 3D ��ת����ֱ��ʹ�� Matrix3d �� Matrix3f
    Matrix3d rotation_matrix = Matrix3d::Identity();
    cout << "Rotation matrix = \n"
         << rotation_matrix << endl;
    // ��ת����ʹ�� AngleAxis, ���ײ㲻ֱ����Matrix����������Ե���������Ϊ�������������
    AngleAxisd rotation_vector(M_PI / 4, Vector3d(0, 0, 1)); // ��Z����ת45��
    // ��ת�����޷�ֱ�������ֻ��ת���ɾ������
    cout << "rotation vector = \n"
         << rotation_vector.matrix() << endl;
    cout << rotation_vector.angle() << endl
         << rotation_vector.axis().transpose() << endl;

    // ֱ�Ӹ�ֵ
    rotation_matrix = rotation_vector.toRotationMatrix();
    cout << "rotation matrix = \n"
         << rotation_matrix << endl;

    // ʹ��AngleAxis��������任
    Vector3d v(1, 0, 0);
    Vector3d v_rotated = rotation_vector * v;
    cout << "(1,0,0) after rotation (by angle axis) = " << v_rotated.transpose() << endl;
    // ��������ת����
    v_rotated = rotation_matrix * v;
    cout << "(1,0,0) after rotation (by matrix) = " << v_rotated.transpose() << endl;

    // ����ת��סת��Ϊŷ����
    Vector3d euler_angles = rotation_matrix.eulerAngles(0, 1, 2); // RPY��
    cout << "Roll Pitch Yaw = " << euler_angles.transpose() << endl
         << "Yaw Pitch Roll = " << rotation_matrix.eulerAngles(2, 1, 0).transpose() << endl;

    // ʹ��Eigen::Isometryʵ��ŷ�ϱ任����
    Isometry3d T = Isometry3d::Identity();
    cout << "T = \n"
         << T.matrix() << endl;

    // ��ת
    T.rotate(rotation_vector);
    // T.rotate(rotation_matrix);
    cout << "After rotation with rotation_vector or rotation_matrix,\nT =\n"
         << T.matrix() << endl;
    // ƽ��
    T.pretranslate(Vector3d(1, 3, 4));
    cout << "After translation,\nT =\n"
         << T.matrix() << endl;

    // ʹ����α任�����������任
    Vector3d v_transformed = T * v;
    cout << "v_transformed = " << v_transformed.transpose() << endl;

    // ���ڷ������Ӱ�任��ʹ�� Eigen::Affine3d �� Eigen::Projective3d ���ɣ���

    // ��Ԫ��
    // ����ֱ�Ӱ�AngleAxis��ֵ����Ԫ������֮��Ȼ
    Quaterniond q = Quaterniond(rotation_matrix);
    cout << "Quaternion from rotation_matrix: " << q.coeffs().transpose() << endl;
    cout << "Quaternion from rotation_vector: " << Quaterniond(rotation_vector).coeffs().transpose() << endl;

    // ʹ����Ԫ����������任
    v_rotated = q * v;
    cout << "(1,0,0) after rotation with quaternion: " << v_rotated.transpose() << endl;
    // �ó��������˷���ʾ����Ӧ�����¼���
    cout << "Which should be equal to " << (q * Quaterniond(0, 1, 0, 0) * q.inverse()).coeffs().transpose() << endl;

    return 0;
}