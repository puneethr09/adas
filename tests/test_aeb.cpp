#include "aeb.hpp"
#include <gtest/gtest.h>

TEST(AEBTest, BrakeRequired) {
    AEB aeb;
    EXPECT_TRUE(aeb.shouldBrake(50.0, 5.0));
}

TEST(AEBTest, NoBrakeRequired) {
    AEB aeb;
    EXPECT_FALSE(aeb.shouldBrake(50.0, 50.0));
}