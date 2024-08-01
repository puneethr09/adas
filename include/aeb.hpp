#ifndef AEB_HPP
#define AEB_HPP

#include <vector>

class AEB {
public:
    AEB();
    bool shouldBrake(double current_speed, double distance_to_obstacle);
private:
    std::vector<double> predictPath(double current_speed, double time_horizon);
};

#endif // AEB_H