#ifndef ACC_HPP
#define ACC_HPP

#include "aeb.hpp"

class ACC {
public:
    ACC(double max_speed, double kp, double ki, double kd);
    double getSpeed(double current_speed, double distance_to_vehicle);
private:
    double max_speed;
    double kp, ki, kd;
    double integral, previous_error, max_integral;
    AEB aeb;
};

#endif // ACC_H