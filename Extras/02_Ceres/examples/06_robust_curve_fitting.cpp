#include "ceres/ceres.h"
#include "glog/logging.h"
#include "curve_fitting_residual.h"
#include "curve_data.h"

int main(int argc, char **argv)
{
    google::InitGoogleLogging(argv[0]);

    // 初值
    double m = 0.0;
    double c = 0.0;

    ceres::Problem problem;
    for (int i = 0; i < kNumObservations; i++)
    {
        ceres::CostFunction *cost_function =
            new ceres::AutoDiffCostFunction<ExponentialResidual, 1, 1, 1>(
                new ExponentialResidual(data[2 * i], data[2 * i + 1]));
        // 添加一个残差块到问题中
        problem.AddResidualBlock(
            // 残差块使用的成本函数，用于计算残差
            cost_function,
            // 损失函数，用于处理 outliers（异常值），这里使用的是 Cauchy 损失函数
            // CauchyLoss 的参数是损失阈值，这里设为 0.5
            new ceres::CauchyLoss(0.5),
            // 参数块的指针，这里传递了两个参数 m 和 c 的指针
            // 这些参数将在优化过程中被调整以最小化残差
            &m, &c);
    }

    ceres::Solver::Options options;
    options.linear_solver_type = ceres::DENSE_QR;
    options.minimizer_progress_to_stdout = true;

    ceres::Solver::Summary summary;
    ceres::Solve(options, &problem, &summary);

    std::cout << summary.BriefReport() << "\n";
    std::cout << "Initial m: " << 0.0
              << ", c: " << 0.0 << std::endl;
    std::cout << "Final   m: " << m
              << ", c: " << c << std::endl;
}
