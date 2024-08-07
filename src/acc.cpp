#include "utils.hpp"
#include "acc.hpp"

ACC::ACC(double max_speed, double kp, double ki, double kd)
    : max_speed(utils::convertKmphToMps(max_speed)), kp(kp), ki(ki), kd(kd), integral(0.0), previous_error(0.0), max_integral(10.0) {}

double ACC::getSpeed(double current_speed, double distance_to_vehicle) {
    current_speed = utils::convertKmphToMps(current_speed);

    // Validate input parameters
    if (current_speed < 0.0) {
        current_speed = 0.0;
    }

    if (distance_to_vehicle < 0.0) {
        distance_to_vehicle = 0.0;
    }

    // Check if AEB should engage
    if (aeb.shouldBrake(current_speed, distance_to_vehicle)) {
        return 0.0; // Immediate braking
    }

    // Improved target speed calculation
    double target_speed;
    if (distance_to_vehicle < 5.0) {
        target_speed = 0.0;
    } else if (distance_to_vehicle < 20.0) {
        target_speed = max_speed * (distance_to_vehicle / 20.0);
    } else {
        target_speed = max_speed;
    }

    double error = target_speed - current_speed;
    integral += error;

    // Prevent integral windup
    if (integral > max_integral) {
        integral = max_integral;
    } else if (integral < -max_integral) {
        integral = -max_integral;
    }

    double derivative = error - previous_error;
    previous_error = error;

    // Apply PID control
    double output = kp * error + ki * integral + kd * derivative;

    // Calculate new speed and ensure it is within bounds
    double new_speed = current_speed + output;
    new_speed = std::min(std::max(new_speed, 0.0), max_speed);

    return utils::convertMpsToKmph(new_speed);
}