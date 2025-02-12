#include <iostream>
#include <filesystem>
#include <chrono>
#include <ceres/ceres.h>
#include "yaml-cpp/yaml.h"
#include "DataGeneration.h"
#include "Problems.h"

int main(int argc, char **argv)
{
    // Initialize data
    std::vector<double> x_data, y_data;

    std::string file = std::filesystem::current_path().string() + "/config/example.yaml";
    GenerateData(file, x_data, y_data);

    // Load Configuration
    YAML::Node node = YAML::LoadFile(file);
    int num_data = node["NUM_Data"].as<int>();
    double ae = node["Estimated"]["a"].as<double>();
    double be = node["Estimated"]["b"].as<double>();
    double ce = node["Estimated"]["c"].as<double>();
    double abc[3] = {ae, be, ce};                   // 估计参数值

    ceres::Problem problem_1;
    for (int i=0;i<num_data;i++){
        ceres::CostFunction *cost_function =
            new ceres::AutoDiffCostFunction<Problem::CURVE_FITTING_COST,1,3>(
                new Problem::CURVE_FITTING_COST(x_data[i], y_data[i])
            );
        problem_1.AddResidualBlock(cost_function, nullptr, abc);
    }

    // Run the solver
    ceres::Solver::Options options;
    options.linear_solver_type = ceres::DENSE_QR;
    options.minimizer_progress_to_stdout = true;

    ceres::Solver::Summary summary;
    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
    ceres::Solve(options, &problem_1, &summary);
    std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> time_used = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    std::cout << "solve time cost = " << time_used.count() << " seconds. " << std::endl;

    std::cout << summary.FullReport() << "\n";
    return 0;
}