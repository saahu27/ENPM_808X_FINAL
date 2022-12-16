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
 * @file tb3controller.cpp
 * @author Sahruday Patti, Vishaal Sivakumar
 * @brief Illustration of walker algorithm
 * @version 0.1
 * @date 2022-11-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/LinearMath/Quaternion.h>

#include <geometry_msgs/msg/transform_stamped.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <string>
#include <utility>
#include <vector>

#include "tf2/exceptions.h"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"

using std::placeholders::_1;
using namespace std::chrono_literals;

class tb3 : public rclcpp::Node {
 public:
  tb3(const std::string node_name = "tb3",
      const std::string robot_name = "robot", bool go_to_goal = true,
      double linear_speed = 0.5, double angular_speed = 0.1,
      bool go_to_angle = true)
      : Node(node_name),
        m_robot_name{robot_name},
        m_goal_x{0.0},
        m_goal_y{0.0},
        m_go_to_goal{go_to_goal},
        m_linear_speed{linear_speed},
        m_angular_speed{angular_speed},
        m_roll{0},
        m_pitch{0},
        m_yaw{0},
        m_kv{1},
        m_kh{1},
        m_go_to_angle{go_to_angle},
        m_distance_to_goal{1.0}

  {
    // remmeber robot initial spawning location.
    auto current_location = std::make_pair<double, double>(3.0, 0.0);
    m_location = current_location;  // initilizing current location with double
                                    // pointer 3.0,0.0
    m_cbg = this->create_callback_group(
        rclcpp::CallbackGroupType::MutuallyExclusive);

    auto command_topic_name = "/cmd_vel";
    auto pose_topic_name = "/odom";

    RCLCPP_INFO_STREAM(this->get_logger(), "tb3controller Constructor");

    m_publisher_cmd_vel = this->create_publisher<geometry_msgs::msg::Twist>(
        command_topic_name, 10);

    m_parent_frame = "odom";
    m_child_frame = "base_footprint";

    /* time delay between nodes*/
    m_tf_buffer = std::make_unique<tf2_ros::Buffer>(this->get_clock());
    m_tf_listener = std::make_shared<tf2_ros::TransformListener>(*m_tf_buffer);

    // Call on_timer function 5 times per second
    m_transform_timer = this->create_wall_timer(
        std::chrono::milliseconds((int)(1000.0 / 5)),
        std::bind(&tb3::transform_callback, this), m_cbg);
    m_go_to_goal_timer = this->create_wall_timer(
        std::chrono::milliseconds((int)(1000.0 / 1)),
        std::bind(&tb3::go_to_goal_callback, this), m_cbg);
  }
  /**
   * @brief Set the goal to reach.
   *
   * @param go_to_goal Flag used to perform a transform listener
   * @param x x-coordinate of the goal position.
   * @param y y-coordinate of the goal position.
   */
  void set_goal(std::vector<std::vector<float>> goals_) {
    m_go_to_goal = true;
    m_go_to_angle = true;

    m_goal_x = goals_[goals_.size() - 1][0];
    m_goal_y = goals_[goals_.size() - 1][1];
    m_goal_orientation = goals_[goals_.size() - 1][2];

    goals_.pop_back();
    goals = goals_;
    RCLCPP_INFO_STREAM(this->get_logger(), "Going to goal: [" << m_goal_x << ","
                                                              << m_goal_y
                                                              << "]");
  }

  void stop();

 private:
  double m_goal_x = 5.0;
  double m_goal_y = 0.0;
  std::string m_robot_name;
  double m_linear_speed;
  double m_angular_speed;
  double m_roll;   // rad
  double m_pitch;  // rad
  double m_yaw;    // rad
  double m_distance_to_goal;
  double m_kv;  // gain for linear velocity
  double m_kh;  // gain for angular velocity

  double m_goal_orientation;
  bool m_go_to_goal;
  bool m_go_to_angle;
  std::vector<std::vector<float>> goals;

  rclcpp::CallbackGroup::SharedPtr m_cbg;
  rclcpp::TimerBase::SharedPtr m_timer;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr m_publisher_cmd_vel;

  std::string m_parent_frame;
  std::string m_child_frame;
  std::pair<double, double> m_location;
  geometry_msgs::msg::Quaternion m_orientation;
  rclcpp::TimerBase::SharedPtr m_transform_timer;
  rclcpp::TimerBase::SharedPtr m_go_to_goal_timer;
  // rclcpp::TimerBase::SharedPtr m_move_in_circle_timer;
  std::shared_ptr<tf2_ros::TransformListener> m_tf_listener;
  std::unique_ptr<tf2_ros::Buffer> m_tf_buffer;

  /**
   * @brief Compute the distance between two points.
   *
   * @param a The first point.
   * @param b The second point.
   * @return double   The distance between a and b.
   */
  double compute_distance(const std::pair<double, double> &a,
                          const std::pair<double, double> &b);

  /**
   * @brief Callback function for the robot3 pose.
   *
   * @param msg Odometry message.
   */
  // void robot_pose_callback(const nav_msgs::msg::Odometry::SharedPtr msg);

  /**
   * @brief Normalizes the angle to be 0 to 2*M_PI
   *
   * @param angle Angle to normalize (rad)
   * @return double Normalized angle (rad)
   */
  double normalize_angle_positive(double angle);

  /**
   * @brief Normalizes the angle to be -M_PI circle to +M_PI circle
   *
   * @param angle Angle to normalize (rad)
   * @return double Normalized angle (rad)
   */
  double normalize_angle(double angle);

  /**
   * @brief Subscribes to tf topic and updates current pose
   */
  void transform_callback();

  /**
   * @brief checks the distance to goal and moves towards it
   */
  void go_to_goal_callback();

  /**
   * @brief converts to quaternion to euler and gives yaw.
   * @return double yaw angle (rad)
   */
  double compute_yaw_from_quaternion();

  /**
   * @brief publisher velocity commands to turtlebot to movea
   *
   * @param linear  linear velocity
   * @param angular angular velocity
   * @return double Normalized angle (rad)
   */
  void move_tb3(double linear, double angular);
};
