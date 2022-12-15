#include "../include/tb3/turtlebot_sim.hpp"

using std::placeholders::_1;

void MinimalSubscriber::topic_callback(const tutorial_interfaces::msg::Num::SharedPtr msg)       // CHANGE
  { 
  if(abs((float)ang)<=0.0001 && abs((float)lin_x) <=0.0001 && abs((float)lin_y)<=0.0001)
  {

    for(size_t i=0;i<msg->poses.size();i++)
    {   
       if (flag[msg->marker_ids[i]]!=-1)
       {
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
    	
    	if(i==msg->poses.size()-1)
    	{flag[msg->marker_ids[i]]=-1;}}
    	
    	
    }}
   
    
  }
void MinimalSubscriber::robot_pose_callback(const nav_msgs::msg::Odometry::SharedPtr pose_msg)       // CHANGE
{ 
   ang = pose_msg->twist.twist.angular.z; 
   lin_x = pose_msg->twist.twist.linear.x;
   lin_y = pose_msg->twist.twist.linear.y;
  }
   

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
