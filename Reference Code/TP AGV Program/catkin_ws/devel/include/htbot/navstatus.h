// Generated by gencpp from file htbot/navstatus.msg
// DO NOT EDIT!


#ifndef HTBOT_MESSAGE_NAVSTATUS_H
#define HTBOT_MESSAGE_NAVSTATUS_H


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
struct navstatus_
{
  typedef navstatus_<ContainerAllocator> Type;

  navstatus_()
    : stn0(0)
    , stn1(0)
    , stn2(0)
    , stn3(0)
    , stn4(0)
    , stn5(0)
    , stn6(0)
    , stn7(0)
    , stn8(0)
    , stn9(0)  {
    }
  navstatus_(const ContainerAllocator& _alloc)
    : stn0(0)
    , stn1(0)
    , stn2(0)
    , stn3(0)
    , stn4(0)
    , stn5(0)
    , stn6(0)
    , stn7(0)
    , stn8(0)
    , stn9(0)  {
  (void)_alloc;
    }



   typedef int8_t _stn0_type;
  _stn0_type stn0;

   typedef int8_t _stn1_type;
  _stn1_type stn1;

   typedef int8_t _stn2_type;
  _stn2_type stn2;

   typedef int8_t _stn3_type;
  _stn3_type stn3;

   typedef int8_t _stn4_type;
  _stn4_type stn4;

   typedef int8_t _stn5_type;
  _stn5_type stn5;

   typedef int8_t _stn6_type;
  _stn6_type stn6;

   typedef int8_t _stn7_type;
  _stn7_type stn7;

   typedef int8_t _stn8_type;
  _stn8_type stn8;

   typedef int8_t _stn9_type;
  _stn9_type stn9;





  typedef boost::shared_ptr< ::htbot::navstatus_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::htbot::navstatus_<ContainerAllocator> const> ConstPtr;

}; // struct navstatus_

typedef ::htbot::navstatus_<std::allocator<void> > navstatus;

typedef boost::shared_ptr< ::htbot::navstatus > navstatusPtr;
typedef boost::shared_ptr< ::htbot::navstatus const> navstatusConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::htbot::navstatus_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::htbot::navstatus_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::htbot::navstatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::htbot::navstatus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::navstatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::navstatus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::navstatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::navstatus_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::htbot::navstatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cc229716d82952abdbbbe7b0e8dff271";
  }

  static const char* value(const ::htbot::navstatus_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xcc229716d82952abULL;
  static const uint64_t static_value2 = 0xdbbbe7b0e8dff271ULL;
};

template<class ContainerAllocator>
struct DataType< ::htbot::navstatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "htbot/navstatus";
  }

  static const char* value(const ::htbot::navstatus_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::htbot::navstatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 stn0\n\
int8 stn1\n\
int8 stn2\n\
int8 stn3\n\
int8 stn4\n\
int8 stn5\n\
int8 stn6\n\
int8 stn7\n\
int8 stn8\n\
int8 stn9\n\
";
  }

  static const char* value(const ::htbot::navstatus_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::htbot::navstatus_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.stn0);
      stream.next(m.stn1);
      stream.next(m.stn2);
      stream.next(m.stn3);
      stream.next(m.stn4);
      stream.next(m.stn5);
      stream.next(m.stn6);
      stream.next(m.stn7);
      stream.next(m.stn8);
      stream.next(m.stn9);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct navstatus_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::htbot::navstatus_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::htbot::navstatus_<ContainerAllocator>& v)
  {
    s << indent << "stn0: ";
    Printer<int8_t>::stream(s, indent + "  ", v.stn0);
    s << indent << "stn1: ";
    Printer<int8_t>::stream(s, indent + "  ", v.stn1);
    s << indent << "stn2: ";
    Printer<int8_t>::stream(s, indent + "  ", v.stn2);
    s << indent << "stn3: ";
    Printer<int8_t>::stream(s, indent + "  ", v.stn3);
    s << indent << "stn4: ";
    Printer<int8_t>::stream(s, indent + "  ", v.stn4);
    s << indent << "stn5: ";
    Printer<int8_t>::stream(s, indent + "  ", v.stn5);
    s << indent << "stn6: ";
    Printer<int8_t>::stream(s, indent + "  ", v.stn6);
    s << indent << "stn7: ";
    Printer<int8_t>::stream(s, indent + "  ", v.stn7);
    s << indent << "stn8: ";
    Printer<int8_t>::stream(s, indent + "  ", v.stn8);
    s << indent << "stn9: ";
    Printer<int8_t>::stream(s, indent + "  ", v.stn9);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HTBOT_MESSAGE_NAVSTATUS_H