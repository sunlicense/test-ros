/*
 * This node is to store debug messages 
 */
/* 	History
*		Date Modified : 31.7.2015
*		Changes :
*/

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <signal.h>
#include <stdio.h>
#include "boost/thread/mutex.hpp"
#include "boost/thread/thread.hpp"
#include <tf/transform_listener.h>
#include <tf/transform_datatypes.h>
#include <geometry_msgs/TransformStamped.h>
#include "htbot/move_status.h"
#include "htbot/status.h"
#include "boost/algorithm/string.hpp"
#include <math.h>
#include "htbot/sound.h"
#include "htbot/debug.h"


using namespace std;


ros::Subscriber debug;
ros::Publisher play_pub;
std::string filename;

// prototype
void publish_sound(int id);


void publish_sound(int id)
{
	htbot::sound cmd;
	cmd.id = id;
	play_pub.publish(cmd);
	//ROS_INFO("Debug: Publish SOund");
	return;
}

bool debugStore(const htbot::debug::ConstPtr& msg)
{
	FILE *fp;
	fp = fopen(filename.c_str(), "a");
	fprintf(fp,"%s\n",msg->msg.c_str())	;
	fclose(fp);	
  return true;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "Debug Node");
  ros::NodeHandle n;

	debug = n.subscribe<htbot::debug>("debug", 1000, debugStore);  // 
	play_pub = n.advertise<htbot::sound>("/sound", 100);
	n.getParam("/debug/filename",filename);
	//publish_sound(1);
  //ROS_INFO("Ready to Record Debug Messages.");
	
	
  ros::spin();

  return 0;
}



