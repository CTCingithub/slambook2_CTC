#include <iostream>
#include <ctime>

#include <Eigen/Core>
#include <Eigen/Dense>

#define MATRIX_SIZE 50

int main(int argc, char **argv)
{
    std::cout << "Before Initializing" << std::endl
              << "\n===========================================" << std::endl;

    // Eigen 中所有向量和矩阵都是Eigen::Matrix，它是一个模板类。它的前三个参数为：数据类型，行，列
    // 声明一个2*3的float矩阵
    Eigen::Matrix<float, 2, 3> matrix_23;
    std::cout << "\nmatrix_23:" << std::endl
              << matrix_23 << std::endl;

    // 同时，Eigen 通过 typedef 提供了许多内置类型，不过底层仍是Eigen::Matrix
    // 例如 Vector3d 实质上是 Eigen::Matrix<double, 3, 1>，即三维向量
    Eigen::Vector3d v_3d;
    Eigen::Matrix<float, 3, 1> vd_3d;
    std::cout << "\nv_3d:" << std::endl
              << v_3d << std::endl;
    std::cout << "\nvd_3d:" << std::endl
              << vd_3d << std::endl;

    // 如果不确定矩阵大小，可以使用动态大小的矩阵
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_dynamic;
    std::cout << "\nmatrix_dynamic:" << std::endl
              << matrix_dynamic << std::endl;
    // 更简单的
    Eigen::MatrixXd matrix_x;
    std::cout << "\nmatrix_x:" << std::endl
              << matrix_x << std::endl;

    // Matrix3d 实质上是 Eigen::Matrix<double, 3, 3>
    Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero(); // 初始化为零
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

    // 访问矩阵元素
    std::cout << "\nmatrix_23(0,0): " << matrix_23(0, 0) << std::endl;
    std::cout << "\nvd_3d(1): " << vd_3d(1) << std::endl;

    // 矩阵和向量经过显式变换后相乘
    Eigen::Matrix<double, 2, 1> result_1 = matrix_23.cast<double>() * v_3d;
    Eigen::Matrix<float, 2, 1> result_2 = matrix_23 * vd_3d;
    std::cout << "\nmatrix_23 @ v_3d" << std::endl
              << result_1 << std::endl;
    std::cout << "\nmatrix_23 @ vd_3d" << std::endl
              << result_2 << std::endl;

    // 一些矩阵运算
    // 随机数矩阵
    std::cout << "\nMatrix Operation" << std::endl
              << "\n===========================================" << std::endl;
    matrix_33 = Eigen::Matrix3d::Random();
    std::cout << "\nmatrix_33:" << std::endl
              << matrix_33 << std::endl;
    // 矩阵的转置
    std::cout << "\ntranspose of matrix_33:" << std::endl
              << matrix_33.transpose() << std::endl;
    // 矩阵元素求和
    std::cout << "\nsum of matrix_33:" << std::endl
              << matrix_33.sum() << std::endl;
    // 矩阵的迹
    std::cout << "\ntrace of matrix_33:" << std::endl
              << matrix_33.trace() << std::endl;
    // 数乘矩阵
    std::cout << "\n5 * matrix_33 =" << std::endl
              << 5 * matrix_33 << std::endl;
    // 矩阵的逆
    std::cout << "\ninverse of matrix_33:" << std::endl
              << matrix_33.inverse() << std::endl;
    // 矩阵的行列式
    std::cout << "\ndet of matrix_33:" << std::endl
              << matrix_33.determinant() << std::endl;

    // 矩阵的特征系统
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

    // 解线性方程
    std::cout << "\nLinear Equation Solution" << std::endl
              << "\n===========================================" << std::endl;
    Eigen::Matrix<double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN = Eigen::MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
    matrix_NN = matrix_NN * matrix_NN.transpose();
    Eigen::Matrix<double, MATRIX_SIZE, 1> v_Nd = Eigen::MatrixXd::Random(MATRIX_SIZE, 1);

    // 计时器
    clock_t time_start = clock();
    // 直接求逆矩阵求解
    Eigen::Matrix<double, MATRIX_SIZE, 1> x_Nd = matrix_NN.inverse() * v_Nd;
    std::cout << "\nDuration in normal inverse case:" << 1000 * (clock() - time_start) / (double)CLOCKS_PER_SEC << "ms" << std::endl;
    // std::cout << "x_Nd = " << x_Nd.transpose() << std::endl;

    // 重新计时
    time_start = clock();
    // 使用QR分解求解
    x_Nd = matrix_NN.colPivHouseholderQr().solve(v_Nd);
    std::cout << "\nDuration in QR decomposition case:" << 1000 * (clock() - time_start) / (double)CLOCKS_PER_SEC << "ms" << std::endl;

    // 重新计时
    time_start = clock();
    // 使用Cholesky分解求解
    x_Nd = matrix_NN.ldlt().solve(v_Nd);
    std::cout << "\nDuration in Cholesky decomposition case:" << 1000 * (clock() - time_start) / (double)CLOCKS_PER_SEC << "ms" << std::endl;

    return 0;
}