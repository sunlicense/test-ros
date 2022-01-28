// Generated by gencpp from file htbot/go.msg
// DO NOT EDIT!


#ifndef HTBOT_MESSAGE_GO_H
#define HTBOT_MESSAGE_GO_H


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
struct go_
{
  typedef go_<ContainerAllocator> Type;

  go_()
    : cmd(0)  {
    }
  go_(const ContainerAllocator& _alloc)
    : cmd(0)  {
  (void)_alloc;
    }



   typedef int8_t _cmd_type;
  _cmd_type cmd;





  typedef boost::shared_ptr< ::htbot::go_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::htbot::go_<ContainerAllocator> const> ConstPtr;

}; // struct go_

typedef ::htbot::go_<std::allocator<void> > go;

typedef boost::shared_ptr< ::htbot::go > goPtr;
typedef boost::shared_ptr< ::htbot::go const> goConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::htbot::go_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::htbot::go_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::htbot::go_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::htbot::go_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::go_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::go_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::go_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::go_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::htbot::go_<ContainerAllocator> >
{
  static const char* value()
  {
    return "26e2d5a54557d558b8243da339e9952c";
  }

  static const char* value(const ::htbot::go_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x26e2d5a54557d558ULL;
  static const uint64_t static_value2 = 0xb8243da339e9952cULL;
};

template<class ContainerAllocator>
struct DataType< ::htbot::go_<ContainerAllocator> >
{
  static const char* value()
  {
    return "htbot/go";
  }

  static const char* value(const ::htbot::go_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::htbot::go_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 cmd\n\
";
  }

  static const char* value(const ::htbot::go_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::htbot::go_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.cmd);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct go_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::htbot::go_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::htbot::go_<ContainerAllocator>& v)
  {
    s << indent << "cmd: ";
    Printer<int8_t>::stream(s, indent + "  ", v.cmd);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HTBOT_MESSAGE_GO_H
