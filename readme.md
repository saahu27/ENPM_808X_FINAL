# ENPM_808X_FINAL

[![Build Status](https://github.com/saahu27/ENPM_808X_FINAL/actions/workflows/build_and_coveralls.yml/badge.svg)](https://github.com/saahu27/ENPM_808X_FINAL/actions/workflows/build_and_coveralls.yml)    [![Coverage Status](https://coveralls.io/repos/github/saahu27/ENPM_808X_FINAL/badge.svg?branch=master)](https://coveralls.io/github/saahu27/ENPM_808X_FINAL?branch=master)   [![License](https://img.shields.io/badge/License-Apache_2.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

# ENPM808X_FINAL_PROJECT
After obtaining sufficient funding, ACME Robotics is looking for developing robots for different applications. Our team is proposing a software stack for the robot that enables inventory management. The robot has a knowledge of the environment and has to navigate to multiple locations inside a warehouse in order to collect information regarding the products in the warehouse. The products have unique tags on them which would be scanned by the robot to identify the product and maintain the count. The warehouse is a dynamic environment and the obstacles need not be in the same position. Given the obstacle locations, we implement a path planner to safely navigate around them to perform the task of collecting product information.

## Assumptions
```
OS: Ubuntu Linux Focal (20.04) 64-bit
ROS2 Distro: Humble Hawksbill
ROS2 Workspace name: ros2_ws
ROS2 Installation Directory: ros2_humble
```

## ROS 2 dependencies
```
ament_cmake
rclcpp
std_msgs
```

## Creating the workspace and building the package
```
mkdir ros2_ws/src
cd ros2_ws/src
git clone https://github.com/saahu27/ENPM_808X_FINAL.git
cd ..
colcon build --packages-select ENPM_808X_FINAL
. install/setup.bash
```