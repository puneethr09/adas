#include "acc.hpp"

ACC::ACC(double max_speed, double kp, double ki, double kd)
    : max_speed(max_speed), kp(kp), ki(ki), kd(kd), integral(0.0), previous_error(0.0) {}

double ACC::getSpeed(double current_speed, double distance_to_vehicle) {
    double target_speed = (distance_to_vehicle < 20.0) ? 0.0 : max_speed;
    double error = target_speed - current_speed;
    integral += error;
    double derivative = error - previous_error;

    double output = kp * error + ki * integral + kd * derivative;
    previous_error = error;

    return current_speed + output;
}