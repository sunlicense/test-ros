// Generated by gencpp from file htbot/mqueueRequest.msg
// DO NOT EDIT!


#ifndef HTBOT_MESSAGE_MQUEUEREQUEST_H
#define HTBOT_MESSAGE_MQUEUEREQUEST_H


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
struct mqueueRequest_
{
  typedef mqueueRequest_<ContainerAllocator> Type;

  mqueueRequest_()
    : cmd(0)
    , LP(0)
    , GN(0)
    , LPT(0)
    , gps()
    , lps()
    , pw()
    , tx(0.0)
    , ty(0.0)
    , tz(0.0)
    , rx(0.0)
    , ry(0.0)
    , rz(0.0)
    , rw(0.0)
    , prd(0.0)
    , pra(0.0)
    , psd(0.0)
    , psa(0.0)
    , prd1(0.0)
    , pra1(0.0)
    , psd1(0.0)
    , psa1(0.0)
    , align(0.0)
    , func(0.0)
    , trolley(0.0)
    , trolleydist(0.0)  {
    }
  mqueueRequest_(const ContainerAllocator& _alloc)
    : cmd(0)
    , LP(0)
    , GN(0)
    , LPT(0)
    , gps(_alloc)
    , lps(_alloc)
    , pw(_alloc)
    , tx(0.0)
    , ty(0.0)
    , tz(0.0)
    , rx(0.0)
    , ry(0.0)
    , rz(0.0)
    , rw(0.0)
    , prd(0.0)
    , pra(0.0)
    , psd(0.0)
    , psa(0.0)
    , prd1(0.0)
    , pra1(0.0)
    , psd1(0.0)
    , psa1(0.0)
    , align(0.0)
    , func(0.0)
    , trolley(0.0)
    , trolleydist(0.0)  {
  (void)_alloc;
    }



   typedef int16_t _cmd_type;
  _cmd_type cmd;

   typedef int8_t _LP_type;
  _LP_type LP;

   typedef int8_t _GN_type;
  _GN_type GN;

   typedef int8_t _LPT_type;
  _LPT_type LPT;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _gps_type;
  _gps_type gps;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _lps_type;
  _lps_type lps;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _pw_type;
  _pw_type pw;

   typedef float _tx_type;
  _tx_type tx;

   typedef float _ty_type;
  _ty_type ty;

   typedef float _tz_type;
  _tz_type tz;

   typedef float _rx_type;
  _rx_type rx;

   typedef float _ry_type;
  _ry_type ry;

   typedef float _rz_type;
  _rz_type rz;

   typedef float _rw_type;
  _rw_type rw;

   typedef float _prd_type;
  _prd_type prd;

   typedef float _pra_type;
  _pra_type pra;

   typedef float _psd_type;
  _psd_type psd;

   typedef float _psa_type;
  _psa_type psa;

   typedef float _prd1_type;
  _prd1_type prd1;

   typedef float _pra1_type;
  _pra1_type pra1;

   typedef float _psd1_type;
  _psd1_type psd1;

   typedef float _psa1_type;
  _psa1_type psa1;

   typedef float _align_type;
  _align_type align;

   typedef float _func_type;
  _func_type func;

   typedef float _trolley_type;
  _trolley_type trolley;

   typedef float _trolleydist_type;
  _trolleydist_type trolleydist;





  typedef boost::shared_ptr< ::htbot::mqueueRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::htbot::mqueueRequest_<ContainerAllocator> const> ConstPtr;

}; // struct mqueueRequest_

typedef ::htbot::mqueueRequest_<std::allocator<void> > mqueueRequest;

typedef boost::shared_ptr< ::htbot::mqueueRequest > mqueueRequestPtr;
typedef boost::shared_ptr< ::htbot::mqueueRequest const> mqueueRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::htbot::mqueueRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::htbot::mqueueRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::htbot::mqueueRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::htbot::mqueueRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::mqueueRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::htbot::mqueueRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::mqueueRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::htbot::mqueueRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::htbot::mqueueRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d5fb3bca17362751105a99da8eadab95";
  }

  static const char* value(const ::htbot::mqueueRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd5fb3bca17362751ULL;
  static const uint64_t static_value2 = 0x105a99da8eadab95ULL;
};

