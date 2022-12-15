// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tb3:msg/Data.idl
// generated code does not contain a copyright notice

#ifndef TB3__MSG__DETAIL__DATA__BUILDER_HPP_
#define TB3__MSG__DETAIL__DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tb3/msg/detail/data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tb3
{

namespace msg
{

namespace builder
{

class Init_Data_my_data
{
public:
  Init_Data_my_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tb3::msg::Data my_data(::tb3::msg::Data::_my_data_type arg)
  {
    msg_.my_data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tb3::msg::Data msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tb3::msg::Data>()
{
  return tb3::msg::builder::Init_Data_my_data();
}

}  // namespace tb3

#endif  // TB3__MSG__DETAIL__DATA__BUILDER_HPP_
