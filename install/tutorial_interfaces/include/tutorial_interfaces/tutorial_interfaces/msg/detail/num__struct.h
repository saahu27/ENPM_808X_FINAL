// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tutorial_interfaces:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__NUM__STRUCT_H_
#define TUTORIAL_INTERFACES__MSG__DETAIL__NUM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'marker_ids'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'poses'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/Num in the package tutorial_interfaces.
typedef struct tutorial_interfaces__msg__Num
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__int64__Sequence marker_ids;
  geometry_msgs__msg__Pose__Sequence poses;
} tutorial_interfaces__msg__Num;

// Struct for a sequence of tutorial_interfaces__msg__Num.
typedef struct tutorial_interfaces__msg__Num__Sequence
{
  tutorial_interfaces__msg__Num * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__msg__Num__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__NUM__STRUCT_H_
