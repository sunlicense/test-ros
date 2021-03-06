/*
 * This node is to do mapping using buttons  
 */
/* 	History
*		Date Modified : 24.11.2015
*		Changes :
*/

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <signal.h>
#include <termios.h>
#include <stdio.h>
#include "boost/thread/mutex.hpp"
#include "boost/thread/thread.hpp"
#include <tf/transform_listener.h>
#include <tf/transform_datatypes.h>
#include <geometry_msgs/TransformStamped.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_client_goal_state.h>
#include <actionlib/client/simple_action_client.h>
#include "htbot/Command.h"
#include "htbot/status.h"
#include "htbot/srvcmd.h"
#include "htbot/sendgoal.h"
#include "htbot/move.h"
#include "htbot/move_status.h"
//#include "htbot/dbcmd.h"
#include "htbot/Empty.h"
#include "htbot/mqueue.h"
#include "boost/algorithm/string.hpp"
#include "std_srvs/Empty.h"
#include "htbot/clear.h"
#include "htbot/debug.h"
#include <nav_msgs/GetPlan.h>
#include <geometry_msgs/PoseStamped.h>
#include "std_msgs/UInt16.h"
#include "std_msgs/Float32.h"
#include "std_msgs/String.h"
#include "htbot/sound.h"

using namespace std;
using namespace boost::algorithm;


class ArduinoNode
{
public:
	ArduinoNode();	
	void buttonCallback(const std_msgs::UInt16::ConstPtr& msg);
	void publish_debug(string s);
	void publish_status(string s);
	bool mqPush(int LP);
	bool dbRequest(int cmd,int LP);
	void publish_sound(int id);
	void voltCallback(const std_msgs::Float32::ConstPtr& msg);
	void publish_fButton(unsigned short cmd);
	bool butcmdServiceCallback(htbot::srvcmd::Request &req,htbot::srvcmd::Response &res);
	
	ros::Publisher debug_pub;
	ros::Publisher status_pub;
	ros::Publisher pos_pub;
	ros::Publisher play_pub;
	ros::Publisher fButton_pub;
	htbot::mqueue web_srv;
	ros::ServiceClient web_client;
	htbot::mqueue mq_srv;
	ros::ServiceClient mq_client;
	ros::ServiceServer but_service;

	double tx,ty,tz;
	double rx,ry,rz,rw;
	double prd,pra,prd1,pra1,psd,psa,psd1,psa1,align,func;
	string lpName;
	bool estop;

	// Arduino
	ros::Subscriber button_sub;



private:
	ros::NodeHandle nh;
	boost::mutex mut;
};

ArduinoNode::ArduinoNode()
{
	ros::NodeHandle nh;
	debug_pub = nh.advertise<htbot::debug>("debug",100);
	button_sub = nh.subscribe<std_msgs::UInt16>("button", 100, &ArduinoNode::buttonCallback,this);
	web_client = nh.serviceClient<htbot::mqueue>("web_cmd");
	mq_client = nh.serviceClient<htbot::mqueue>("mqueue");
	status_pub = nh.advertise<htbot::status>("feedback",100);
	pos_pub = nh.advertise<geometry_msgs::Twist>("cmd_pos", 1);
	play_pub = nh.advertise<htbot::sound>("sound", 1);
	but_service = nh.advertiseService("button_service",&ArduinoNode::butcmdServiceCallback,this); 

}

void ArduinoNode::publish_sound(int id)
{
	htbot::sound cmd;
	cmd.id = id;
	play_pub.publish(cmd);
	//ROS_INFO("Publish Sound AA");
	return;
}

void ArduinoNode::publish_status(string s)
{
	htbot::status status;
	status.msg = s;
	status_pub.publish(status);
	return;
}

void ArduinoNode::publish_fButton(unsigned short cmd)
{
	std_msgs::UInt16 msg;
	msg.data = cmd;
	fButton_pub.publish(msg);
	return;
}

bool ArduinoNode::dbRequest(int cmd,int LP) {
	bool ret;

	web_srv.request.GN = 0;  
	web_srv.request.LP = LP;  		
	web_srv.request.cmd = cmd;
			
	//ROS_INFO("dbReequest : %d. LP : %d ",cmd,LP);
		
	if (web_client.call(web_srv)) {
		//ROS_INFO("Received reply from dbase Server");
		if (web_srv.response.status == cmd) {	 
			//ROS_ERROR("call dbase service OK");	 		 
			tx = web_srv.response.tx;   	
			ty = web_srv.response.ty;
			tz = web_srv.response.tz;
			rx = web_srv.response.rx;   	
			ry = web_srv.response.ry;
			rz = web_srv.response.rz;
			rw = web_srv.response.rw;
			prd = web_srv.response.prd;
			pra = web_srv.response.pra;
			psd = web_srv.response.psd;
			psa = web_srv.response.psa;
			prd1 = web_srv.response.prd1;
			pra1 = web_srv.response.pra1;
			psd1 = web_srv.response.psd1;
			psa1 = web_srv.response.psa1;
			align = web_srv.response.align;
			func = web_srv.response.func;
			lpName = web_srv.response.lps;
			ret = true;
		} else {
	    ROS_ERROR("Failed to call web service");	
			ret = false;
	 	}
	}
	return ret;
}


