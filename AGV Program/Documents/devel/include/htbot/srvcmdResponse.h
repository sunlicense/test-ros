// Generated by gencpp from file htbot/srvcmdResponse.msg
// DO NOT EDIT!


#ifndef HTBOT_MESSAGE_SRVCMDRESPONSE_H
#define HTBOT_MESSAGE_SRVCMDRESPONSE_H


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
struct srvcmdResponse_
{
  typedef srvcmdResponse_<ContainerAllocator> Type;

  srvcmdResponse_()
    : status(0)
    , s1()
    , s2()
    , linear(0.0)
    , angular(0.0)  {
    }
  srvcmdResponse_(const ContainerAllocator& _alloc)
    : status(0)
    , s1(_alloc)
    , s2(_alloc)
    , linear(0.0)
    , angular(0.0)  {
  (void)_alloc;
    }



   typedef int8_t _status_type;
  _status_type status;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _s1_type;
  _s1_type s1;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _s2_type;
  _s2_type s2;

   typedef float _linear_type;
  _linear_type linear;

   typedef float _angular_type;
  _angular_type angular;





  typedef boost::shared_ptr< ::htbot::srvcmdResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::htbot::srvcmdResponse_<ContainerAllocator> const> ConstPtr;

}; // struct srvcmdResponse_

typedef ::htbot::srvcmdResponse_<std::allocator<void> > srvcmdResponse;

typedef boost::shared_ptr< ::htbot::srvcmdResponse > srvcmdResponsePtr;
typedef boost::shared_ptr< ::htbot::srvcmdResponse const> srvcmdResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::htbot::srvcmdResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::htbot::srvcmdResponse_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::htbot::srvcmdResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::htbot::srvcmdResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::srvcmdResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::srvcmdResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::srvcmdResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::srvcmdResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::htbot::srvcmdResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bf41a1e7b1d81f6e588d96220bbc26a9";
  }

  static const char* value(const ::htbot::srvcmdResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xbf41a1e7b1d81f6eULL;
  static const uint64_t static_value2 = 0x588d96220bbc26a9ULL;
};

template<class ContainerAllocator>
struct DataType< ::htbot::srvcmdResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "htbot/srvcmdResponse";
  }

  static const char* value(const ::htbot::srvcmdResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::htbot::srvcmdResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 status\n\
string s1\n\
string s2\n\
float32 linear\n\
float32 angular\n\
\n\
";
  }

  static const char* value(const ::htbot::srvcmdResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::htbot::srvcmdResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.status);
      stream.next(m.s1);
      stream.next(m.s2);
      stream.next(m.linear);
      stream.next(m.angular);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct srvcmdResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::htbot::srvcmdResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::htbot::srvcmdResponse_<ContainerAllocator>& v)
  {
    s << indent << "status: ";
    Printer<int8_t>::stream(s, indent + "  ", v.status);
    s << indent << "s1: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.s1);
    s << indent << "s2: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.s2);
    s << indent << "linear: ";
    Printer<float>::stream(s, indent + "  ", v.linear);
    s << indent << "angular: ";
    Printer<float>::stream(s, indent + "  ", v.angular);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HTBOT_MESSAGE_SRVCMDRESPONSE_H
