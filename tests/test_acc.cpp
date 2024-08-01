#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch_test_macros.hpp>
#include <gtest/gtest.h>
#include "acc.hpp"

TEST(ACCTest, SpeedIncrease) {
    ACC acc(100.0, 0.1, 0.01, 0.01);
    EXPECT_NEAR(acc.getSpeed(50.0, 30.0), 55.0, 1.0);
}

TEST(ACCTest, SpeedDecrease) {
    ACC acc(100.0, 0.1, 0.01, 0.01);
    EXPECT_NEAR(acc.getSpeed(50.0, 15.0), 40.0, 5.0);
}

TEST(ACCTest, SpeedMax) {
    ACC acc(100.0, 0.1, 0.01, 0.01);
    EXPECT_NEAR(acc.getSpeed(95.0, 30.0), 100.0, 5.0);
}