// Generated by gencpp from file htbot/stat.msg
// DO NOT EDIT!


#ifndef HTBOT_MESSAGE_STAT_H
#define HTBOT_MESSAGE_STAT_H


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
struct stat_
{
  typedef stat_<ContainerAllocator> Type;

  stat_()
    : speed(0)
    , trip(0)
    , time(0)
    , maxspeed(0.0)
    , minspeed(0.0)
    , avgspeed(0.0)
    , curspeed(0.0)
    , totalruntime(0.0)
    , totaltriptime(0.0)
    , totaldowntime(0.0)
    , totalidletime(0.0)
    , uptime(0.0)
    , totaltripdist(0.0)
    , avgvolt(0.0)
    , avgcurr(0.0)
    , maxcurr(0.0)
    , mincurr(0.0)
    , amphr(0.0)
    , batlevel(0.0)
    , tnumtrip(0)
    , clearops(0)
    , estop(0)
    , motordisable(0)
    , alarmlog()
    , heartbeat(0)  {
    }
  stat_(const ContainerAllocator& _alloc)
    : speed(0)
    , trip(0)
    , time(0)
    , maxspeed(0.0)
    , minspeed(0.0)
    , avgspeed(0.0)
    , curspeed(0.0)
    , totalruntime(0.0)
    , totaltriptime(0.0)
    , totaldowntime(0.0)
    , totalidletime(0.0)
    , uptime(0.0)
    , totaltripdist(0.0)
    , avgvolt(0.0)
    , avgcurr(0.0)
    , maxcurr(0.0)
    , mincurr(0.0)
    , amphr(0.0)
    , batlevel(0.0)
    , tnumtrip(0)
    , clearops(0)
    , estop(0)
    , motordisable(0)
    , alarmlog(_alloc)
    , heartbeat(0)  {
  (void)_alloc;
    }



   typedef int8_t _speed_type;
  _speed_type speed;

   typedef int8_t _trip_type;
  _trip_type trip;

   typedef int8_t _time_type;
  _time_type time;

   typedef float _maxspeed_type;
  _maxspeed_type maxspeed;

   typedef float _minspeed_type;
  _minspeed_type minspeed;

   typedef float _avgspeed_type;
  _avgspeed_type avgspeed;

   typedef float _curspeed_type;
  _curspeed_type curspeed;

   typedef float _totalruntime_type;
  _totalruntime_type totalruntime;

   typedef float _totaltriptime_type;
  _totaltriptime_type totaltriptime;

   typedef float _totaldowntime_type;
  _totaldowntime_type totaldowntime;

   typedef float _totalidletime_type;
  _totalidletime_type totalidletime;

   typedef float _uptime_type;
  _uptime_type uptime;

   typedef float _totaltripdist_type;
  _totaltripdist_type totaltripdist;

   typedef float _avgvolt_type;
  _avgvolt_type avgvolt;

   typedef float _avgcurr_type;
  _avgcurr_type avgcurr;

   typedef float _maxcurr_type;
  _maxcurr_type maxcurr;

   typedef float _mincurr_type;
  _mincurr_type mincurr;

   typedef float _amphr_type;
  _amphr_type amphr;

   typedef float _batlevel_type;
  _batlevel_type batlevel;

   typedef int16_t _tnumtrip_type;
  _tnumtrip_type tnumtrip;

   typedef int16_t _clearops_type;
  _clearops_type clearops;

   typedef int16_t _estop_type;
  _estop_type estop;

   typedef int16_t _motordisable_type;
  _motordisable_type motordisable;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _alarmlog_type;
  _alarmlog_type alarmlog;

   typedef int16_t _heartbeat_type;
  _heartbeat_type heartbeat;





  typedef boost::shared_ptr< ::htbot::stat_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::htbot::stat_<ContainerAllocator> const> ConstPtr;

}; // struct stat_

typedef ::htbot::stat_<std::allocator<void> > stat;

