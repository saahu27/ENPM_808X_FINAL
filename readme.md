# ENPM_808X_FINAL

[![Build Status](https://github.com/saahu27/ENPM_808X_FINAL/actions/workflows/my_codecov_upload.yml/badge.svg)](https://github.com/saahu27/ENPM_808X_FINAL/actions/workflows/my_codecov_upload.yml)    [![Coverage Status](https://coveralls.io/repos/github/saahu27/ENPM_808X_FINAL/badge.svg?branch=master)](https://coveralls.io/github/saahu27/ENPM_808X_FINAL?branch=master)   [![License](https://img.shields.io/badge/License-Apache_2.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

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
colcon build --packages-select tb3
colcon build --packages-select ros2_aruco
colcon build --packages-select tutorial_interfaces
. install/setup.bash
```

## Launch Demo shown during presentation
```
ros2 launch tb3 demo_launch.py
```

## build for test coverage
```
rm -rf build/tb3/
colcon build --cmake-args -DCOVERAGE=1 --packages-select tb3
cat log/latest_build/tb3/stdout_stderr.log
```

## Run unit tests
```
source install/setup.bash
colcon test --packages-select tb3
cat log/latest_test/tb3/stdout_stderr.log
```

## Generate code coverage report 
```
source install/setup.bash
ros2 run tb3 generate_coverage_report.bash
```



