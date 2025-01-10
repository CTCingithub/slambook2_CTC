#ifndef ITERATION_H
#define ITERATION_H

#include <iostream>
#include <chrono>
#include <Eigen/Core>
#include <Eigen/Dense>
#include "yaml-cpp/yaml.h"

Eigen::Vector3d GaussNewtonIterator(std::string &config, std::vector<double> &x_data, std::vector<double> &y_data);

#endif