bool ArduinoNode::mqPush(int LP) {
	bool ret;
  ROS_INFO("Arduino Push . LP : %d",LP);
	mq_srv.request.LP = LP;  		
	mq_srv.request.cmd = 1;
	mq_srv.request.tx = tx;	
	mq_srv.request.ty = ty;
	mq_srv.request.tz = tz;	
	mq_srv.request.rx = rx;	
	mq_srv.request.ry = ry;		
	mq_srv.request.rz = rz;	
	mq_srv.request.rw = rw;
	mq_srv.request.prd = prd;	
	mq_srv.request.pra = pra;	
	mq_srv.request.psd = psd;
	mq_srv.request.psa = psa;	
	mq_srv.request.prd1 = prd1;
	mq_srv.request.pra1 = pra1;	
	mq_srv.request.psd1 = psd1;	
	mq_srv.request.psa1 = psa1;
	mq_srv.request.align = align;
	mq_srv.request.func = func;
	mq_srv.request.lps = lpName;
		
	if (mq_client.call(mq_srv)) {
		if (mq_srv.response.status == 1) {	 
			ret = true;
			//ROS_INFO("Ar ok push to move queue");	
		} else {
	    ROS_ERROR("AR : Failed to push to move queue");	
			ret = false;
	 	}
	} else {
		ROS_INFO("AR mq_srv error");
	}
	return ret;
}

bool ArduinoNode::butcmdServiceCallback(htbot::srvcmd::Request &req,htbot::srvcmd::Response &res)
{
	switch (req.cmd) {
		case 11:
			ROS_INFO(" Button Service");
			if (dbRequest(32,req.cLP)) {
				mqPush(req.cLP);
				res.status = 11;
			} else {
				publish_status("Arduino : Button Command Error");
				res.status = 0;
			}			
			break;
	}
}


void ArduinoNode::buttonCallback(const std_msgs::UInt16::ConstPtr& msg)
{
	ros::NodeHandle rn; 
	int nGP, nLP, butNo;
	//bool ok;
	geometry_msgs::Twist pos;
	bool ok;
	char buf [100];
	string s;

	butNo = msg->data; 
	ROS_INFO("Arduino_Node : Button Code Received = %d",butNo);

	switch (butNo) {
		case 1:
			if (dbRequest(32,1)) {
				mqPush(1);
			} else {
				publish_status("Arduino : DB Error");
			}
			break;
		case 2:
			if (dbRequest(32,2)) {
				mqPush(2);
			} else {
				publish_status("Arduino : DB Error");
			}
			break;
		case 3:
			if (dbRequest(32,3)) {
				mqPush(3);
			} else {
				publish_status("Arduino : DB Error");
			}
			break;
		case 4:
			if (dbRequest(32,4)) {
				mqPush(4);
			} else {
				publish_status("Arduino : DB Error");
			}
			break;
		case 5:
			if (dbRequest(32,5)) {
				mqPush(5);
			} else {
				publish_status("Arduino : DB Error");
			}
			break;
		case 6:
			if (dbRequest(32,6)) {
				mqPush(6);
			} else {
				publish_status("Arduino : DB Error");
			}
			break;		
		case 7:
			if (dbRequest(32,7)) {
				mqPush(7);
			} else {
				publish_status("Arduino : DB Error");
			}
			break;
		case 8:
			if (dbRequest(32,8)) {
				mqPush(8);
			} else {
				publish_status("Arduino : DB Error");
			}
			break;
/*
		case 13: // robot charging now. Stop robot
			// stop robot.
			pos.angular.z = 0.0;
			pos.linear.x = 0.0;
			pos.linear.z = 7.0;  // 7.0
			pos_pub.publish(pos);
			publish_status("Docking Activated");
			publish_debug("Move Node : Docking Achieved.Stop Robot");
			break;
		case 15:
			// stop robot.
			pos.angular.z = 0.0;
			pos.linear.x = 0.0;
			pos.linear.z = 7.8;  // 7.0
			pos_pub.publish(pos);
			estop = true;
			rn.setParam("estop",estop);
			publish_status("Emergency Stop Activated");
			publish_debug("Move Node : Emergency Stop Activated");			
			publish_sound(15);		
			sleep(2);
			break;
		case 16:
			if (estop) {
				pos.angular.z = 0.0;
				pos.linear.x = 0.0;
				pos.linear.z = 7.9;  // 7.0
				pos_pub.publish(pos);
				publish_status("Emergency Stop Released");
				publish_debug("Move Node : Emergency Released");
				estop = false;
			}
			break;
*/
		case 20:  // shutdown
			ROS_INFO(" Recieved Shutdown from Button");
			publish_fButton(120); // inform audrino
			sleep(2);
			system("sudo shutdown -h now");
			break;
	}
	return;
}

void ArduinoNode::publish_debug(string s)
{
	htbot::debug deb;
	deb.msg = s;
	debug_pub.publish(deb);
	return;
}



int main(int argc, char **argv)
{
  ros::init(argc, argv, "Arduino node");  		
	ArduinoNode arNode;

  ROS_INFO("Arduino Node Running...");

	ros::MultiThreadedSpinner spinner(4);
  spinner.spin();
	
  return 0;
}


