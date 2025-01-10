#include <iostream>
#include <chrono>
#include <Eigen/Core>
#include <Eigen/Dense>
#include "yaml-cpp/yaml.h"

Eigen::Vector3d GaussNewtonIterator(std::string &config, std::vector<double> &x_data, std::vector<double> &y_data)
{
    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
    std::cout << "Start Gauss-Newton Iterator" << std::endl;

    // Load Configuration
    YAML::Node node = YAML::LoadFile(config);
    int num_data = node["NUM_Data"].as<int>();
    int num_iteration = node["iterations"].as<int>();
    double w_sigma = node["w_sigma"].as<double>();
    double ae = node["Estimated"]["a"].as<double>();
    double be = node["Estimated"]["b"].as<double>();
    double ce = node["Estimated"]["c"].as<double>();
    double inv_sigma = 1.0 / w_sigma;

    // Gauss-Newton Iterator
    double cost = 0, LastCost = 0;
    for (int iter = 0; iter < num_iteration; iter++)
    {
        // Hessian Matrix H = J^T W^{-1} J
        Eigen::Matrix3d H = Eigen::Matrix3d::Zero();
        // bias
        Eigen::Vector3d b = Eigen::Vector3d::Zero();
        cost = 0;

        // Obtain total cost in current iteration
        for (int i = 0; i < num_data; i++)
        {
            double xi = x_data[i], yi = y_data[i]; // The i-th data
            double error = yi - exp(ae * xi * xi + be * xi + ce);
            Eigen::Vector3d J;
            J[0] = -xi * xi * exp(ae * xi * xi + be * xi + ce); // de/da
            J[1] = -xi * exp(ae * xi * xi + be * xi + ce);      // de/db
            J[2] = -exp(ae * xi * xi + be * xi + ce);           // de/dc

            H += inv_sigma * inv_sigma * J * J.transpose();
            b += -inv_sigma * inv_sigma * error * J;

            cost += error * error;
        }

        // Linear Solve Hx = b
        Eigen::Vector3d dx = H.ldlt().solve(b);
        if (std::isnan(dx[0]))
        {
            std::cout << "result is nan!" << std::endl;
            break;
        }

        if (iter > 0 && cost >= LastCost)
        {
            std::cout << "cost: " << cost << ">= last cost: " << LastCost << ", break." << std::endl;
            break;
        }

        ae += dx[0];
        be += dx[1];
        ce += dx[2];

        LastCost = cost;
        std::cout << "iter: " << iter + 1 << "/" << num_iteration << ", cost: " << cost << std::endl;
        std::cout << "update: " << dx.transpose() << std::endl;
        std::cout << "estimated params: " << ae << "," << be << "," << ce << std::endl;
    }

    std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> time_used = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    std::cout << "\nDuration: " << time_used.count() << " seconds." << std::endl;
    return Eigen::Vector3d(ae, be, ce);
}