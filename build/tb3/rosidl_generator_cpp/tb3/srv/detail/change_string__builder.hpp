// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tb3:srv/ChangeString.idl
// generated code does not contain a copyright notice

#ifndef TB3__SRV__DETAIL__CHANGE_STRING__BUILDER_HPP_
#define TB3__SRV__DETAIL__CHANGE_STRING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tb3/srv/detail/change_string__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tb3
{

namespace srv
{

namespace builder
{

class Init_ChangeString_Request_input
{
public:
  Init_ChangeString_Request_input()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tb3::srv::ChangeString_Request input(::tb3::srv::ChangeString_Request::_input_type arg)
  {
    msg_.input = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tb3::srv::ChangeString_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tb3::srv::ChangeString_Request>()
{
  return tb3::srv::builder::Init_ChangeString_Request_input();
}

}  // namespace tb3


namespace tb3
{

namespace srv
{

namespace builder
{

class Init_ChangeString_Response_output
{
public:
  Init_ChangeString_Response_output()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tb3::srv::ChangeString_Response output(::tb3::srv::ChangeString_Response::_output_type arg)
  {
    msg_.output = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tb3::srv::ChangeString_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tb3::srv::ChangeString_Response>()
{
  return tb3::srv::builder::Init_ChangeString_Response_output();
}

}  // namespace tb3

#endif  // TB3__SRV__DETAIL__CHANGE_STRING__BUILDER_HPP_
