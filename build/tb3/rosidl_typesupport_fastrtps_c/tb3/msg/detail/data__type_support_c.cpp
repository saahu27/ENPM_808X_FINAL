// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from tb3:msg/Data.idl
// generated code does not contain a copyright notice
#include "tb3/msg/detail/data__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "tb3/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "tb3/msg/detail/data__struct.h"
#include "tb3/msg/detail/data__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // my_data
#include "rosidl_runtime_c/string_functions.h"  // my_data

// forward declare type support functions


using _Data__ros_msg_type = tb3__msg__Data;

static bool _Data__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Data__ros_msg_type * ros_message = static_cast<const _Data__ros_msg_type *>(untyped_ros_message);
  // Field name: my_data
  {
    const rosidl_runtime_c__String * str = &ros_message->my_data;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _Data__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Data__ros_msg_type * ros_message = static_cast<_Data__ros_msg_type *>(untyped_ros_message);
  // Field name: my_data
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->my_data.data) {
      rosidl_runtime_c__String__init(&ros_message->my_data);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->my_data,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'my_data'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tb3
size_t get_serialized_size_tb3__msg__Data(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Data__ros_msg_type * ros_message = static_cast<const _Data__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name my_data
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->my_data.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _Data__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_tb3__msg__Data(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tb3
size_t max_serialized_size_tb3__msg__Data(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: my_data
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _Data__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_tb3__msg__Data(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Data = {
  "tb3::msg",
  "Data",
  _Data__cdr_serialize,
  _Data__cdr_deserialize,
  _Data__get_serialized_size,
  _Data__max_serialized_size
};

static rosidl_message_type_support_t _Data__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Data,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tb3, msg, Data)() {
  return &_Data__type_support;
}

#if defined(__cplusplus)
}
#endif
