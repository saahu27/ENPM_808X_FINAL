// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tb3:srv/ChangeString.idl
// generated code does not contain a copyright notice

#ifndef TB3__SRV__DETAIL__CHANGE_STRING__STRUCT_HPP_
#define TB3__SRV__DETAIL__CHANGE_STRING__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tb3__srv__ChangeString_Request __attribute__((deprecated))
#else
# define DEPRECATED__tb3__srv__ChangeString_Request __declspec(deprecated)
#endif

namespace tb3
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ChangeString_Request_
{
  using Type = ChangeString_Request_<ContainerAllocator>;

  explicit ChangeString_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->input = "";
    }
  }

  explicit ChangeString_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : input(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->input = "";
    }
  }

  // field types and members
  using _input_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _input_type input;

  // setters for named parameter idiom
  Type & set__input(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->input = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tb3::srv::ChangeString_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const tb3::srv::ChangeString_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tb3::srv::ChangeString_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tb3::srv::ChangeString_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tb3::srv::ChangeString_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tb3::srv::ChangeString_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tb3::srv::ChangeString_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tb3::srv::ChangeString_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tb3::srv::ChangeString_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tb3::srv::ChangeString_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tb3__srv__ChangeString_Request
    std::shared_ptr<tb3::srv::ChangeString_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tb3__srv__ChangeString_Request
    std::shared_ptr<tb3::srv::ChangeString_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ChangeString_Request_ & other) const
  {
    if (this->input != other.input) {
      return false;
    }
    return true;
  }
  bool operator!=(const ChangeString_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ChangeString_Request_

// alias to use template instance with default allocator
using ChangeString_Request =
  tb3::srv::ChangeString_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tb3


#ifndef _WIN32
# define DEPRECATED__tb3__srv__ChangeString_Response __attribute__((deprecated))
#else
# define DEPRECATED__tb3__srv__ChangeString_Response __declspec(deprecated)
#endif

namespace tb3
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ChangeString_Response_
{
  using Type = ChangeString_Response_<ContainerAllocator>;

  explicit ChangeString_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->output = "";
    }
  }

  explicit ChangeString_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : output(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->output = "";
    }
  }

  // field types and members
  using _output_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _output_type output;

  // setters for named parameter idiom
  Type & set__output(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->output = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tb3::srv::ChangeString_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const tb3::srv::ChangeString_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tb3::srv::ChangeString_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tb3::srv::ChangeString_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tb3::srv::ChangeString_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tb3::srv::ChangeString_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tb3::srv::ChangeString_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tb3::srv::ChangeString_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tb3::srv::ChangeString_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tb3::srv::ChangeString_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tb3__srv__ChangeString_Response
    std::shared_ptr<tb3::srv::ChangeString_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tb3__srv__ChangeString_Response
    std::shared_ptr<tb3::srv::ChangeString_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ChangeString_Response_ & other) const
  {
    if (this->output != other.output) {
      return false;
    }
    return true;
  }
  bool operator!=(const ChangeString_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ChangeString_Response_

// alias to use template instance with default allocator
using ChangeString_Response =
  tb3::srv::ChangeString_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tb3

namespace tb3
{

namespace srv
{

struct ChangeString
{
  using Request = tb3::srv::ChangeString_Request;
  using Response = tb3::srv::ChangeString_Response;
};

}  // namespace srv

}  // namespace tb3

#endif  // TB3__SRV__DETAIL__CHANGE_STRING__STRUCT_HPP_
