#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/LinearMath/Quaternion.h>
#include "tf2/exceptions.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include <geometry_msgs/msg/transform_stamped.hpp>
#include "tutorial_interfaces/msg/num.hpp" 

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("minimal_subscriber")
  {
    
    subscription2_ = this->create_subscription<nav_msgs::msg::Odometry>("odom", 10, std::bind(&MinimalSubscriber::robot_pose_callback, this, _1));

    subscription_ = this->create_subscription<tutorial_interfaces::msg::Num>("aruco_markers", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
    for (int i=0;i<4;i++)
    {id[i]=0;
     x[i]=0;
     y[i]=0;
     z[i]=0;
     x_prev[i]=-100;
     y_prev[i]=-100;
     z_prev[i]=-100;
     flag[i]=0;
}
  }

private:
  void topic_callback(const tutorial_interfaces::msg::Num::SharedPtr msg);   

  void robot_pose_callback(const nav_msgs::msg::Odometry::SharedPtr pose_msg); 
  
  rclcpp::Subscription<tutorial_interfaces::msg::Num>::SharedPtr subscription_;
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subscription2_;  
  
  int id[4];   
  float x[4], y[4], z[4];
  float x_prev[4], y_prev[4], z_prev[4];

  float lin_x, lin_y, ang;
  int flag[4];

};
