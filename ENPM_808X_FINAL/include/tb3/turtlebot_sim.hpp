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
 * @file turtlebot_sim.hpp
 * @author Sahruday Patti, Vishaal Sivakumar
 * @brief Aruco count module
 * @version 0.1
 * @date 2022-12-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/LinearMath/Quaternion.h>

#include <geometry_msgs/msg/transform_stamped.hpp>
#include <memory>

#include "nav_msgs/msg/odometry.hpp"
#include "rclcpp/rclcpp.hpp"
#include "tf2/exceptions.h"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "tutorial_interfaces/msg/num.hpp"

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node {
 public:
  MinimalSubscriber() : Node("minimal_subscriber") {
    subscription2_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "odom", 10,
        std::bind(&MinimalSubscriber::robot_pose_callback, this, _1));

    subscription_ = this->create_subscription<tutorial_interfaces::msg::Num>(
        "aruco_markers", 10,
        std::bind(&MinimalSubscriber::topic_callback, this, _1));
    for (int i = 0; i < 4; i++) {
      id[i] = 0;
      x[i] = 0;
      y[i] = 0;
      z[i] = 0;
      x_prev[i] = -100;
      y_prev[i] = -100;
      z_prev[i] = -100;
      flag[i] = 0;
    }
  }

 private:
  /**
   * @brief subscribes to aruco-markers reads if aruco is in frame
   * @return updates the tutorial_interfaces::msg::Num
   */
  void topic_callback(const tutorial_interfaces::msg::Num::SharedPtr msg);

  /**
   * @brief subscribes to odom and updates robot current pose
   */
  void robot_pose_callback(const nav_msgs::msg::Odometry::SharedPtr pose_msg);

  rclcpp::Subscription<tutorial_interfaces::msg::Num>::SharedPtr subscription_;
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subscription2_;

  int id[4];
  float x[4], y[4], z[4];
  float x_prev[4], y_prev[4], z_prev[4];

  float lin_x, lin_y, ang;
  int flag[4];
};
