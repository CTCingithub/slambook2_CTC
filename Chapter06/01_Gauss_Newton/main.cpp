#include <iostream>
#include <filesystem>
#include "DataGeneration.h"
#include "Iteration.h"

int main(int argc, char **argv)
{
    // Initialize data
    std::vector<double> x_data, y_data;

    std::string file = std::filesystem::current_path().string() + "/config/example.yaml";
    GenerateData(file, x_data, y_data);

    // Start Gauss-Newton iteration
    int num_iterations = 100;
    double cost = 0, lastCost = 0;

    // double ae, be, ce;
    Eigen::Vector3d temp = GaussNewtonIterator(file, x_data, y_data);
    std::cout << "\n a_e = " << temp[0] << "\n b_e = " << temp[1] << "\n c_e = " << temp[2] << std::endl;

    return 0;
}