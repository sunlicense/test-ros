// Generated by gencpp from file htbot/weblaser.msg
// DO NOT EDIT!


#ifndef HTBOT_MESSAGE_WEBLASER_H
#define HTBOT_MESSAGE_WEBLASER_H


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
struct weblaser_
{
  typedef weblaser_<ContainerAllocator> Type;

  weblaser_()
    : info(0)
    , size(0)
    , px()
    , py()  {
    }
  weblaser_(const ContainerAllocator& _alloc)
    : info(0)
    , size(0)
    , px(_alloc)
    , py(_alloc)  {
  (void)_alloc;
    }



   typedef int8_t _info_type;
  _info_type info;

   typedef int32_t _size_type;
  _size_type size;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _px_type;
  _px_type px;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _py_type;
  _py_type py;





  typedef boost::shared_ptr< ::htbot::weblaser_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::htbot::weblaser_<ContainerAllocator> const> ConstPtr;

}; // struct weblaser_

typedef ::htbot::weblaser_<std::allocator<void> > weblaser;

typedef boost::shared_ptr< ::htbot::weblaser > weblaserPtr;
typedef boost::shared_ptr< ::htbot::weblaser const> weblaserConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::htbot::weblaser_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::htbot::weblaser_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::htbot::weblaser_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::htbot::weblaser_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::weblaser_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::weblaser_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::weblaser_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::weblaser_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::htbot::weblaser_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f7e0272dce619f1a82242dcdb545a8bc";
  }

  static const char* value(const ::htbot::weblaser_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf7e0272dce619f1aULL;
  static const uint64_t static_value2 = 0x82242dcdb545a8bcULL;
};

template<class ContainerAllocator>
struct DataType< ::htbot::weblaser_<ContainerAllocator> >
{
  static const char* value()
  {
    return "htbot/weblaser";
  }

  static const char* value(const ::htbot::weblaser_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::htbot::weblaser_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 info\n\
int32 size\n\
float32[] px\n\
float32[] py\n\
";
  }

  static const char* value(const ::htbot::weblaser_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::htbot::weblaser_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.info);
      stream.next(m.size);
      stream.next(m.px);
      stream.next(m.py);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct weblaser_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::htbot::weblaser_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::htbot::weblaser_<ContainerAllocator>& v)
  {
    s << indent << "info: ";
    Printer<int8_t>::stream(s, indent + "  ", v.info);
    s << indent << "size: ";
    Printer<int32_t>::stream(s, indent + "  ", v.size);
    s << indent << "px[]" << std::endl;
    for (size_t i = 0; i < v.px.size(); ++i)
    {
      s << indent << "  px[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.px[i]);
    }
    s << indent << "py[]" << std::endl;
    for (size_t i = 0; i < v.py.size(); ++i)
    {
      s << indent << "  py[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.py[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // HTBOT_MESSAGE_WEBLASER_H
