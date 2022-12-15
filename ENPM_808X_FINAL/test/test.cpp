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
#include "../include/tb3/turtlebot_sim.hpp"

class TaskPlanningFixture : public testing::Test {
public:

  TaskPlanningFixture()
    : node_(std::make_shared<rclcpp::Node>("basic_test"))
  {
    RCLCPP_INFO_STREAM(node_->get_logger(), "DONE WITH CONSTRUCTOR!!");
  }

  void SetUp() override
  {
    // Setup things that should occur before every test instance should go here

    /*
     * 1.) Define any ros2 package and exectuable you want to test
     *  example: package name = cpp_pubsub, node name = minimal_publisher,
     * executable = talker
     */
    bool retVal = StartROSExec(
      "tb3",
      "MinimalSubscriber",
      "turtlebot_sim");

    ASSERT_TRUE(retVal);

    RCLCPP_INFO_STREAM(node_->get_logger(), "DONE WITH SETUP!!");
  }

  void TearDown() override
  {
    // Tear things that should occur after every test instance should go here

    // Stop the running ros2 node, if any.
    bool retVal = StopROSExec();

    ASSERT_TRUE(retVal);

    std::cout << "DONE WITH TEARDOWN" << std::endl;
  }

protected:

  rclcpp::Node::SharedPtr node_;
  std::stringstream cmd_ss, cmdInfo_ss, killCmd_ss;

  bool StartROSExec(
    const char *pkg_name,
    const char *node_name,
    const char *exec_name)
  {
    cmd_ss << "ros2 run " << pkg_name << " " << exec_name <<
      " > /dev/null 2> /dev/null &";
    cmdInfo_ss << "ros2 node info " << "/" << node_name <<
      " > /dev/null 2> /dev/null";

    killCmd_ss << "pkill --signal SIGINT " << exec_name <<
      " > /dev/null 2> /dev/null";

    // First kill the ros2 node, in case it's still running.
    StopROSExec();

    // Start a ros2 node and wait for it to get ready:
    int retVal = system(cmd_ss.str().c_str());

    if (retVal != 0)
    {
      return false;
    }

    retVal = -1;

    while (retVal != 0)
    {
      retVal = system(cmdInfo_ss.str().c_str());
      sleep(1);
    }
    return true;
  }

  bool StopROSExec()
  {
    if (killCmd_ss.str().empty())
    {
      return true;
    }

    int retVal = system(killCmd_ss.str().c_str());

    return retVal == 0;
  }
};

TEST_F(TaskPlanningFixture, TrueIsTrueTest)
{
  std::cout << "TEST BEGINNING!!" << std::endl;

  EXPECT_TRUE(true);

  /*
   * 2.) subscribe to the topic
   */
  using SUBSCRIBER = rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr;
  bool hasData            = false;
  SUBSCRIBER subscription = node_->create_subscription<nav_msgs::msg::Odometry>(
    "/odom", 10,

    // Lambda expression begins
    [&](const nav_msgs::msg::Odometry& msg) {
    RCLCPP_INFO(node_->get_logger(), "I heard: '%f'", msg.twist.twist.angular.z);
    hasData = true;
    std::cout<<"Hi";
  }

    // end of lambda expression
    );

  /*
   * 3.) check to see if we get data winhin 3 sec
   */
  using timer = std::chrono::system_clock;
  using namespace std::chrono_literals;
  timer::time_point clock_start;
  timer::duration   elapsed_time;

  clock_start  = timer::now();
  elapsed_time = timer::now() - clock_start;
  rclcpp::Rate rate(2.0); // 2hz checks

  while (elapsed_time < 3s)
  {
    rclcpp::spin_some(node_);
    rate.sleep();
    elapsed_time = timer::now() - clock_start;
  }
  EXPECT_TRUE(hasData);
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  ::testing::InitGoogleTest(&argc, argv);
  int result = RUN_ALL_TESTS();

  rclcpp::shutdown();
  std::cout << "DONE SHUTTING DOWN ROS" << std::endl;
  return result;
}
