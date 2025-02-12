#include <iostream>
#include <string>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/log/initialize.h"
#include "absl/log/log.h"

#include "ceres/ceres.h"
#include "04_powell.h"

ABSL_FLAG(std::string,
          minimizer,
          "trust_region",
          "Minimizer type to use, choices are: line_search & trust_region");

int main(int argc, char **argv)
{
    // logging
    absl::InitializeLog();
    absl::ParseCommandLine(argc, argv);

    // Initial value
    double x1 = 3.0;
    double x2 = -1.0;
    double x3 = 0.0;
    double x4 = 1.0;

    // Problem setup
    ceres::Problem problem;

    // Add residual terms
    problem.AddResidualBlock(
        new ceres::AutoDiffCostFunction<F1, 1, 1, 1>(new F1), nullptr, &x1, &x2);
    // 模板参数F1是用户定义的成本函类，
    // 1, 1, 1分别表示残差维度、两个参数的维度
    // 第一个F1是创建一个基于F1类的自动微分成本函数
    // 第二个F1是实际创建这个类的实例
    // 两个F1都必须引用同一个用户定义的类
    problem.AddResidualBlock(
        new ceres::AutoDiffCostFunction<F2, 1, 1, 1>(new F2), nullptr, &x3, &x4);
    problem.AddResidualBlock(
        new ceres::AutoDiffCostFunction<F3, 1, 1, 1>(new F3), nullptr, &x2, &x3);
    problem.AddResidualBlock(
        new ceres::AutoDiffCostFunction<F4, 1, 1, 1>(new F4), nullptr, &x1, &x4);

    ceres::Solver::Options options;
    LOG_IF(FATAL,
           !ceres::StringToMinimizerType(absl::GetFlag(FLAGS_minimizer),
                                         &options.minimizer_type))
        << "Invalid minimizer: " << absl::GetFlag(FLAGS_minimizer)
        << ", valid options are: trust_region and line_search.";

    options.max_num_iterations = 100;
    options.linear_solver_type = ceres::DENSE_QR;
    options.minimizer_progress_to_stdout = true;

    // clang-format off
    std::cout << "Initial x1 = " << x1
            << ", x2 = " << x2
            << ", x3 = " << x3
            << ", x4 = " << x4
            << "\n";
    // clang-format on

    // Run the solver!
    ceres::Solver::Summary summary;
    ceres::Solve(options, &problem, &summary);

    std::cout << summary.FullReport() << "\n";
    // clang-format off
    std::cout << "Final x1 = " << x1
            << ", x2 = " << x2
            << ", x3 = " << x3
            << ", x4 = " << x4
            << "\n";
    // clang-format on
    return 0;
}