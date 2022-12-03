# ENPM_808X_FINAL

[![Build Status](https://github.com/saahu27/ENPM_808X_FINAL/actions/workflows/build_and_coveralls.yml/badge.svg)](https://github.com/saahu27/ENPM_808X_FINAL/actions/workflows/build_and_coveralls.yml)    [![Coverage Status](https://coveralls.io/repos/github/saahu27/ENPM_808X_FINAL/badge.svg?branch=master)](https://coveralls.io/github/saahu27/ENPM_808X_FINAL?branch=master)   [![License](https://img.shields.io/badge/License-Apache_2.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

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