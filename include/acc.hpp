#ifndef ACC_HPP
#define ACC_HPP

class ACC {
public:
    ACC(double max_speed, double kp, double ki, double kd);
    double getSpeed(double current_speed, double distance_to_vehicle);
private:
    double max_speed;
    double kp, ki, kd;
    double integral, previous_error;
};

#endif // ACC_H