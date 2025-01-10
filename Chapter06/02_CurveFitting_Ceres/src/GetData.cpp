#include <iostream>
#include <fstream>
#include "yaml-cpp/yaml.h"
#include "opencv2/opencv.hpp"

void GenerateData(std::string &config, std::vector<double> &x, std::vector<double> &y)
{
    std::cout << "Generating data..." << std::endl;

    // Load Configuration
    YAML::Node node = YAML::LoadFile(config);
    int num_data = node["NUM_Data"].as<int>();
    double ar = node["Real"]["a"].as<double>();
    double br = node["Real"]["b"].as<double>();
    double cr = node["Real"]["c"].as<double>();
    double w_sigma = node["w_sigma"].as<double>();

    // Random value generation with OpenCV
    cv::RNG rng;
    for (int i = 0; i < num_data; i++)
    {
        double x_temp = i / 100.0;
        x.push_back(x_temp);
        y.push_back(exp(ar * x_temp * x_temp + br * x_temp + cr) + rng.gaussian(w_sigma));
    }
}
