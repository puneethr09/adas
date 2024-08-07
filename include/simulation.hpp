#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <vector>

class Simulation {
public:
    Simulation();
    void run();
    void saveResults();
   // void visualizeResults(); // Add this line

private:
    std::vector<double> times;
    std::vector<double> speeds;
    std::vector<double> distances;
};

#endif // SIMULATION_HPP