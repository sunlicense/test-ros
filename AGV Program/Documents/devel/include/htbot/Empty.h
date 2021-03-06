// Generated by gencpp from file htbot/Empty.msg
// DO NOT EDIT!


#ifndef HTBOT_MESSAGE_EMPTY_H
#define HTBOT_MESSAGE_EMPTY_H

#include <ros/service_traits.h>


#include <htbot/EmptyRequest.h>
#include <htbot/EmptyResponse.h>


namespace htbot
{

struct Empty
{

typedef EmptyRequest Request;
typedef EmptyResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct Empty
} // namespace htbot


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::htbot::Empty > {
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::htbot::Empty&) { return value(); }
};

template<>
struct DataType< ::htbot::Empty > {
  static const char* value()
  {
    return "htbot/Empty";
  }

  static const char* value(const ::htbot::Empty&) { return value(); }
};


// service_traits::MD5Sum< ::htbot::EmptyRequest> should match 
// service_traits::MD5Sum< ::htbot::Empty > 
template<>
struct MD5Sum< ::htbot::EmptyRequest>
{
  static const char* value()
  {
    return MD5Sum< ::htbot::Empty >::value();
  }
  static const char* value(const ::htbot::EmptyRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::htbot::EmptyRequest> should match 
// service_traits::DataType< ::htbot::Empty > 
template<>
struct DataType< ::htbot::EmptyRequest>
{
  static const char* value()
  {
    return DataType< ::htbot::Empty >::value();
  }
  static const char* value(const ::htbot::EmptyRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::htbot::EmptyResponse> should match 
// service_traits::MD5Sum< ::htbot::Empty > 
template<>
struct MD5Sum< ::htbot::EmptyResponse>
{
  static const char* value()
  {
    return MD5Sum< ::htbot::Empty >::value();
  }
  static const char* value(const ::htbot::EmptyResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::htbot::EmptyResponse> should match 
// service_traits::DataType< ::htbot::Empty > 
template<>
struct DataType< ::htbot::EmptyResponse>
{
  static const char* value()
  {
    return DataType< ::htbot::Empty >::value();
  }
  static const char* value(const ::htbot::EmptyResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // HTBOT_MESSAGE_EMPTY_H
