cmake_minimum_required(VERSION 3.8)
project(tb3)



if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
# find_package(tb3_controller REQUIRED)
# For service and msg
find_package(rosidl_default_generators REQUIRED)

set(THIS_PACKAGE_INCLUDE_DEPENDS
  geometry_msgs
  rclcpp
  nav_msgs
  tf2
  tf2_ros
  std_msgs
  sensor_msgs
)

include_directories(include)

if(COVERAGE)
  set(CMAKE_BUILD_TYPE "Debug")
  set(CMAKE_CXX_FLAGS "--coverage")
  set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE "ON")
  set(ARG_CONFIG_FILE "${PROJECT_SOURCE_DIR}/uncrustify_google_cpp_allman.cfg"
    CACHE STRING "uncrustify config file")
endif()
    
if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  find_package(ament_lint_auto REQUIRED)
  find_package(tutorial_interfaces REQUIRED) 
    # the following lines skip linters
  set(ament_cmake_cppcheck_FOUND TRUE)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  set(ament_cmake_flake8_FOUND TRUE)
  set(ament_cmake_uncrustify_FOUND TRUE)
  set(ament_cmake_xmllint_FOUND TRUE)
  set(ament_cmake_lint_cmake_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()

  # Add gtests
  # ament_add_gtest(test test/test.cpp)
  # ament_target_dependencies(test rclcpp rclcpp_action std_msgs geometry_msgs nav_msgs tf2 tf2_ros)
  # rosidl_target_interfaces(server_test ${PROJECT_NAME} "rosidl_typesupport_cpp")
  # rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
  # target_link_libraries(test "${cpp_typesupport_target}")

  # install(TARGETS
  # test
  # DESTINATION lib/${PROJECT_NAME})
  
  set(TESTFILES
  test/aruco_test.cpp
  test/controller_test.cpp
  test/main.cpp)
  ament_add_gtest(${PROJECT_NAME}_test ${TESTFILES})
  ament_target_dependencies(${PROJECT_NAME}_test rclcpp tutorial_interfaces std_msgs geometry_msgs sensor_msgs nav_msgs tf2 tf2_ros)

endif()

add_executable(tb3G src/tb3controller.cpp)
ament_target_dependencies(tb3G rclcpp std_msgs geometry_msgs sensor_msgs nav_msgs tf2 tf2_ros)
# rosidl_target_interfaces(talker ${PROJECT_NAME} "rosidl_typesupport_cpp")
# TO make sure that executable files can link to service and message headers
rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(tb3G "${cpp_typesupport_target}")

add_executable(turtlebot_sim src/turtlebot_sim.cpp)
ament_target_dependencies(turtlebot_sim rclcpp tutorial_interfaces std_msgs geometry_msgs sensor_msgs nav_msgs tf2 tf2_ros)

install(TARGETS
  tb3G
  turtlebot_sim
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY
  launch worlds models scripts
  DESTINATION share/${PROJECT_NAME}/
)

install(PROGRAMS      # want to make the file executable (ie. chmod a+x)
  scripts/generate_coverage_report.bash
  DESTINATION lib/${PROJECT_NAME})

ament_package()
