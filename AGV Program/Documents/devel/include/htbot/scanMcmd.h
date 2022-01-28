// Generated by gencpp from file htbot/scanMcmd.msg
// DO NOT EDIT!


#ifndef HTBOT_MESSAGE_SCANMCMD_H
#define HTBOT_MESSAGE_SCANMCMD_H

#include <ros/service_traits.h>


#include <htbot/scanMcmdRequest.h>
#include <htbot/scanMcmdResponse.h>


namespace htbot
{

struct scanMcmd
{

typedef scanMcmdRequest Request;
typedef scanMcmdResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct scanMcmd
} // namespace htbot


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::htbot::scanMcmd > {
  static const char* value()
  {
    return "fe363af63be51788db46af922590fcac";
  }

  static const char* value(const ::htbot::scanMcmd&) { return value(); }
};

template<>
struct DataType< ::htbot::scanMcmd > {
  static const char* value()
  {
    return "htbot/scanMcmd";
  }

  static const char* value(const ::htbot::scanMcmd&) { return value(); }
};


// service_traits::MD5Sum< ::htbot::scanMcmdRequest> should match 
// service_traits::MD5Sum< ::htbot::scanMcmd > 
template<>
struct MD5Sum< ::htbot::scanMcmdRequest>
{
  static const char* value()
  {
    return MD5Sum< ::htbot::scanMcmd >::value();
  }
  static const char* value(const ::htbot::scanMcmdRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::htbot::scanMcmdRequest> should match 
// service_traits::DataType< ::htbot::scanMcmd > 
template<>
struct DataType< ::htbot::scanMcmdRequest>
{
  static const char* value()
  {
    return DataType< ::htbot::scanMcmd >::value();
  }
  static const char* value(const ::htbot::scanMcmdRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::htbot::scanMcmdResponse> should match 
// service_traits::MD5Sum< ::htbot::scanMcmd > 
template<>
struct MD5Sum< ::htbot::scanMcmdResponse>
{
  static const char* value()
  {
    return MD5Sum< ::htbot::scanMcmd >::value();
  }
  static const char* value(const ::htbot::scanMcmdResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::htbot::scanMcmdResponse> should match 
// service_traits::DataType< ::htbot::scanMcmd > 
template<>
struct DataType< ::htbot::scanMcmdResponse>
{
  static const char* value()
  {
    return DataType< ::htbot::scanMcmd >::value();
  }
  static const char* value(const ::htbot::scanMcmdResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // HTBOT_MESSAGE_SCANMCMD_H