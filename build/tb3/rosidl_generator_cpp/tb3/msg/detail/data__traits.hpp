// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tb3:msg/Data.idl
// generated code does not contain a copyright notice

#ifndef TB3__MSG__DETAIL__DATA__TRAITS_HPP_
#define TB3__MSG__DETAIL__DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tb3/msg/detail/data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace tb3
{

namespace msg
{

inline void to_flow_style_yaml(
  const Data & msg,
  std::ostream & out)
{
  out << "{";
  // member: my_data
  {
    out << "my_data: ";
    rosidl_generator_traits::value_to_yaml(msg.my_data, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Data & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: my_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "my_data: ";
    rosidl_generator_traits::value_to_yaml(msg.my_data, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Data & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace tb3

namespace rosidl_generator_traits
{

[[deprecated("use tb3::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tb3::msg::Data & msg,
  std::ostream & out, size_t indentation = 0)
{
  tb3::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tb3::msg::to_yaml() instead")]]
inline std::string to_yaml(const tb3::msg::Data & msg)
{
  return tb3::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tb3::msg::Data>()
{
  return "tb3::msg::Data";
}

template<>
inline const char * name<tb3::msg::Data>()
{
  return "tb3/msg/Data";
}

template<>
struct has_fixed_size<tb3::msg::Data>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tb3::msg::Data>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tb3::msg::Data>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TB3__MSG__DETAIL__DATA__TRAITS_HPP_
