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
#include <rclcpp/rclcpp.hpp>
#include <gtest/gtest.h>
#include <stdlib.h>

#include <std_msgs/msg/string.hpp>
#include "../include/tb3/tb3controller.hpp"

class Test_controller : public testing::Test {
 protected:
  rclcpp::Node::SharedPtr node_;
};

TEST_F(Test_controller, test_num_subscribers) {
  node_ = rclcpp::Node::make_shared("test_control");
  auto test_pub = node_->create_publisher<std_msgs::msg::String>
                    ("Test_controller_task", 10.0);

  auto num_pub = node_->count_publishers("Test_controller_task");
  EXPECT_EQ(1, static_cast<int>(num_pub));
}
