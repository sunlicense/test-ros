// Generated by gencpp from file htbot/move_status.msg
// DO NOT EDIT!


#ifndef HTBOT_MESSAGE_MOVE_STATUS_H
#define HTBOT_MESSAGE_MOVE_STATUS_H


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
struct move_status_
{
  typedef move_status_<ContainerAllocator> Type;

  move_status_()
    : stat(0)  {
    }
  move_status_(const ContainerAllocator& _alloc)
    : stat(0)  {
  (void)_alloc;
    }



   typedef int8_t _stat_type;
  _stat_type stat;





  typedef boost::shared_ptr< ::htbot::move_status_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::htbot::move_status_<ContainerAllocator> const> ConstPtr;

}; // struct move_status_

typedef ::htbot::move_status_<std::allocator<void> > move_status;

typedef boost::shared_ptr< ::htbot::move_status > move_statusPtr;
typedef boost::shared_ptr< ::htbot::move_status const> move_statusConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::htbot::move_status_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::htbot::move_status_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::htbot::move_status_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::htbot::move_status_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::move_status_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::move_status_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::move_status_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::move_status_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::htbot::move_status_<ContainerAllocator> >
{
  static const char* value()
  {
    return "85998e8afa5502f501182cfd6840bd64";
  }

  static const char* value(const ::htbot::move_status_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x85998e8afa5502f5ULL;
  static const uint64_t static_value2 = 0x01182cfd6840bd64ULL;
};

template<class ContainerAllocator>
struct DataType< ::htbot::move_status_<ContainerAllocator> >
{
  static const char* value()
  {
    return "htbot/move_status";
  }

  static const char* value(const ::htbot::move_status_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::htbot::move_status_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 stat\n\
";
  }

  static const char* value(const ::htbot::move_status_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::htbot::move_status_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.stat);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct move_status_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::htbot::move_status_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::htbot::move_status_<ContainerAllocator>& v)
  {
    s << indent << "stat: ";
    Printer<int8_t>::stream(s, indent + "  ", v.stat);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HTBOT_MESSAGE_MOVE_STATUS_H
