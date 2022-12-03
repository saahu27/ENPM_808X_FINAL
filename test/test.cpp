/**
 * @file test.cpp
 * @author Sahruday Patti (sahruday@umd.edu)
 * @brief
 * @version 0.1
 * @date 2022-10-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <gtest/gtest.h>

#include <iostream>

#include "../src/Planning/include/pid.hpp"

controller::PID PIDController;

TEST(ControllerComputeTest_increasing, should_pass) {
  EXPECT_NEAR(PIDController.RunController(10), 10, 0.1);
}
