#include "simulation.hpp"

int main() {
    Simulation simulation;
    simulation.run();
    simulation.saveResults();
   // simulation.visualizeResults(); // Call the new visualization method

    return 0;
}