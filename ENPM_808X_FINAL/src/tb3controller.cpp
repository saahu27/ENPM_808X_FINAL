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
 * @file walker_node.cpp
 * @author Sahruday Patti
 * @brief Illustration of walker algorithm
 * @version 0.1
 * @date 2022-11-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/tb3/pid.hpp"
#include "../include/tb3/tb3controller.hpp"
#include <cstdlib>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/LinearMath/Quaternion.h>
#include "tf2/exceptions.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include <geometry_msgs/msg/transform_stamped.hpp>

using std::placeholders::_1;
using namespace std::chrono_literals;

void tb3::transform_callback() {
    if (!m_go_to_goal && !m_go_to_angle)
        return;

    geometry_msgs::msg::TransformStamped t;

    // RCLCPP_INFO(this->get_logger(), "Transform callback");

    try
    {
        t = m_tf_buffer->lookupTransform(m_parent_frame, m_child_frame, tf2::TimePointZero);
    }
    catch (const tf2::TransformException &ex)
    {
        //RCLCPP_INFO_STREAM(this->get_logger(), "Could not transform " << m_parent_frame << " to " << m_child_frame << ": " << ex.what());
        return;
    }

    //RCLCPP_INFO(this->get_logger(), "Position of robot in odom: [%f, %f]", t.transform.rotation.x, t.transform.rotation.y);

    m_location.first = t.transform.translation.x;
    m_location.second = t.transform.translation.y;
    m_orientation = t.transform.rotation;

    // if (!m_goal_set)
    // {
    //     RCLCPP_INFO(this->get_logger(), "Robot has been localized, going to goal.");
    //     go_to_goal();
    // }
}

double tb3::compute_distance(const std::pair<double, double> &a, const std::pair<double, double> &b) {
    return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
}

double tb3::compute_yaw_from_quaternion() {
    tf2::Quaternion q(
        m_orientation.x,
        m_orientation.y,
        m_orientation.z,
        m_orientation.w);
    tf2::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);

    return yaw;
}

void tb3::move_tb3(double linear, double angular) {
    geometry_msgs::msg::Twist msg;
    msg.linear.x = linear;
    msg.angular.z = angular;
    m_publisher_cmd_vel->publish(msg);
}

void tb3::stop() {
    geometry_msgs::msg::Twist cmd_vel_msg;
    cmd_vel_msg.linear.x = 0;
    cmd_vel_msg.angular.z = 0;
    m_publisher_cmd_vel->publish(cmd_vel_msg);
    if (!m_go_to_angle)
    {for(int i=0; i<100;i++)
    	{}}

    // std_msgs::msg::Bool goal_reached_msg;
    // goal_reached_msg.data = true;
    // m_goal_reached_publisher->publish(goal_reached_msg);

}

double tb3::normalize_angle_positive(double angle) {
    const double result = fmod(angle, 2.0 * M_PI);
    if (result < 0)
        return result + 2.0 * M_PI;
    return result;
}

double tb3::normalize_angle(double angle) {
    const double result = fmod(angle + M_PI, 2.0 * M_PI);
    if (result <= 0.0)
        return result + M_PI;
    return result - M_PI;   
}

