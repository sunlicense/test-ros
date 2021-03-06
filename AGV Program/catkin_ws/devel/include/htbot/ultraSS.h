// Generated by gencpp from file htbot/ultraSS.msg
// DO NOT EDIT!


#ifndef HTBOT_MESSAGE_ULTRASS_H
#define HTBOT_MESSAGE_ULTRASS_H


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
struct ultraSS_
{
  typedef ultraSS_<ContainerAllocator> Type;

  ultraSS_()
    : uFR(0.0)
    , uFL(0.0)
    , uRF(0.0)
    , uRR(0.0)
    , uLF(0.0)
    , uLR(0.0)  {
    }
  ultraSS_(const ContainerAllocator& _alloc)
    : uFR(0.0)
    , uFL(0.0)
    , uRF(0.0)
    , uRR(0.0)
    , uLF(0.0)
    , uLR(0.0)  {
  (void)_alloc;
    }



   typedef float _uFR_type;
  _uFR_type uFR;

   typedef float _uFL_type;
  _uFL_type uFL;

   typedef float _uRF_type;
  _uRF_type uRF;

   typedef float _uRR_type;
  _uRR_type uRR;

   typedef float _uLF_type;
  _uLF_type uLF;

   typedef float _uLR_type;
  _uLR_type uLR;





  typedef boost::shared_ptr< ::htbot::ultraSS_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::htbot::ultraSS_<ContainerAllocator> const> ConstPtr;

}; // struct ultraSS_

typedef ::htbot::ultraSS_<std::allocator<void> > ultraSS;

typedef boost::shared_ptr< ::htbot::ultraSS > ultraSSPtr;
typedef boost::shared_ptr< ::htbot::ultraSS const> ultraSSConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::htbot::ultraSS_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::htbot::ultraSS_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::htbot::ultraSS_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::htbot::ultraSS_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::ultraSS_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::ultraSS_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::ultraSS_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::ultraSS_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::htbot::ultraSS_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9863d3f832b0ad0ccba6621fbb52a2e5";
  }

  static const char* value(const ::htbot::ultraSS_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9863d3f832b0ad0cULL;
  static const uint64_t static_value2 = 0xcba6621fbb52a2e5ULL;
};

template<class ContainerAllocator>
struct DataType< ::htbot::ultraSS_<ContainerAllocator> >
{
  static const char* value()
  {
    return "htbot/ultraSS";
  }

  static const char* value(const ::htbot::ultraSS_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::htbot::ultraSS_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 uFR\n\
float32 uFL\n\
float32 uRF\n\
float32 uRR\n\
float32 uLF\n\
float32 uLR\n\
";
  }

  static const char* value(const ::htbot::ultraSS_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::htbot::ultraSS_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.uFR);
      stream.next(m.uFL);
      stream.next(m.uRF);
      stream.next(m.uRR);
      stream.next(m.uLF);
      stream.next(m.uLR);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ultraSS_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::htbot::ultraSS_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::htbot::ultraSS_<ContainerAllocator>& v)
  {
    s << indent << "uFR: ";
    Printer<float>::stream(s, indent + "  ", v.uFR);
    s << indent << "uFL: ";
    Printer<float>::stream(s, indent + "  ", v.uFL);
    s << indent << "uRF: ";
    Printer<float>::stream(s, indent + "  ", v.uRF);
    s << indent << "uRR: ";
    Printer<float>::stream(s, indent + "  ", v.uRR);
    s << indent << "uLF: ";
    Printer<float>::stream(s, indent + "  ", v.uLF);
    s << indent << "uLR: ";
    Printer<float>::stream(s, indent + "  ", v.uLR);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HTBOT_MESSAGE_ULTRASS_H
