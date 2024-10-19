#include <iostream>
#include <ctime>

#include <Eigen/Core>
#include <Eigen/Dense>

#define MATRIX_SIZE 50

int main(int argc, char **argv)
{
    std::cout << "Before Initializing" << std::endl
              << "\n===========================================" << std::endl;

    // Eigen �����������;�����Eigen::Matrix������һ��ģ���ࡣ����ǰ��������Ϊ���������ͣ��У���
    // ����һ��2*3��float����
    Eigen::Matrix<float, 2, 3> matrix_23;
    std::cout << "\nmatrix_23:" << std::endl
              << matrix_23 << std::endl;

    // ͬʱ��Eigen ͨ�� typedef �ṩ������������ͣ������ײ�����Eigen::Matrix
    // ���� Vector3d ʵ������ Eigen::Matrix<double, 3, 1>������ά����
    Eigen::Vector3d v_3d;
    Eigen::Matrix<float, 3, 1> vd_3d;
    std::cout << "\nv_3d:" << std::endl
              << v_3d << std::endl;
    std::cout << "\nvd_3d:" << std::endl
              << vd_3d << std::endl;

    // �����ȷ�������С������ʹ�ö�̬��С�ľ���
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_dynamic;
    std::cout << "\nmatrix_dynamic:" << std::endl
              << matrix_dynamic << std::endl;
    // ���򵥵�
    Eigen::MatrixXd matrix_x;
    std::cout << "\nmatrix_x:" << std::endl
              << matrix_x << std::endl;

    // Matrix3d ʵ������ Eigen::Matrix<double, 3, 3>
    Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero(); // ��ʼ��Ϊ��
    std::cout << "Initializing when defining" << std::endl
              << "\n===========================================" << std::endl;
    std::cout << "\nmatrix_33:" << std::endl
              << matrix_33 << std::endl;

    std::cout << "\nAfter Initializing" << std::endl
              << "\n===========================================" << std::endl;

    matrix_23 << 1, 2, 3, 4, 5, 6;
    v_3d << 3, 2, 1;
    vd_3d << 4, 5, 6;
    std::cout << "\nmatrix_23:" << std::endl
              << matrix_23 << std::endl;
    std::cout << "\nv_3d:" << std::endl
              << v_3d << std::endl;
    std::cout << "\nvd_3d:" << std::endl
              << vd_3d << std::endl;

    // ���������������ʽ�任�����
    Eigen::Matrix<double, 2, 1> result_1 = matrix_23.cast<double>() * v_3d;
    Eigen::Matrix<float, 2, 1> result_2 = matrix_23 * vd_3d;
    std::cout << "\nmatrix_23 @ v_3d" << std::endl
              << result_1 << std::endl;
    std::cout << "\nmatrix_23 @ vd_3d" << std::endl
              << result_2 << std::endl;

    // һЩ��������
    // ���������
    std::cout << "\nMatrix Operation" << std::endl
              << "\n===========================================" << std::endl;
    matrix_33 = Eigen::Matrix3d::Random();
    std::cout << "\nmatrix_33:" << std::endl
              << matrix_33 << std::endl;
    // �����ת��
    std::cout << "\ntranspose of matrix_33:" << std::endl
              << matrix_33.transpose() << std::endl;
    // ����Ԫ�����
    std::cout << "\nsum of matrix_33:" << std::endl
              << matrix_33.sum() << std::endl;
    // ����ļ�
    std::cout << "\ntrace of matrix_33:" << std::endl
              << matrix_33.trace() << std::endl;
    // ���˾���
    std::cout << "\n5 * matrix_33 =" << std::endl
              << 5 * matrix_33 << std::endl;
    // �������
    std::cout << "\ninverse of matrix_33:" << std::endl
              << matrix_33.inverse() << std::endl;
    // ���������ʽ
    std::cout << "\ndet of matrix_33:" << std::endl
              << matrix_33.determinant() << std::endl;

    // ���������ϵͳ
    std::cout << "\nEigen System" << std::endl
              << "\n===========================================" << std::endl;
    matrix_dynamic.resize(3, 3);
    matrix_dynamic << 1, 0, 0, 0, 2, 1, 0, 0, 3;
    std::cout << "\nmatrix_dynamic after resizing and setting values:" << std::endl
              << matrix_dynamic << std::endl;
    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigen_solver(matrix_dynamic);
    std::cout << "\neigen values = " << std::endl
              << eigen_solver.eigenvalues() << std::endl;
    std::cout << "\neigen vectors = " << std::endl
              << eigen_solver.eigenvectors() << std::endl;

    // �����Է���

    return 0;
}