void tb3::go_to_goal_callback() {
    std::pair<double, double> goal{m_goal_x, m_goal_y};
    //RCLCPP_INFO_STREAM(this->get_logger(), "go_to_goal_callback");
    // if (m_location.first == 3.0 && m_location.second == 0)
    // {
    //     RCLCPP_INFO(this->get_logger(), "Robot is not localized yet");
    //     return;
    // }

    if ((!m_go_to_goal) && (!m_go_to_angle))
    	if(goals.size()!=0)
    	{//RCLCPP_INFO(this->get_logger(), "Size = %d", goals.size());

    	set_goal(goals);
    	 }
        else
        {return;}

    if (m_go_to_goal == false && m_go_to_angle == true) {

        double m_current_orientation = compute_yaw_from_quaternion();
        double angle_to_goal = (m_goal_orientation - m_current_orientation);
        // RCLCPP_INFO_STREAM(this->get_logger(), "Distance to goal: [" << distance_to_goal << "]");

        if (angle_to_goal < 0)
            // angle_to_goal = 2 * M_PI + angle_to_goal;
            angle_to_goal = normalize_angle_positive(angle_to_goal);

        // angle to rotate to face the goal
        double w = angle_to_goal; //m_goal_orientation - compute_yaw_from_quaternion();
        //RCLCPP_INFO(this->get_logger(), "yaw %f",compute_yaw_from_quaternion());
        //RCLCPP_INFO(this->get_logger(), "w %f",w);
        //RCLCPP_INFO(this->get_logger(), "w %f %f %f %f",m_orientation.x,m_orientation.y,m_orientation.z,m_orientation.w);
        if (w > M_PI)
        {
            w = w - 2 * M_PI;
            // w = m_normalize_angle_positive(w);
        }

        // proportional control for linear velocity
        double linear_x = 0.0;
        w = abs(w);
        // proportional control for angular velocity
        double angular_z = m_kh * w;
        if (angular_z > 0)
            angular_z = std::min(angular_z, m_angular_speed);
        else
            angular_z = std::max(angular_z, -m_angular_speed);

        if (w > 0.05) {
            
            move_tb3(linear_x, angular_z);
        }
        else {
            m_go_to_angle = false;
            stop();
        }
        


    }

    if (m_go_to_goal) {
        std::pair<double, double> goal{m_goal_x, m_goal_y};
        double distance_to_goal = compute_distance(m_location, goal);
        //RCLCPP_INFO(this->get_logger(), "distance %f",distance_to_goal);
        // RCLCPP_INFO_STREAM(this->get_logger(), "Current position: [" << m_location.first << "," << m_location.second << "]");

        if (distance_to_goal > 0.1)
        {
            distance_to_goal = compute_distance(m_location, goal);
            double angle_to_goal = std::atan2(m_goal_y - m_location.second, m_goal_x - m_location.first);
        // RCLCPP_INFO_STREAM(this->get_logger(), "Distance to goal: [" << distance_to_goal << "]");

            if (angle_to_goal < 0)
            // angle_to_goal = 2 * M_PI + angle_to_goal;
            angle_to_goal = normalize_angle_positive(angle_to_goal);

        // angle to rotate to face the goal
            double w = angle_to_goal - compute_yaw_from_quaternion();
            //RCLCPP_INFO(this->get_logger(), "yaw %f",compute_yaw_from_quaternion());
            //RCLCPP_INFO(this->get_logger(), "w %f",w);
            //RCLCPP_INFO(this->get_logger(), "w %f %f %f %f",m_orientation.x,m_orientation.y,m_orientation.z,m_orientation.w);
    
        
            if (w > M_PI)
            {
            w = w - 2 * M_PI;
            // w = m_normalize_angle_positive(w);
            }

        // proportional control for linear velocity
            double linear_x = std::min(m_kv * distance_to_goal, m_linear_speed);

        // proportional control for angular velocity
            double angular_z = m_kh * w;
            if (angular_z > 0)
                angular_z = std::min(angular_z, m_angular_speed);
            else
                angular_z = std::max(angular_z, -m_angular_speed);
            move_tb3(linear_x, angular_z);
        }
        else
        {
            //RCLCPP_INFO_STREAM(this->get_logger(), "********** Goal reached **********");
            //stop();
            m_go_to_goal = false;
            stop();
        }
    }
    
}

int main(int argc, char *argv[]) {
    // init
    rclcpp::init(argc, argv);
    // node
    auto node = std::make_shared<tb3>("tb3_controller", "robot");
    std::vector<std::vector<float>> goals = {{-4.0,0.0, 3.14},{-4.0,0.0, 4.9},{0.0,0.0, 3.14},{0.0,0.0, 4.9}};
    node->set_goal(goals);
    //if (!node->m_go_to_goal && !node->m_go_to_angle) 
    //{node->set_goal(-4.0,0.0, 4.9);}
    //node->set_goal(-4.0,0.0, 4.9);

    rclcpp::spin(node);
    // shutdown
    rclcpp::shutdown();


    //rclcpp::executors::MultiThreadedExecutor exec;
    //exec.add_node(std::make_shared<MinimalSubscriber>());
    // // controller::PID angle_pid;
    // // controller::PID distance_pid;
    // auto node = std::make_shared<tb3>("tb3", "robot");
    // exec.add_node(node);
    // exec.spin();
    // rclcpp::shutdown();
}
