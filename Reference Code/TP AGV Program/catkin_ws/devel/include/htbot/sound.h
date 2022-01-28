// Generated by gencpp from file htbot/sound.msg
// DO NOT EDIT!


#ifndef HTBOT_MESSAGE_SOUND_H
#define HTBOT_MESSAGE_SOUND_H


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
struct sound_
{
  typedef sound_<ContainerAllocator> Type;

  sound_()
    : id(0)
    , startdelay(0)
    , restartdelay(0)  {
    }
  sound_(const ContainerAllocator& _alloc)
    : id(0)
    , startdelay(0)
    , restartdelay(0)  {
  (void)_alloc;
    }



   typedef int16_t _id_type;
  _id_type id;

   typedef int8_t _startdelay_type;
  _startdelay_type startdelay;

   typedef int8_t _restartdelay_type;
  _restartdelay_type restartdelay;





  typedef boost::shared_ptr< ::htbot::sound_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::htbot::sound_<ContainerAllocator> const> ConstPtr;

}; // struct sound_

typedef ::htbot::sound_<std::allocator<void> > sound;

typedef boost::shared_ptr< ::htbot::sound > soundPtr;
typedef boost::shared_ptr< ::htbot::sound const> soundConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::htbot::sound_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::htbot::sound_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::htbot::sound_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::htbot::sound_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::sound_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::sound_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::sound_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::sound_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::htbot::sound_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ca5aa2e17ae07703f6b975c8e29b6503";
  }

  static const char* value(const ::htbot::sound_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xca5aa2e17ae07703ULL;
  static const uint64_t static_value2 = 0xf6b975c8e29b6503ULL;
};

template<class ContainerAllocator>
struct DataType< ::htbot::sound_<ContainerAllocator> >
{
  static const char* value()
  {
    return "htbot/sound";
  }

  static const char* value(const ::htbot::sound_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::htbot::sound_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int16 id\n\
int8 startdelay\n\
int8 restartdelay\n\
";
  }

  static const char* value(const ::htbot::sound_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::htbot::sound_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.id);
      stream.next(m.startdelay);
      stream.next(m.restartdelay);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct sound_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::htbot::sound_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::htbot::sound_<ContainerAllocator>& v)
  {
    s << indent << "id: ";
    Printer<int16_t>::stream(s, indent + "  ", v.id);
    s << indent << "startdelay: ";
    Printer<int8_t>::stream(s, indent + "  ", v.startdelay);
    s << indent << "restartdelay: ";
    Printer<int8_t>::stream(s, indent + "  ", v.restartdelay);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HTBOT_MESSAGE_SOUND_H
