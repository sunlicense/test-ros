// Generated by gencpp from file htbot/queue.msg
// DO NOT EDIT!


#ifndef HTBOT_MESSAGE_QUEUE_H
#define HTBOT_MESSAGE_QUEUE_H


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
struct queue_
{
  typedef queue_<ContainerAllocator> Type;

  queue_()
    : noQ(0)
    , fLP1()
    , tLP1()
    , fLP2()
    , tLP2()
    , fLP3()
    , tLP3()
    , fLP4()
    , tLP4()
    , LPName()
    , LPInfo()  {
    }
  queue_(const ContainerAllocator& _alloc)
    : noQ(0)
    , fLP1(_alloc)
    , tLP1(_alloc)
    , fLP2(_alloc)
    , tLP2(_alloc)
    , fLP3(_alloc)
    , tLP3(_alloc)
    , fLP4(_alloc)
    , tLP4(_alloc)
    , LPName(_alloc)
    , LPInfo(_alloc)  {
  (void)_alloc;
    }



   typedef int8_t _noQ_type;
  _noQ_type noQ;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _fLP1_type;
  _fLP1_type fLP1;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _tLP1_type;
  _tLP1_type tLP1;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _fLP2_type;
  _fLP2_type fLP2;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _tLP2_type;
  _tLP2_type tLP2;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _fLP3_type;
  _fLP3_type fLP3;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _tLP3_type;
  _tLP3_type tLP3;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _fLP4_type;
  _fLP4_type fLP4;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _tLP4_type;
  _tLP4_type tLP4;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _LPName_type;
  _LPName_type LPName;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _LPInfo_type;
  _LPInfo_type LPInfo;





  typedef boost::shared_ptr< ::htbot::queue_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::htbot::queue_<ContainerAllocator> const> ConstPtr;

}; // struct queue_

typedef ::htbot::queue_<std::allocator<void> > queue;

typedef boost::shared_ptr< ::htbot::queue > queuePtr;
typedef boost::shared_ptr< ::htbot::queue const> queueConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::htbot::queue_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::htbot::queue_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::htbot::queue_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::htbot::queue_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::queue_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::queue_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::queue_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::queue_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::htbot::queue_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1ad64500a08450047cb508b267d3d903";
  }

  static const char* value(const ::htbot::queue_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1ad64500a0845004ULL;
  static const uint64_t static_value2 = 0x7cb508b267d3d903ULL;
};

template<class ContainerAllocator>
struct DataType< ::htbot::queue_<ContainerAllocator> >
{
  static const char* value()
  {
    return "htbot/queue";
  }

  static const char* value(const ::htbot::queue_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::htbot::queue_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 noQ\n\
string fLP1\n\
string tLP1\n\
string fLP2\n\
string tLP2\n\
string fLP3\n\
string tLP3\n\
string fLP4\n\
string tLP4\n\
string LPName\n\
string LPInfo\n\
";
  }

  static const char* value(const ::htbot::queue_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::htbot::queue_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.noQ);
      stream.next(m.fLP1);
      stream.next(m.tLP1);
      stream.next(m.fLP2);
      stream.next(m.tLP2);
      stream.next(m.fLP3);
      stream.next(m.tLP3);
      stream.next(m.fLP4);
      stream.next(m.tLP4);
      stream.next(m.LPName);
      stream.next(m.LPInfo);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct queue_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::htbot::queue_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::htbot::queue_<ContainerAllocator>& v)
  {
    s << indent << "noQ: ";
    Printer<int8_t>::stream(s, indent + "  ", v.noQ);
    s << indent << "fLP1: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.fLP1);
    s << indent << "tLP1: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.tLP1);
    s << indent << "fLP2: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.fLP2);
    s << indent << "tLP2: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.tLP2);
    s << indent << "fLP3: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.fLP3);
    s << indent << "tLP3: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.tLP3);
    s << indent << "fLP4: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.fLP4);
    s << indent << "tLP4: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.tLP4);
    s << indent << "LPName: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.LPName);
    s << indent << "LPInfo: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.LPInfo);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HTBOT_MESSAGE_QUEUE_H