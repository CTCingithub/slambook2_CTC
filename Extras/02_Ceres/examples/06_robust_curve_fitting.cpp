#include "ceres/ceres.h"
#include "glog/logging.h"
#include "curve_fitting_residual.h"
#include "curve_data.h"

int main(int argc, char **argv)
{
    google::InitGoogleLogging(argv[0]);

    // ��ֵ
    double m = 0.0;
    double c = 0.0;

    ceres::Problem problem;
    for (int i = 0; i < kNumObservations; i++)
    {
        ceres::CostFunction *cost_function =
            new ceres::AutoDiffCostFunction<ExponentialResidual, 1, 1, 1>(
                new ExponentialResidual(data[2 * i], data[2 * i + 1]));
        // ���һ���в�鵽������
        problem.AddResidualBlock(
            // �в��ʹ�õĳɱ����������ڼ���в�
            cost_function,
            // ��ʧ���������ڴ��� outliers���쳣ֵ��������ʹ�õ��� Cauchy ��ʧ����
            // CauchyLoss �Ĳ�������ʧ��ֵ��������Ϊ 0.5
            new ceres::CauchyLoss(0.5),
            // �������ָ�룬���ﴫ������������ m �� c ��ָ��
            // ��Щ���������Ż������б���������С���в�
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
