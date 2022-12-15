// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__NUM__BUILDER_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__NUM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tutorial_interfaces/msg/detail/num__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tutorial_interfaces
{

namespace msg
{

namespace builder
{

class Init_Num_poses
{
public:
  explicit Init_Num_poses(::tutorial_interfaces::msg::Num & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::msg::Num poses(::tutorial_interfaces::msg::Num::_poses_type arg)
  {
    msg_.poses = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::msg::Num msg_;
};

class Init_Num_marker_ids
{
public:
  explicit Init_Num_marker_ids(::tutorial_interfaces::msg::Num & msg)
  : msg_(msg)
  {}
  Init_Num_poses marker_ids(::tutorial_interfaces::msg::Num::_marker_ids_type arg)
  {
    msg_.marker_ids = std::move(arg);
    return Init_Num_poses(msg_);
  }

private:
  ::tutorial_interfaces::msg::Num msg_;
};

class Init_Num_header
{
public:
  Init_Num_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Num_marker_ids header(::tutorial_interfaces::msg::Num::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Num_marker_ids(msg_);
  }

private:
  ::tutorial_interfaces::msg::Num msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::msg::Num>()
{
  return tutorial_interfaces::msg::builder::Init_Num_header();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__NUM__BUILDER_HPP_
