#include <gtest/gtest.h>
#include "simulation.hpp"

TEST(SimulationTest, RunSimulation) {
    Simulation simulation;
    simulation.run();
    simulation.saveResults();
    // Add checks for the saved HDF5 file if necessary
}