// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tb3:msg/Data.idl
// generated code does not contain a copyright notice

#ifndef TB3__MSG__DETAIL__DATA__STRUCT_HPP_
#define TB3__MSG__DETAIL__DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tb3__msg__Data __attribute__((deprecated))
#else
# define DEPRECATED__tb3__msg__Data __declspec(deprecated)
#endif

namespace tb3
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Data_
{
  using Type = Data_<ContainerAllocator>;

  explicit Data_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->my_data = "";
    }
  }

  explicit Data_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : my_data(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->my_data = "";
    }
  }

  // field types and members
  using _my_data_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _my_data_type my_data;

  // setters for named parameter idiom
  Type & set__my_data(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->my_data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tb3::msg::Data_<ContainerAllocator> *;
  using ConstRawPtr =
    const tb3::msg::Data_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tb3::msg::Data_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tb3::msg::Data_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tb3::msg::Data_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tb3::msg::Data_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tb3::msg::Data_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tb3::msg::Data_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tb3::msg::Data_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tb3::msg::Data_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tb3__msg__Data
    std::shared_ptr<tb3::msg::Data_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tb3__msg__Data
    std::shared_ptr<tb3::msg::Data_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Data_ & other) const
  {
    if (this->my_data != other.my_data) {
      return false;
    }
    return true;
  }
  bool operator!=(const Data_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Data_

// alias to use template instance with default allocator
using Data =
  tb3::msg::Data_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tb3

#endif  // TB3__MSG__DETAIL__DATA__STRUCT_HPP_
