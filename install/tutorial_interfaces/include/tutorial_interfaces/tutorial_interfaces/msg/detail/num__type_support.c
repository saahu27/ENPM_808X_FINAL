// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tutorial_interfaces:msg/Num.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tutorial_interfaces/msg/detail/num__rosidl_typesupport_introspection_c.h"
#include "tutorial_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tutorial_interfaces/msg/detail/num__functions.h"
#include "tutorial_interfaces/msg/detail/num__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `marker_ids`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `poses`
#include "geometry_msgs/msg/pose.h"
// Member `poses`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__Num_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tutorial_interfaces__msg__Num__init(message_memory);
}

void tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__Num_fini_function(void * message_memory)
{
  tutorial_interfaces__msg__Num__fini(message_memory);
}

size_t tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__size_function__Num__marker_ids(
  const void * untyped_member)
{
  const rosidl_runtime_c__int64__Sequence * member =
    (const rosidl_runtime_c__int64__Sequence *)(untyped_member);
  return member->size;
}

const void * tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__get_const_function__Num__marker_ids(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int64__Sequence * member =
    (const rosidl_runtime_c__int64__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__get_function__Num__marker_ids(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int64__Sequence * member =
    (rosidl_runtime_c__int64__Sequence *)(untyped_member);
  return &member->data[index];
}

void tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__fetch_function__Num__marker_ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int64_t * item =
    ((const int64_t *)
    tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__get_const_function__Num__marker_ids(untyped_member, index));
  int64_t * value =
    (int64_t *)(untyped_value);
  *value = *item;
}

void tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__assign_function__Num__marker_ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int64_t * item =
    ((int64_t *)
    tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__get_function__Num__marker_ids(untyped_member, index));
  const int64_t * value =
    (const int64_t *)(untyped_value);
  *item = *value;
}

bool tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__resize_function__Num__marker_ids(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int64__Sequence * member =
    (rosidl_runtime_c__int64__Sequence *)(untyped_member);
  rosidl_runtime_c__int64__Sequence__fini(member);
  return rosidl_runtime_c__int64__Sequence__init(member, size);
}

size_t tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__size_function__Num__poses(
  const void * untyped_member)
{
  const geometry_msgs__msg__Pose__Sequence * member =
    (const geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  return member->size;
}

const void * tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__get_const_function__Num__poses(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Pose__Sequence * member =
    (const geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__get_function__Num__poses(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Pose__Sequence * member =
    (geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  return &member->data[index];
}

void tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__fetch_function__Num__poses(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Pose * item =
    ((const geometry_msgs__msg__Pose *)
    tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__get_const_function__Num__poses(untyped_member, index));
  geometry_msgs__msg__Pose * value =
    (geometry_msgs__msg__Pose *)(untyped_value);
  *value = *item;
}

void tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__assign_function__Num__poses(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Pose * item =
    ((geometry_msgs__msg__Pose *)
    tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__get_function__Num__poses(untyped_member, index));
  const geometry_msgs__msg__Pose * value =
    (const geometry_msgs__msg__Pose *)(untyped_value);
  *item = *value;
}

bool tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__resize_function__Num__poses(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Pose__Sequence * member =
    (geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  geometry_msgs__msg__Pose__Sequence__fini(member);
  return geometry_msgs__msg__Pose__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__Num_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__Num, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "marker_ids",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__Num, marker_ids),  // bytes offset in struct
    NULL,  // default value
    tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__size_function__Num__marker_ids,  // size() function pointer
    tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__get_const_function__Num__marker_ids,  // get_const(index) function pointer
    tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__get_function__Num__marker_ids,  // get(index) function pointer
    tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__fetch_function__Num__marker_ids,  // fetch(index, &value) function pointer
    tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__assign_function__Num__marker_ids,  // assign(index, value) function pointer
    tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__resize_function__Num__marker_ids  // resize(index) function pointer
  },
  {
    "poses",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__Num, poses),  // bytes offset in struct
    NULL,  // default value
    tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__size_function__Num__poses,  // size() function pointer
    tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__get_const_function__Num__poses,  // get_const(index) function pointer
    tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__get_function__Num__poses,  // get(index) function pointer
    tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__fetch_function__Num__poses,  // fetch(index, &value) function pointer
    tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__assign_function__Num__poses,  // assign(index, value) function pointer
    tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__resize_function__Num__poses  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__Num_message_members = {
  "tutorial_interfaces__msg",  // message namespace
  "Num",  // message name
  3,  // number of fields
  sizeof(tutorial_interfaces__msg__Num),
  tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__Num_message_member_array,  // message members
  tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__Num_init_function,  // function to initialize message memory (memory has to be allocated)
  tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__Num_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__Num_message_type_support_handle = {
  0,
  &tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__Num_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tutorial_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, msg, Num)() {
  tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__Num_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__Num_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__Num_message_type_support_handle.typesupport_identifier) {
    tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__Num_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tutorial_interfaces__msg__Num__rosidl_typesupport_introspection_c__Num_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
