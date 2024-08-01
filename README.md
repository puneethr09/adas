# adas

# ADAS

This project simulates an Advanced Driver Assistance System (ADAS) with Adaptive Cruise Control (ACC) and Autonomous Emergency Braking (AEB). It uses PID control for ACC and polynomial path prediction for AEB. The results of the simulation are saved in HDF5 format.

## Project Structure

/ADAS
├── /include
│ ├── ACC.h
│ ├── AEB.h
│ ├── Simulation.h
├── /src
│ ├── ACC.cpp
│ ├── AEB.cpp
│ ├── Simulation.cpp
│ └── main.cpp
├── /tests
│ ├── test_ACC.cpp
│ ├── test_AEB.cpp
│ ├── test_Simulation.cpp
├── CMakeLists.txt
├── README.md
├── LICENSE
└── .gitignore

## Dependencies

- **Google Test** for unit testing.
- **HighFive** for HDF5 support.
- **SFML** for visualization (optional).

### Installing Dependencies

1. **Google Test:**

   ```sh
   sudo apt-get install libgtest-dev
   cd /usr/src/gtest
   sudo cmake CMakeLists.txt
   sudo make
   sudo cp *.a /usr/lib

   ```

2. **HighFive:**
   Follow the HighFive installation instructions.

3. **SFML (optional):**
   sudo apt-get install libsfml-dev

#### Project Components

# Adaptive Cruise Control (ACC)

The ACC uses a PID controller to maintain a desired speed. The speed is adjusted based on the distance to the vehicle ahead.

# Autonomous Emergency Braking (AEB)

The AEB uses polynomial path prediction to determine if the vehicle should brake. It predicts the vehicle’s path over a time horizon and checks if it intersects with any obstacles.

# Simulation

The simulation runs for a set period, adjusting the vehicle’s speed using ACC and deciding when to brake using AEB. The results are saved in HDF5 format.

# Saving Results

The simulation results are saved in an HDF5 file named simulation_results.h5. The file contains two datasets: times and speeds, representing the time steps and corresponding speeds during the simulation.

# Extending the Project

This project can be extended by adding more features, such as:

    •	Improved simulation accuracy
    •	Enhanced user interface and visualization
    •	Additional ADAS features
