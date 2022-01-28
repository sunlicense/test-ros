// Generated by gencpp from file htbot/scanMcmdResponse.msg
// DO NOT EDIT!


#ifndef HTBOT_MESSAGE_SCANMCMDRESPONSE_H
#define HTBOT_MESSAGE_SCANMCMDRESPONSE_H


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
struct scanMcmdResponse_
{
  typedef scanMcmdResponse_<ContainerAllocator> Type;

  scanMcmdResponse_()
    : status(0)
    , s1()
    , s2()
    , x(0.0)
    , y(0.0)
    , an(0.0)  {
    }
  scanMcmdResponse_(const ContainerAllocator& _alloc)
    : status(0)
    , s1(_alloc)
    , s2(_alloc)
    , x(0.0)
    , y(0.0)
    , an(0.0)  {
  (void)_alloc;
    }



   typedef int8_t _status_type;
  _status_type status;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _s1_type;
  _s1_type s1;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _s2_type;
  _s2_type s2;

   typedef float _x_type;
  _x_type x;

   typedef float _y_type;
  _y_type y;

   typedef float _an_type;
  _an_type an;





  typedef boost::shared_ptr< ::htbot::scanMcmdResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::htbot::scanMcmdResponse_<ContainerAllocator> const> ConstPtr;

}; // struct scanMcmdResponse_

typedef ::htbot::scanMcmdResponse_<std::allocator<void> > scanMcmdResponse;

typedef boost::shared_ptr< ::htbot::scanMcmdResponse > scanMcmdResponsePtr;
typedef boost::shared_ptr< ::htbot::scanMcmdResponse const> scanMcmdResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::htbot::scanMcmdResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::htbot::scanMcmdResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace htbot

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'htbot': ['/home/rac/catkin_ws/src/htbot/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::htbot::scanMcmdResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::htbot::scanMcmdResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::scanMcmdResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::scanMcmdResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::scanMcmdResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::scanMcmdResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::htbot::scanMcmdResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5106dd5514f949ed1f84cad57c27a682";
  }

  static const char* value(const ::htbot::scanMcmdResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5106dd5514f949edULL;
  static const uint64_t static_value2 = 0x1f84cad57c27a682ULL;
};

template<class ContainerAllocator>
struct DataType< ::htbot::scanMcmdResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "htbot/scanMcmdResponse";
  }

  static const char* value(const ::htbot::scanMcmdResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::htbot::scanMcmdResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 status\n\
string s1\n\
string s2\n\
float32 x\n\
float32 y\n\
float32 an\n\
\n\
";
  }

  static const char* value(const ::htbot::scanMcmdResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::htbot::scanMcmdResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.status);
      stream.next(m.s1);
      stream.next(m.s2);
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.an);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct scanMcmdResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::htbot::scanMcmdResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::htbot::scanMcmdResponse_<ContainerAllocator>& v)
  {
    s << indent << "status: ";
    Printer<int8_t>::stream(s, indent + "  ", v.status);
    s << indent << "s1: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.s1);
    s << indent << "s2: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.s2);
    s << indent << "x: ";
    Printer<float>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<float>::stream(s, indent + "  ", v.y);
    s << indent << "an: ";
    Printer<float>::stream(s, indent + "  ", v.an);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HTBOT_MESSAGE_SCANMCMDRESPONSE_H
