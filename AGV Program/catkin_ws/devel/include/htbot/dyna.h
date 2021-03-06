// Generated by gencpp from file htbot/dyna.msg
// DO NOT EDIT!


#ifndef HTBOT_MESSAGE_DYNA_H
#define HTBOT_MESSAGE_DYNA_H


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
struct dyna_
{
  typedef dyna_<ContainerAllocator> Type;

  dyna_()
    : paramid(0)
    , intValue(0)
    , doubleValue(0.0)
    , strValue()
    , boolValue(false)
    , ftprintno(0)
    , footprintlist()  {
    }
  dyna_(const ContainerAllocator& _alloc)
    : paramid(0)
    , intValue(0)
    , doubleValue(0.0)
    , strValue(_alloc)
    , boolValue(false)
    , ftprintno(0)
    , footprintlist(_alloc)  {
  (void)_alloc;
    }



   typedef int8_t _paramid_type;
  _paramid_type paramid;

   typedef int32_t _intValue_type;
  _intValue_type intValue;

   typedef double _doubleValue_type;
  _doubleValue_type doubleValue;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _strValue_type;
  _strValue_type strValue;

   typedef uint8_t _boolValue_type;
  _boolValue_type boolValue;

   typedef int8_t _ftprintno_type;
  _ftprintno_type ftprintno;

   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _footprintlist_type;
  _footprintlist_type footprintlist;





  typedef boost::shared_ptr< ::htbot::dyna_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::htbot::dyna_<ContainerAllocator> const> ConstPtr;

}; // struct dyna_

typedef ::htbot::dyna_<std::allocator<void> > dyna;

typedef boost::shared_ptr< ::htbot::dyna > dynaPtr;
typedef boost::shared_ptr< ::htbot::dyna const> dynaConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::htbot::dyna_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::htbot::dyna_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::htbot::dyna_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::htbot::dyna_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::dyna_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::dyna_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::dyna_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::dyna_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::htbot::dyna_<ContainerAllocator> >
{
  static const char* value()
  {
    return "aeca87cb1dcfc788fa047b80da0c718b";
  }

  static const char* value(const ::htbot::dyna_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xaeca87cb1dcfc788ULL;
  static const uint64_t static_value2 = 0xfa047b80da0c718bULL;
};

template<class ContainerAllocator>
struct DataType< ::htbot::dyna_<ContainerAllocator> >
{
  static const char* value()
  {
    return "htbot/dyna";
  }

  static const char* value(const ::htbot::dyna_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::htbot::dyna_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 paramid\n\
int32 intValue\n\
float64 doubleValue\n\
string strValue\n\
bool boolValue\n\
int8 ftprintno\n\
float64[] footprintlist\n\
";
  }

  static const char* value(const ::htbot::dyna_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::htbot::dyna_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.paramid);
      stream.next(m.intValue);
      stream.next(m.doubleValue);
      stream.next(m.strValue);
      stream.next(m.boolValue);
      stream.next(m.ftprintno);
      stream.next(m.footprintlist);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct dyna_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::htbot::dyna_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::htbot::dyna_<ContainerAllocator>& v)
  {
    s << indent << "paramid: ";
    Printer<int8_t>::stream(s, indent + "  ", v.paramid);
    s << indent << "intValue: ";
    Printer<int32_t>::stream(s, indent + "  ", v.intValue);
    s << indent << "doubleValue: ";
    Printer<double>::stream(s, indent + "  ", v.doubleValue);
    s << indent << "strValue: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.strValue);
    s << indent << "boolValue: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.boolValue);
    s << indent << "ftprintno: ";
    Printer<int8_t>::stream(s, indent + "  ", v.ftprintno);
    s << indent << "footprintlist[]" << std::endl;
    for (size_t i = 0; i < v.footprintlist.size(); ++i)
    {
      s << indent << "  footprintlist[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.footprintlist[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // HTBOT_MESSAGE_DYNA_H
