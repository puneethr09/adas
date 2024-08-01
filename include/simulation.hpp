#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <vector>

class Simulation {
public:
    Simulation();
    void run();
    void saveResults();
private:
    std::vector<double> times;
    std::vector<double> speeds;
};

#endif // SIMULATION_H