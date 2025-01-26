#include <iostream>
#include <filesystem>
// #include <Eigen/Dense>
#include <ceres/ceres.h>
#include "DataGeneration.h"
#include "Problems.h"

int main(int argc, char **argv)
{
    // Initialize data
    std::vector<double> x_data, y_data;

    std::string file = std::filesystem::current_path().string() + "/config/example.yaml";
    GenerateData(file, x_data, y_data);

    ceres::Problem problem_1;
    double initial_x = 5.0;
    double x = initial_x;
    ceres::CostFunction *cost_function =
        new ceres::AutoDiffCostFunction<Problem::Quad_Minimum, 1, 1>(
            new Problem::Quad_Minimum);
    problem_1.AddResidualBlock(cost_function, nullptr, &x);

    // Run the solver
    ceres::Solver::Options options;
    options.linear_solver_type = ceres::DENSE_QR;
    options.minimizer_progress_to_stdout = true;
    ceres::Solver::Summary summary;
    ceres::Solve(options, &problem_1, &summary);
    std::cout << summary.FullReport() << "\n";
    std::cout << "Initial x: " << initial_x << "\n";
    std::cout << "Final   x: " << x << "\n";
    return 0;
}