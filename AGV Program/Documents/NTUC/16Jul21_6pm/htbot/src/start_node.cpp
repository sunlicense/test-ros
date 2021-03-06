/*
 * This node is to launch node 
 */
/* 	History
*		Date Modified :8.7.2015
*		Changes :
*/

//#define ODROID
#define SSMC
//#define RAC

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <signal.h>
#include <stdio.h>
#include <tf/transform_listener.h>
#include <tf/transform_datatypes.h>
#include <geometry_msgs/TransformStamped.h>
#include "htbot/status.h"
#include "htbot/srvcmd.h"
#include "htbot/move.h"
//#include "htbot/dbcmd.h"
#include "boost/algorithm/string.hpp"

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

#include "std_msgs/UInt16.h"
#include "std_msgs/String.h"

#define NAVMODE 21
#define MAPMODE 20

using namespace std;
using namespace boost::algorithm;

class STNode
{
public:
	STNode(ros::NodeHandle rn);	

	void readParamfromFile();
	int getipaddr();
	void publish_toggleButton(unsigned short cmd);

	char *ipaddr;
	std::string paramfile;	
	int mapflag;
	ros::Publisher toggleButton_pub;
	std::string sdir,homedir;

private:
	ros::NodeHandle nh;
};

STNode::STNode(ros::NodeHandle rn)
	
{
	ros::NodeHandle sn(rn);
	nh.getParam("/stNode/param_file",paramfile);	
	toggleButton_pub = nh.advertise<std_msgs::UInt16>("toggle_button",100);
	nh.getParam("home_dir",homedir);
}

int STNode::getipaddr()
{
	int fd;
	struct ifreq ifr;
	
	fd = socket(AF_INET,SOCK_DGRAM,0);
	if (fd < 0) {
		return -1;
	}
	// get an ip4 ip addr	
	ifr.ifr_addr.sa_family = AF_INET;
	// ip addr attached to "wlan2"
	strncpy(ifr.ifr_name, "wlan2", IFNAMSIZ-1);
	
	ioctl(fd,SIOCGIFADDR, &ifr);
	close(fd);
	ipaddr = inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr);
	//printf("%s\n",inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
	//printf("%s\n",ipaddr);
	//ROS_INFO("DBase : %s",ipaddr);
}

void STNode::readParamfromFile()
{

	FILE *fp;
	ros::NodeHandle rn;  			

	//ROS_INFO("Param File : %s",paramfile.c_str());
	fp = fopen(paramfile.c_str(), "r");
  if (fp == NULL) {
  	ROS_INFO("I couldn't open paramdata.dat to read.\n");    
  	return;
  }
	// read mapping flag. 1=mapping done. 0=mapping not done
	fscanf(fp, "%d\n", &mapflag);	
	rn.setParam("mapflag",mapflag);
	if (mapflag == 77) {	
		publish_toggleButton(NAVMODE);
		//ROS_INFO("NavMode %d",NAVMODE);
		//system("gnome-terminal -x aplay /home/meiban/sound/navigation.wav");	
		//sleep(2);	
		sdir = homedir+"htbot_startnav.sh";
		//system("/home/racnys/htbot_startnav.sh");						
		//system(sdir.c_str());
	} else if (mapflag == 33) {	
		publish_toggleButton(MAPMODE);
		//ROS_INFO("MapMode %d",MAPMODE);
		sdir = homedir+"htbot_startmap.sh";
		//system(sdir.c_str());
		//system("/home/racnys/htbot_startmap.sh");			
	} 
	fclose(fp);	
}

void STNode::publish_toggleButton(unsigned short cmd)
{
	std_msgs::UInt16 msg;
	msg.data = cmd;
	toggleButton_pub.publish(msg);
	return;
}
 
int main(int argc, char **argv)
{
  ros::init(argc, argv, "Htbot Start Node");  
  ros::NodeHandle rn;  	
	int readyflag;
		
	STNode cNode(rn);	
	cNode.readParamfromFile();
	//cNode.getipaddr();
	//sleep(3);
	//ros::shutdown();
	ros::MultiThreadedSpinner spinner(4);
  spinner.spin();
  
  return 0;
}


