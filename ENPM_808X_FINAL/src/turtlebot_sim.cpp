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
 * @file turtlebot_sim.cpp
 * @author Sahruday Patti, Vishaal Sivakumar
 * @brief Aruco count module
 * @version 0.1
 * @date 2022-12-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/tb3/turtlebot_sim.hpp"

using std::placeholders::_1;

void MinimalSubscriber::topic_callback(
    const tutorial_interfaces::msg::Num::SharedPtr msg) {
  if (abs(static_cast<float>(ang)) <= 0.0001 &&
      abs(static_cast<float>(lin_x)) <= 0.0001 &&
      abs(static_cast<float>(lin_y)) <= 0.0001) {
    for (size_t i = 0; i < msg->poses.size(); i++) {
      if (flag[msg->marker_ids[i]] != -1) {
        auto pose = msg->poses[i];

        x[msg->marker_ids[i]] = pose.position.x;
        y[msg->marker_ids[i]] = pose.position.y;
        z[msg->marker_ids[i]] = pose.position.z;

        id[msg->marker_ids[i]]++;
        RCLCPP_INFO(this->get_logger(), "Product 1 count: '%d'", id[0]);
        RCLCPP_INFO(this->get_logger(), "Product 2 count: '%d'", id[1]);
        RCLCPP_INFO(this->get_logger(), "Product 3 count: '%d'", id[2]);
        RCLCPP_INFO(this->get_logger(), "Product 4 count: '%d'", id[3]);

        x_prev[msg->marker_ids[i]] = x[msg->marker_ids[i]];
        y_prev[msg->marker_ids[i]] = y[msg->marker_ids[i]];
        z_prev[msg->marker_ids[i]] = z[msg->marker_ids[i]];

        if (i == msg->poses.size() - 1) {
          flag[msg->marker_ids[i]] = -1;
        }
      }
    }
  }
}
void MinimalSubscriber::robot_pose_callback(
    const nav_msgs::msg::Odometry::SharedPtr pose_msg) {
  ang = pose_msg->twist.twist.angular.z;
  lin_x = pose_msg->twist.twist.linear.x;
  lin_y = pose_msg->twist.twist.linear.y;
}

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
