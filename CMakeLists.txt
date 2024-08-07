# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(adas)

# C++ standard and build type
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g")

# Include directories
include_directories(include)
include_directories(include/highfive)

# Add source files
file(GLOB SOURCES "src/*.cpp")

# Add the main executable
add_executable(adas ${SOURCES})

# Manually specify the paths for HDF5
set(HDF5_ROOT "/opt/homebrew/opt/hdf5")
find_package(HDF5 REQUIRED)
include_directories(${HDF5_INCLUDE_DIRS})
link_directories(${HDF5_LIBRARY_DIRS})

# Link HDF5 libraries
target_link_libraries(adas ${HDF5_LIBRARIES})

# Add Catch2 for unit tests
add_subdirectory(externals/Catch2)
include_directories(${CMAKE_SOURCE_DIR}/externals/Catch2/src)

# Add GTest for unit tests
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
link_directories(${GTEST_LIBRARY_DIRS})

# Manually add NumPy include path
# Updated path for numpy
execute_process(
    COMMAND python3 -c "import numpy; print(numpy.get_include())"
    OUTPUT_VARIABLE NUMPY_INCLUDE_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
include_directories(${NUMPY_INCLUDE_DIR})

# Find Python3
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
include_directories(${Python3_INCLUDE_DIRS})

# Add all test source files
set(TEST_SOURCES
    tests/test_acc.cpp
    tests/test_aeb.cpp
    tests/test_simulation.cpp
    src/acc.cpp
    src/aeb.cpp
    src/simulation.cpp
)

# Add the test executable
add_executable(run_tests ${TEST_SOURCES})
target_link_libraries(run_tests ${HDF5_LIBRARIES} Catch2::Catch2 GTest::GTest GTest::Main ${Python3_LIBRARIES})

# Enable testing and Catch2 test discovery
include(CTest)
include(Catch)
# catch_discover_tests(run_tests)

# Enable testing
enable_testing()
add_test(NAME run_tests COMMAND run_tests)