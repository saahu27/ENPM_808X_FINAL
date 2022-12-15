// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tb3:srv/ChangeString.idl
// generated code does not contain a copyright notice

#ifndef TB3__SRV__DETAIL__CHANGE_STRING__TRAITS_HPP_
#define TB3__SRV__DETAIL__CHANGE_STRING__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tb3/srv/detail/change_string__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace tb3
{

namespace srv
{

inline void to_flow_style_yaml(
  const ChangeString_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: input
  {
    out << "input: ";
    rosidl_generator_traits::value_to_yaml(msg.input, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ChangeString_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: input
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "input: ";
    rosidl_generator_traits::value_to_yaml(msg.input, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ChangeString_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace tb3

namespace rosidl_generator_traits
{

[[deprecated("use tb3::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tb3::srv::ChangeString_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  tb3::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tb3::srv::to_yaml() instead")]]
inline std::string to_yaml(const tb3::srv::ChangeString_Request & msg)
{
  return tb3::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tb3::srv::ChangeString_Request>()
{
  return "tb3::srv::ChangeString_Request";
}

template<>
inline const char * name<tb3::srv::ChangeString_Request>()
{
  return "tb3/srv/ChangeString_Request";
}

template<>
struct has_fixed_size<tb3::srv::ChangeString_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tb3::srv::ChangeString_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tb3::srv::ChangeString_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace tb3
{

namespace srv
{

inline void to_flow_style_yaml(
  const ChangeString_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: output
  {
    out << "output: ";
    rosidl_generator_traits::value_to_yaml(msg.output, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ChangeString_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: output
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "output: ";
    rosidl_generator_traits::value_to_yaml(msg.output, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ChangeString_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace tb3

namespace rosidl_generator_traits
{

[[deprecated("use tb3::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tb3::srv::ChangeString_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  tb3::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tb3::srv::to_yaml() instead")]]
inline std::string to_yaml(const tb3::srv::ChangeString_Response & msg)
{
  return tb3::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tb3::srv::ChangeString_Response>()
{
  return "tb3::srv::ChangeString_Response";
}

template<>
inline const char * name<tb3::srv::ChangeString_Response>()
{
  return "tb3/srv/ChangeString_Response";
}

template<>
struct has_fixed_size<tb3::srv::ChangeString_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tb3::srv::ChangeString_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tb3::srv::ChangeString_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tb3::srv::ChangeString>()
{
  return "tb3::srv::ChangeString";
}

template<>
inline const char * name<tb3::srv::ChangeString>()
{
  return "tb3/srv/ChangeString";
}

template<>
struct has_fixed_size<tb3::srv::ChangeString>
  : std::integral_constant<
    bool,
    has_fixed_size<tb3::srv::ChangeString_Request>::value &&
    has_fixed_size<tb3::srv::ChangeString_Response>::value
  >
{
};

template<>
struct has_bounded_size<tb3::srv::ChangeString>
  : std::integral_constant<
    bool,
    has_bounded_size<tb3::srv::ChangeString_Request>::value &&
    has_bounded_size<tb3::srv::ChangeString_Response>::value
  >
{
};

template<>
struct is_service<tb3::srv::ChangeString>
  : std::true_type
{
};

template<>
struct is_service_request<tb3::srv::ChangeString_Request>
  : std::true_type
{
};

template<>
struct is_service_response<tb3::srv::ChangeString_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TB3__SRV__DETAIL__CHANGE_STRING__TRAITS_HPP_
