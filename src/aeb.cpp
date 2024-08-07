#include "aeb.hpp"
#include <cmath>
#include "utils.hpp"

AEB::AEB() {}

std::vector<double> AEB::predictPath(double current_speed, double time_horizon) {
    current_speed = utils::convertKmphToMps(current_speed);
    std::vector<double> path;
    double time_step = 0.1;
    for (double t = 0.0; t <= time_horizon; t += time_step) {
        path.push_back(current_speed * t);
    }
    return path;
}

bool AEB::shouldBrake(double current_speed, double distance_to_obstacle) {
    current_speed = utils::convertKmphToMps(current_speed);
    double time_horizon = 2.0; // Predict the path for the next 2 seconds
    std::vector<double> path = predictPath(current_speed, time_horizon);
    
    for (double position : path) {
        if (position >= distance_to_obstacle) {
            return true;
        }
    }
    return false;
}