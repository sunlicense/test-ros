// Generated by gencpp from file htbot/agv_status.msg
// DO NOT EDIT!


#ifndef HTBOT_MESSAGE_AGV_STATUS_H
#define HTBOT_MESSAGE_AGV_STATUS_H


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
struct agv_status_
{
  typedef agv_status_<ContainerAllocator> Type;

  agv_status_()
    : cmd(0)
    , time()
    , status(0)
    , location(0)
    , arrival()
    , b_level(0)
    , e_status(0)
    , complete(0)
    , lastLP(0)  {
    }
  agv_status_(const ContainerAllocator& _alloc)
    : cmd(0)
    , time()
    , status(0)
    , location(0)
    , arrival()
    , b_level(0)
    , e_status(0)
    , complete(0)
    , lastLP(0)  {
  (void)_alloc;
    }



   typedef int8_t _cmd_type;
  _cmd_type cmd;

   typedef ros::Time _time_type;
  _time_type time;

   typedef int8_t _status_type;
  _status_type status;

   typedef int8_t _location_type;
  _location_type location;

   typedef ros::Time _arrival_type;
  _arrival_type arrival;

   typedef int8_t _b_level_type;
  _b_level_type b_level;

   typedef int8_t _e_status_type;
  _e_status_type e_status;

   typedef int8_t _complete_type;
  _complete_type complete;

   typedef int8_t _lastLP_type;
  _lastLP_type lastLP;





  typedef boost::shared_ptr< ::htbot::agv_status_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::htbot::agv_status_<ContainerAllocator> const> ConstPtr;

}; // struct agv_status_

typedef ::htbot::agv_status_<std::allocator<void> > agv_status;

typedef boost::shared_ptr< ::htbot::agv_status > agv_statusPtr;
typedef boost::shared_ptr< ::htbot::agv_status const> agv_statusConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::htbot::agv_status_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::htbot::agv_status_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::htbot::agv_status_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::htbot::agv_status_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::agv_status_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::agv_status_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::agv_status_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::agv_status_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::htbot::agv_status_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0b47d165e9912a2afc0c77fd2d5b0bfa";
  }

  static const char* value(const ::htbot::agv_status_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0b47d165e9912a2aULL;
  static const uint64_t static_value2 = 0xfc0c77fd2d5b0bfaULL;
};

template<class ContainerAllocator>
struct DataType< ::htbot::agv_status_<ContainerAllocator> >
{
  static const char* value()
  {
    return "htbot/agv_status";
  }

  static const char* value(const ::htbot::agv_status_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::htbot::agv_status_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 cmd\n\
time time\n\
int8 status\n\
int8 location\n\
time arrival\n\
int8 b_level\n\
int8 e_status\n\
int8 complete\n\
int8 lastLP\n\
";
  }

  static const char* value(const ::htbot::agv_status_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::htbot::agv_status_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.cmd);
      stream.next(m.time);
      stream.next(m.status);
      stream.next(m.location);
      stream.next(m.arrival);
      stream.next(m.b_level);
      stream.next(m.e_status);
      stream.next(m.complete);
      stream.next(m.lastLP);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct agv_status_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::htbot::agv_status_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::htbot::agv_status_<ContainerAllocator>& v)
  {
    s << indent << "cmd: ";
    Printer<int8_t>::stream(s, indent + "  ", v.cmd);
    s << indent << "time: ";
    Printer<ros::Time>::stream(s, indent + "  ", v.time);
    s << indent << "status: ";
    Printer<int8_t>::stream(s, indent + "  ", v.status);
    s << indent << "location: ";
    Printer<int8_t>::stream(s, indent + "  ", v.location);
    s << indent << "arrival: ";
    Printer<ros::Time>::stream(s, indent + "  ", v.arrival);
    s << indent << "b_level: ";
    Printer<int8_t>::stream(s, indent + "  ", v.b_level);
    s << indent << "e_status: ";
    Printer<int8_t>::stream(s, indent + "  ", v.e_status);
    s << indent << "complete: ";
    Printer<int8_t>::stream(s, indent + "  ", v.complete);
    s << indent << "lastLP: ";
    Printer<int8_t>::stream(s, indent + "  ", v.lastLP);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HTBOT_MESSAGE_AGV_STATUS_H