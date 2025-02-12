#include <iostream>
#include <ceres/ceres.h>
#include "03_analytic_derivative.h"
int main(int argc, char **argv)
{
    google::InitGoogleLogging(argv[0]);

    const double initial_x = 5.0; // ��ʼֵ;
    double x = initial_x;         // �Ż�����;

    // ��������;
    ceres::Problem problem;
    // �������涨���QuadraticCostFunction�������ۺ���, ceres��ͨ���Զ��󵼻�ú������ſɱȾ���;
    ceres::CostFunction *cost_function = new QuadraticCostFunction;
    // ��һ��1��ʾ�����ά�ȣ���Ϊ�в��Ǳ���������1���ڶ���1��ʾ�����ά�ȣ���Ϊֻ��xһ������������1��
    problem.AddResidualBlock(cost_function, nullptr, &x);

    // ����Solver�����Ż�, �õ���С���˽�;
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