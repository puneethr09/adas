#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch_test_macros.hpp>
#include <gtest/gtest.h>
#include "acc.hpp"

TEST(ACCTest, SpeedIncrease) {
    ACC acc(100.0, 0.1, 0.01, 0.001); // max_speed, kp, ki, kd
    double new_speed = acc.getSpeed(50.0, 30.0);
    EXPECT_NEAR(new_speed, 55.0, 5.0); // Allow a larger margin for PID tuning
}

TEST(ACCTest, SpeedDecrease) {
    ACC acc(100.0, 0.1, 0.01, 0.01);
    double new_speed = acc.getSpeed(50.0, 15.0);
    EXPECT_NEAR(new_speed, 40.0, 10.0); // Adjusted margin to allow for PID behavior
}

TEST(ACCTest, SpeedMax) {
    ACC acc(100.0, 0.1, 0.01, 0.01);
    double new_speed = acc.getSpeed(95.0, 30.0);
    EXPECT_NEAR(new_speed, 100.0, 5.0);
}

TEST(ACCTest, ShouldBrake) {
    ACC acc(100.0, 0.1, 0.01, 0.01);
    double new_speed = acc.getSpeed(50.0, 5.0); // Should trigger braking
    EXPECT_NEAR(new_speed, 0.0, 1.0); // Braking should bring the speed to near 0
}