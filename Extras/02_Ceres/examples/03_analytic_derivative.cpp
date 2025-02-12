#include <iostream>
#include <ceres/ceres.h>
#include "03_analytic_derivative.h"
int main(int argc, char **argv)
{
    google::InitGoogleLogging(argv[0]);

    const double initial_x = 5.0; // 初始值;
    double x = initial_x;         // 优化变量;

    // 构建问题;
    ceres::Problem problem;
    // 利用上面定义的QuadraticCostFunction构建代价函数, ceres会通过自动求导获得函数的雅可比矩阵;
    ceres::CostFunction *cost_function = new QuadraticCostFunction;
    // 第一个1表示输出的维度，因为残差是标量所以是1；第二个1表示输入的维度，因为只有x一个变量所以是1；
    problem.AddResidualBlock(cost_function, nullptr, &x);

    // 利用Solver迭代优化, 得到最小二乘解;
    ceres::Solver::Options options;
    options.linear_solver_type = ceres::DENSE_QR;
    options.minimizer_progress_to_stdout = true;
    ceres::Solver::Summary summary;
    ceres::Solve(options, &problem, &summary);

    std::cout << summary.BriefReport() << "\n";
    std::cout << "x : " << initial_x
              << " -> " << x << "\n";
    return 0;
}