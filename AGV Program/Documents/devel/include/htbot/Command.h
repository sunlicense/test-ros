// Generated by gencpp from file htbot/Command.msg
// DO NOT EDIT!


#ifndef HTBOT_MESSAGE_COMMAND_H
#define HTBOT_MESSAGE_COMMAND_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace htbot
{
template <class ContainerAllocator>
struct Command_
{
  typedef Command_<ContainerAllocator> Type;

  Command_()
    : cmd(0)
    , param1(0)
    , param2(0.0)  {
    }
  Command_(const ContainerAllocator& _alloc)
    : cmd(0)
    , param1(0)
    , param2(0.0)  {
  (void)_alloc;
    }



   typedef int8_t _cmd_type;
  _cmd_type cmd;

   typedef int16_t _param1_type;
  _param1_type param1;

   typedef double _param2_type;
  _param2_type param2;





  typedef boost::shared_ptr< ::htbot::Command_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::htbot::Command_<ContainerAllocator> const> ConstPtr;

}; // struct Command_

typedef ::htbot::Command_<std::allocator<void> > Command;

typedef boost::shared_ptr< ::htbot::Command > CommandPtr;
typedef boost::shared_ptr< ::htbot::Command const> CommandConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::htbot::Command_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::htbot::Command_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace htbot

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'htbot': ['/home/rac/catkin_ws/src/htbot/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::htbot::Command_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::htbot::Command_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::Command_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::Command_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::Command_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::Command_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::htbot::Command_<ContainerAllocator> >
{
  static const char* value()
  {
    return "37e11590ded60e1e4263d0a06e0c9539";
  }

  static const char* value(const ::htbot::Command_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x37e11590ded60e1eULL;
  static const uint64_t static_value2 = 0x4263d0a06e0c9539ULL;
};

template<class ContainerAllocator>
struct DataType< ::htbot::Command_<ContainerAllocator> >
{
  static const char* value()
  {
    return "htbot/Command";
  }

  static const char* value(const ::htbot::Command_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::htbot::Command_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 cmd\n\
int16 param1\n\
float64 param2 \n\
";
  }

  static const char* value(const ::htbot::Command_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::htbot::Command_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.cmd);
      stream.next(m.param1);
      stream.next(m.param2);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Command_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::htbot::Command_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::htbot::Command_<ContainerAllocator>& v)
  {
    s << indent << "cmd: ";
    Printer<int8_t>::stream(s, indent + "  ", v.cmd);
    s << indent << "param1: ";
    Printer<int16_t>::stream(s, indent + "  ", v.param1);
    s << indent << "param2: ";
    Printer<double>::stream(s, indent + "  ", v.param2);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HTBOT_MESSAGE_COMMAND_H
