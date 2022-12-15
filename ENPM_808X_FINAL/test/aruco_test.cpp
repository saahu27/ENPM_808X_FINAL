// Copyright Sahruday
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file aruco_test.cpp
 * @author Sahruday Patti, Vishaal Sivakumar
 * @brief Test cases to test aruco detection
 * @version 0.1
 * @date 2022-12-15
 *
 * @copyright Copyright (c) 2022
 *
 */
 
#include <rclcpp/rclcpp.hpp>
#include <gtest/gtest.h>
#include <stdlib.h>

#include <std_msgs/msg/string.hpp>
#include "../include/tb3/turtlebot_sim.hpp"

class Test_aruco : public testing::Test {
 protected:
  rclcpp::Node::SharedPtr node_;
};

TEST_F(Test_aruco, test_num_subscribers) {
  node_ = rclcpp::Node::make_shared("test_ar_detect");
  auto test_pub = node_->create_publisher<std_msgs::msg::String>
                    ("Test_aruco_task", 10.0);

  auto num_pub = node_->count_publishers("Test_aruco_task");
  EXPECT_EQ(1, static_cast<int>(num_pub));
}
