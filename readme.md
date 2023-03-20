# ENPM808X FINAL Project

After obtaining sufficient funding, ACME Robotics is looking for developing robots for different applications. Our team is proposing a software stack for the robot that enables inventory management. The robot has a knowledge of the environment and has to navigate to multiple locations inside a warehouse in order to collect information regarding the products in the warehouse. The products have unique tags on them which would be scanned by the robot to identify the product and maintain the count. The warehouse is a dynamic environment and the obstacles need not be in the same position. Given the goal locations, we implemenr a controller to navigate to the product isles.   

[![Build Status](https://github.com/saahu27/ENPM_808X_FINAL/actions/workflows/my_codecov_upload.yml/badge.svg)](https://github.com/saahu27/ENPM_808X_FINAL/actions/workflows/my_codecov_upload.yml)    [![codecov](https://codecov.io/gh/saahu27/ENPM_808X_FINAL/branch/main/graph/badge.svg?token=5DVHEL8JLR)](https://codecov.io/gh/saahu27/ENPM_808X_FINAL)   [![License](https://img.shields.io/badge/License-Apache_2.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

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
colcon test --packages-select tutorial_interfaces
colcon test --packages-select ros2_aruco
colcon test --packages-select tb3
cat log/latest_test/tb3/stdout_stderr.log
```

## Generate code coverage report 
```
source install/setup.bash
ros2 run tb3 generate_coverage_report.bash
```
## Static Code 
```
cd <path to repository>/ENPM_808X_Final
cppcheck --enable=all --std=c++11 -I include/ --suppress=missingInclude $( find . -name \*.hpp -or -name *.cpp | grep -vE -e "^./build/" -e "^./vendor/")
```
```
cd <path to repository>/ENPM_808X_Final
cpplint --filter=-build/c++11,+build/c++17,-build/namespaces,-build/include_order $( find . -name \*.hpp -or -name \*.cpp | grep -vE -e "^./build/" -e "^./vendor/" )
```
## Doxygen
```
cd <path to repository>/Docs

doxygen Doxyfile

firefox index.html
```
[AIP Sheet](https://docs.google.com/spreadsheets/d/12jQ-N1z6aNx08tzQ0vjAypztQB04JdK8wfJC_l7KlUk/edit#gid=0)

[Sprint Planning Sheet](https://docs.google.com/document/d/1jmsCzZMhDV4vYkIBsq1OxhA2W3Id5yWly6dfnyGUrAE/edit)

[Presentation](https://docs.google.com/presentation/d/1yycZ2xIvlMv7u-YH4N7T5y6cAZZ6OISVKyMDpMjmE5A/edit?usp=sharing)

UML Diagram:

![UML Class Diagram](https://github.com/saahu27/ENPM_808X_FINAL/blob/main/UML/final/UML_class_diagram.png?raw=true "Title")

![Activity Diagram](https://github.com/saahu27/ENPM_808X_FINAL/blob/main/UML/final/UML_activity_diagram.png?raw=true "Title")