typedef boost::shared_ptr< ::htbot::stat > statPtr;
typedef boost::shared_ptr< ::htbot::stat const> statConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::htbot::stat_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::htbot::stat_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::htbot::stat_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::htbot::stat_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::stat_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::stat_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::stat_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::stat_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::htbot::stat_<ContainerAllocator> >
{
  static const char* value()
  {
    return "af7104aa5ac2b7ecb587449c2a96bf9f";
  }

  static const char* value(const ::htbot::stat_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xaf7104aa5ac2b7ecULL;
  static const uint64_t static_value2 = 0xb587449c2a96bf9fULL;
};

template<class ContainerAllocator>
struct DataType< ::htbot::stat_<ContainerAllocator> >
{
  static const char* value()
  {
    return "htbot/stat";
  }

  static const char* value(const ::htbot::stat_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::htbot::stat_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 speed\n\
int8 trip\n\
int8 time\n\
float32 maxspeed\n\
float32 minspeed\n\
float32 avgspeed\n\
float32 curspeed\n\
float32 totalruntime\n\
float32 totaltriptime\n\
float32 totaldowntime\n\
float32 totalidletime\n\
float32 uptime\n\
float32 totaltripdist\n\
float32 avgvolt\n\
float32 avgcurr\n\
float32 maxcurr\n\
float32 mincurr\n\
float32 amphr\n\
float32 batlevel\n\
int16 tnumtrip\n\
int16 clearops\n\
int16 estop\n\
int16 motordisable\n\
string alarmlog\n\
int16 heartbeat\n\
";
  }

  static const char* value(const ::htbot::stat_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::htbot::stat_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.speed);
      stream.next(m.trip);
      stream.next(m.time);
      stream.next(m.maxspeed);
      stream.next(m.minspeed);
      stream.next(m.avgspeed);
      stream.next(m.curspeed);
      stream.next(m.totalruntime);
      stream.next(m.totaltriptime);
      stream.next(m.totaldowntime);
      stream.next(m.totalidletime);
      stream.next(m.uptime);
      stream.next(m.totaltripdist);
      stream.next(m.avgvolt);
      stream.next(m.avgcurr);
      stream.next(m.maxcurr);
      stream.next(m.mincurr);
      stream.next(m.amphr);
      stream.next(m.batlevel);
      stream.next(m.tnumtrip);
      stream.next(m.clearops);
      stream.next(m.estop);
      stream.next(m.motordisable);
      stream.next(m.alarmlog);
      stream.next(m.heartbeat);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct stat_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::htbot::stat_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::htbot::stat_<ContainerAllocator>& v)
  {
    s << indent << "speed: ";
    Printer<int8_t>::stream(s, indent + "  ", v.speed);
    s << indent << "trip: ";
    Printer<int8_t>::stream(s, indent + "  ", v.trip);
    s << indent << "time: ";
    Printer<int8_t>::stream(s, indent + "  ", v.time);
    s << indent << "maxspeed: ";
    Printer<float>::stream(s, indent + "  ", v.maxspeed);
    s << indent << "minspeed: ";
    Printer<float>::stream(s, indent + "  ", v.minspeed);
    s << indent << "avgspeed: ";
    Printer<float>::stream(s, indent + "  ", v.avgspeed);
    s << indent << "curspeed: ";
    Printer<float>::stream(s, indent + "  ", v.curspeed);
    s << indent << "totalruntime: ";
    Printer<float>::stream(s, indent + "  ", v.totalruntime);
    s << indent << "totaltriptime: ";
    Printer<float>::stream(s, indent + "  ", v.totaltriptime);
    s << indent << "totaldowntime: ";
    Printer<float>::stream(s, indent + "  ", v.totaldowntime);
    s << indent << "totalidletime: ";
    Printer<float>::stream(s, indent + "  ", v.totalidletime);
    s << indent << "uptime: ";
    Printer<float>::stream(s, indent + "  ", v.uptime);
    s << indent << "totaltripdist: ";
    Printer<float>::stream(s, indent + "  ", v.totaltripdist);
    s << indent << "avgvolt: ";
    Printer<float>::stream(s, indent + "  ", v.avgvolt);
    s << indent << "avgcurr: ";
    Printer<float>::stream(s, indent + "  ", v.avgcurr);
    s << indent << "maxcurr: ";
    Printer<float>::stream(s, indent + "  ", v.maxcurr);
    s << indent << "mincurr: ";
    Printer<float>::stream(s, indent + "  ", v.mincurr);
    s << indent << "amphr: ";
    Printer<float>::stream(s, indent + "  ", v.amphr);
    s << indent << "batlevel: ";
    Printer<float>::stream(s, indent + "  ", v.batlevel);
    s << indent << "tnumtrip: ";
    Printer<int16_t>::stream(s, indent + "  ", v.tnumtrip);
    s << indent << "clearops: ";
    Printer<int16_t>::stream(s, indent + "  ", v.clearops);
    s << indent << "estop: ";
    Printer<int16_t>::stream(s, indent + "  ", v.estop);
    s << indent << "motordisable: ";
    Printer<int16_t>::stream(s, indent + "  ", v.motordisable);
    s << indent << "alarmlog: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.alarmlog);
    s << indent << "heartbeat: ";
    Printer<int16_t>::stream(s, indent + "  ", v.heartbeat);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HTBOT_MESSAGE_STAT_H
