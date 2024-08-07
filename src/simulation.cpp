#include "simulation.hpp"
#include <highfive/H5File.hpp>
#include "acc.hpp"
#include "aeb.hpp"
#include <iostream>
#include <vector>
//#include <matplotlibcpp.h> // Include matplotlib-cpp header

//namespace plt = matplotlibcpp;

Simulation::Simulation() {}

void Simulation::run() {
    ACC acc(100.0, 0.1, 0.01, 0.01); // Example PID parameters
    AEB aeb;
    double current_speed = 0.0;
    double distance_to_vehicle = 50.0;

    for (double time = 0.0; time <= 60.0; time += 1.0) {
        current_speed = acc.getSpeed(current_speed, distance_to_vehicle);
        if (aeb.shouldBrake(current_speed, distance_to_vehicle)) {
            current_speed = 0.0;
        }
        times.push_back(time);
        speeds.push_back(current_speed);
        distances.push_back(distance_to_vehicle);
        distance_to_vehicle -= 5.0;
    }
}

void Simulation::saveResults() {
    HighFive::File file("simulation_results.h5", HighFive::File::Overwrite);
    file.createDataSet("times", times);
    file.createDataSet("speeds", speeds);
    file.createDataSet("distances", distances);
}

// void Simulation::visualizeResults() {
//     plt::figure_size(1200, 780);

//     // Plot speed over time
//     plt::subplot(2, 1, 1);
//     plt::title("Speed over Time");
//     plt::plot(times, speeds, "b-");
//     plt::xlabel("Time (s)");
//     plt::ylabel("Speed (km/h)");

//     // Plot distance to vehicle over time
//     plt::subplot(2, 1, 2);
//     plt::title("Distance to Vehicle over Time");
//     plt::plot(times, distances, "r-");
//     plt::xlabel("Time (s)");
//     plt::ylabel("Distance to Vehicle (m)");

//     plt::save("simulation_results.png");
//     plt::show();
// }