template<class ContainerAllocator>
struct DataType< ::htbot::mqueueRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "htbot/mqueueRequest";
  }

  static const char* value(const ::htbot::mqueueRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::htbot::mqueueRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int16 cmd\n\
int8 LP\n\
int8 GN\n\
int8 LPT\n\
string gps\n\
string lps\n\
string pw\n\
float32 tx\n\
float32 ty\n\
float32 tz\n\
float32 rx\n\
float32 ry\n\
float32 rz\n\
float32 rw\n\
float32 prd\n\
float32 pra\n\
float32 psd\n\
float32 psa\n\
float32 prd1\n\
float32 pra1\n\
float32 psd1\n\
float32 psa1\n\
float32 align\n\
float32 func\n\
float32 trolley\n\
float32 trolleydist\n\
";
  }

  static const char* value(const ::htbot::mqueueRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::htbot::mqueueRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.cmd);
      stream.next(m.LP);
      stream.next(m.GN);
      stream.next(m.LPT);
      stream.next(m.gps);
      stream.next(m.lps);
      stream.next(m.pw);
      stream.next(m.tx);
      stream.next(m.ty);
      stream.next(m.tz);
      stream.next(m.rx);
      stream.next(m.ry);
      stream.next(m.rz);
      stream.next(m.rw);
      stream.next(m.prd);
      stream.next(m.pra);
      stream.next(m.psd);
      stream.next(m.psa);
      stream.next(m.prd1);
      stream.next(m.pra1);
      stream.next(m.psd1);
      stream.next(m.psa1);
      stream.next(m.align);
      stream.next(m.func);
      stream.next(m.trolley);
      stream.next(m.trolleydist);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct mqueueRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::htbot::mqueueRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::htbot::mqueueRequest_<ContainerAllocator>& v)
  {
    s << indent << "cmd: ";
    Printer<int16_t>::stream(s, indent + "  ", v.cmd);
    s << indent << "LP: ";
    Printer<int8_t>::stream(s, indent + "  ", v.LP);
    s << indent << "GN: ";
    Printer<int8_t>::stream(s, indent + "  ", v.GN);
    s << indent << "LPT: ";
    Printer<int8_t>::stream(s, indent + "  ", v.LPT);
    s << indent << "gps: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.gps);
    s << indent << "lps: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.lps);
    s << indent << "pw: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.pw);
    s << indent << "tx: ";
    Printer<float>::stream(s, indent + "  ", v.tx);
    s << indent << "ty: ";
    Printer<float>::stream(s, indent + "  ", v.ty);
    s << indent << "tz: ";
    Printer<float>::stream(s, indent + "  ", v.tz);
    s << indent << "rx: ";
    Printer<float>::stream(s, indent + "  ", v.rx);
    s << indent << "ry: ";
    Printer<float>::stream(s, indent + "  ", v.ry);
    s << indent << "rz: ";
    Printer<float>::stream(s, indent + "  ", v.rz);
    s << indent << "rw: ";
    Printer<float>::stream(s, indent + "  ", v.rw);
    s << indent << "prd: ";
    Printer<float>::stream(s, indent + "  ", v.prd);
    s << indent << "pra: ";
    Printer<float>::stream(s, indent + "  ", v.pra);
    s << indent << "psd: ";
    Printer<float>::stream(s, indent + "  ", v.psd);
    s << indent << "psa: ";
    Printer<float>::stream(s, indent + "  ", v.psa);
    s << indent << "prd1: ";
    Printer<float>::stream(s, indent + "  ", v.prd1);
    s << indent << "pra1: ";
    Printer<float>::stream(s, indent + "  ", v.pra1);
    s << indent << "psd1: ";
    Printer<float>::stream(s, indent + "  ", v.psd1);
    s << indent << "psa1: ";
    Printer<float>::stream(s, indent + "  ", v.psa1);
    s << indent << "align: ";
    Printer<float>::stream(s, indent + "  ", v.align);
    s << indent << "func: ";
    Printer<float>::stream(s, indent + "  ", v.func);
    s << indent << "trolley: ";
    Printer<float>::stream(s, indent + "  ", v.trolley);
    s << indent << "trolleydist: ";
    Printer<float>::stream(s, indent + "  ", v.trolleydist);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HTBOT_MESSAGE_MQUEUEREQUEST_H
