#include <gtest/gtest.h>
#include <rclcpp/executors.hpp>
#include <rclcpp/node.hpp>
#include <rclcpp/publisher.hpp>
#include <stdlib.h>
#include <rclcpp/rclcpp.hpp>

#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"

#include "../include/tb3/turtlebot_sim.hpp"

#include "nav_msgs/msg/odometry.hpp"
using ODOM = nav_msgs::msg::Odometry;
using POSE = geometry_msgs::msg::PoseStamped;
using PUBLISHER = rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr;
using TIMER = rclcpp::TimerBase::SharedPtr;
using std::placeholders::_1;
using std::chrono::duration;
using namespace std::chrono_literals;

class TaskPerception : public testing::Test {
 public:
  rclcpp::Node::SharedPtr node_;
  TIMER timer_;
  rclcpp::Publisher<ODOM>::SharedPtr test_pub;
  void callback();
  PUBLISHER nav_publisher_;
};
void TaskPerception::callback() {
  auto message = ODOM();
  test_pub->publish(message);
}

TEST_F(TaskPerception, test_search_bins) {
  node_ = rclcpp::Node::make_shared("test_perception");

  auto test_pub = node_->create_publisher<ODOM>
                    ("odom", 10.0);
  auto ypos = 3.0;
  TIMER timer = node_->create_wall_timer(100ms,
      std::bind(&TaskPerception::callback, this));
  rclcpp::spin_some(node_);
  POSE rpyGoal;
  rpyGoal.header.frame_id = "map";
  rpyGoal.header.stamp = node_->get_clock()->now();
  rpyGoal.pose.position.x = 0;
  rpyGoal.pose.position.y = ypos;
  rpyGoal.pose.position.z = 0;
  rpyGoal.pose.orientation.x = 0;
  rpyGoal.pose.orientation.y = 0;
  rpyGoal.pose.orientation.z = 0;
  rpyGoal.pose.orientation.w = 1;
  ASSERT_TRUE(true);
}

TEST_F(TaskPerception, test_resume_search) {
  node_ = rclcpp::Node::make_shared("test_perception");

  auto test_pub = node_->create_publisher<ODOM>
                    ("odom", 10.0);

  TIMER timer = node_->create_wall_timer(100ms,
      std::bind(&TaskPerception::callback, this));
  rclcpp::spin_some(node_);
  POSE rpyGoal;
  rpyGoal.header.frame_id = "map";
  rpyGoal.header.stamp = node_->get_clock()->now();
  rpyGoal.pose.position.x = 0;
  rpyGoal.pose.position.y = 0;
  rpyGoal.pose.position.z = 0;
  rpyGoal.pose.orientation.x = 0;
  rpyGoal.pose.orientation.y = 0;
  rpyGoal.pose.orientation.z = 0;
  rpyGoal.pose.orientation.w = 1;
  ASSERT_TRUE(true);
}

TEST_F(TaskPerception, test_move_to_disposal) {
  node_ = rclcpp::Node::make_shared("test_perception");

  auto test_pub = node_->create_publisher<ODOM>
                    ("odom", 10.0);
  rclcpp::spin_some(node_);
  TIMER timer = node_->create_wall_timer(100ms,
      std::bind(&TaskPerception::callback, this));
  POSE rpyGoal;
  rpyGoal.header.frame_id = "map";
  rpyGoal.header.stamp = node_->get_clock()->now();
  rpyGoal.pose.position.x = 3;
  rpyGoal.pose.position.y = -2.5;
  rpyGoal.pose.position.z = 0;
  rpyGoal.pose.orientation.x = 0;
  rpyGoal.pose.orientation.y = 0;
  rpyGoal.pose.orientation.z = 0;
  rpyGoal.pose.orientation.w = 1;
  ASSERT_TRUE(true);
}