// Generated by gencpp from file htbot/cleanlist.msg
// DO NOT EDIT!


#ifndef HTBOT_MESSAGE_CLEANLIST_H
#define HTBOT_MESSAGE_CLEANLIST_H


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
struct cleanlist_
{
  typedef cleanlist_<ContainerAllocator> Type;

  cleanlist_()
    : info(0)
    , mapno(0)
    , cplanno(0)
    , mapdir()
    , mapname()
    , cplandir()
    , cleanplan()  {
    }
  cleanlist_(const ContainerAllocator& _alloc)
    : info(0)
    , mapno(0)
    , cplanno(0)
    , mapdir(_alloc)
    , mapname(_alloc)
    , cplandir(_alloc)
    , cleanplan(_alloc)  {
  (void)_alloc;
    }



   typedef int8_t _info_type;
  _info_type info;

   typedef int32_t _mapno_type;
  _mapno_type mapno;

   typedef int32_t _cplanno_type;
  _cplanno_type cplanno;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _mapdir_type;
  _mapdir_type mapdir;

   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _mapname_type;
  _mapname_type mapname;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _cplandir_type;
  _cplandir_type cplandir;

   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _cleanplan_type;
  _cleanplan_type cleanplan;





  typedef boost::shared_ptr< ::htbot::cleanlist_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::htbot::cleanlist_<ContainerAllocator> const> ConstPtr;

}; // struct cleanlist_

typedef ::htbot::cleanlist_<std::allocator<void> > cleanlist;

typedef boost::shared_ptr< ::htbot::cleanlist > cleanlistPtr;
typedef boost::shared_ptr< ::htbot::cleanlist const> cleanlistConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::htbot::cleanlist_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::htbot::cleanlist_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::htbot::cleanlist_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::htbot::cleanlist_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::cleanlist_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::cleanlist_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::cleanlist_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::cleanlist_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::htbot::cleanlist_<ContainerAllocator> >
{
  static const char* value()
  {
    return "975117791827cbfacd76c6c1c424923b";
  }

  static const char* value(const ::htbot::cleanlist_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x975117791827cbfaULL;
  static const uint64_t static_value2 = 0xcd76c6c1c424923bULL;
};

template<class ContainerAllocator>
struct DataType< ::htbot::cleanlist_<ContainerAllocator> >
{
  static const char* value()
  {
    return "htbot/cleanlist";
  }

  static const char* value(const ::htbot::cleanlist_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::htbot::cleanlist_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 info\n\
int32 mapno\n\
int32 cplanno\n\
string mapdir\n\
string[] mapname\n\
string cplandir\n\
string[] cleanplan\n\
";
  }

  static const char* value(const ::htbot::cleanlist_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::htbot::cleanlist_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.info);
      stream.next(m.mapno);
      stream.next(m.cplanno);
      stream.next(m.mapdir);
      stream.next(m.mapname);
      stream.next(m.cplandir);
      stream.next(m.cleanplan);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct cleanlist_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::htbot::cleanlist_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::htbot::cleanlist_<ContainerAllocator>& v)
  {
    s << indent << "info: ";
    Printer<int8_t>::stream(s, indent + "  ", v.info);
    s << indent << "mapno: ";
    Printer<int32_t>::stream(s, indent + "  ", v.mapno);
    s << indent << "cplanno: ";
    Printer<int32_t>::stream(s, indent + "  ", v.cplanno);
    s << indent << "mapdir: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.mapdir);
    s << indent << "mapname[]" << std::endl;
    for (size_t i = 0; i < v.mapname.size(); ++i)
    {
      s << indent << "  mapname[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.mapname[i]);
    }
    s << indent << "cplandir: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.cplandir);
    s << indent << "cleanplan[]" << std::endl;
    for (size_t i = 0; i < v.cleanplan.size(); ++i)
    {
      s << indent << "  cleanplan[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.cleanplan[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // HTBOT_MESSAGE_CLEANLIST_H
