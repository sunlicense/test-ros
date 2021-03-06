/*
 * This node is to queue node 
 */
/* 	History
*		Date Modified :13.5.2017
*		Changes :
*/

#include <ros/ros.h>
#include <signal.h>
#include <stdio.h>
#include "htbot/status.h"
#include "htbot/queue.h"
#include "htbot/mqueue.h"
#include "boost/algorithm/string.hpp"
#include "htbot/sound.h"
#include "htbot/debug.h"

#define MAXQ 100

using namespace std;
using namespace boost::algorithm;

class QNode
{
public:
	QNode(ros::NodeHandle rn);	
	bool qServiceCallback(htbot::mqueue::Request &req,htbot::mqueue::Response &res);	
	void publish_debug(string s);	
	void initialisation();
	void publish_sound(int id);
	void publish_queue(void);

	ros::ServiceServer qq_service;
	ros::Publisher debug_pub;
	ros::Publisher queue_pub;

  int cQP,nQP,noIQ,maxIQ;

	double tx,ty,tz;
	double rx,ry,rz,rw;
	double pre_dist,pre_angle,post_dist,post_angle;  // pre=before start. post=after reaching dest.
	double pre_dist1,pre_angle1,post_dist1,post_angle1;

	double qposeInfo[MAXQ][17];	
	int qLPInfo[MAXQ];	
	string LPString[MAXQ];
	ros::Publisher play_pub;


private:
	ros::NodeHandle nh;
};

QNode::QNode(ros::NodeHandle rn):
	rx(0.0),ry(0.0),rz(0.0),rw(0.0),
	tx(0.0),ty(0.0),tz(0.0),
  cQP(0),nQP(0),noIQ(0),maxIQ(MAXQ)

{
	ros::NodeHandle sn(rn);
	qq_service = nh.advertiseService("mqueue",&QNode::qServiceCallback,this); 
	debug_pub = sn.advertise<htbot::debug>("debug",100);
	queue_pub = sn.advertise<htbot::queue>("queue",100);
	play_pub = sn.advertise<htbot::sound>("sound", 100);
  nh.getParam("maxIQ",maxIQ);
}


void QNode::publish_sound(int id)
{
	htbot::sound cmd;
	cmd.id = id;
	play_pub.publish(cmd);
	return;
}


void QNode::initialisation() 
{	
	for (int i=0;i<MAXQ;i++) {
		qposeInfo[i][0] = 0.0;
    qposeInfo[i][1] = 0.0;
    qposeInfo[i][2] = 0.0;
    qposeInfo[i][3] = 0.0;
    qposeInfo[i][4] = 0.0;
    qposeInfo[i][5] = 0.0;
    qposeInfo[i][6] = 0.0;
    qposeInfo[i][7] = 0.0;
    qposeInfo[i][8] = 0.0;
    qposeInfo[i][9] = 0.0;
    qposeInfo[i][10] = 0.0;
    qposeInfo[i][11] = 0.0;
    qposeInfo[i][12] = 0.0;
    qposeInfo[i][13] = 0.0;
    qposeInfo[i][14] = 0.0;
		qposeInfo[i][15] = 0.0;
		qposeInfo[i][16] = 0.0;
		qLPInfo[i] = 99;  // no LP
		LPString[i] = "";
	}
}


void QNode::publish_debug(string s)
{
	htbot::debug deb;
	deb.msg = s;
	debug_pub.publish(deb);
	return;
}

void QNode::publish_queue(void)
{
	string s1,s2;
	int tcQP,tnQP,cnt;
	char buf [100];
	string s;
	double fx,fy,frz,frw;

	//ROS_INFO("Publish Queue");
	htbot::queue qmsg;
	tcQP = cQP;
	tnQP = nQP;
	cnt = 0;
	qmsg.fLP1 = "";
	qmsg.fLP2 = "";
	qmsg.fLP3 = "";
	if (noIQ > 0) {
		while(tcQP != tnQP) {
			qmsg.LPName = LPString[tcQP];			
			s1 = LPString[tcQP];
			fx = qposeInfo[tcQP][0];
			fy = qposeInfo[tcQP][1];
			frz = qposeInfo[tcQP][5];
			frw = qposeInfo[tcQP][6];
			sprintf(buf,"Station : %s. Pose : x=%.3f. y=%.3f. rz=%.3f. rw=%.3f",s1.c_str(),fx,fy,frz,frw);
			s.assign(buf,strlen(buf));		
			switch (cnt) {
				case 0:						
					qmsg.fLP1 = s;	
					break;
				case 1:
					qmsg.fLP2 = s;	
					break;
				case 2:
					qmsg.fLP3 = s;	
					break;
			}	 
			tcQP++;
			if (tcQP == MAXQ) {
				tcQP = 0;
			}
			cnt++;
		}
	} 
	qmsg.noQ = noIQ;
	queue_pub.publish(qmsg);
	return;
}

bool QNode::qServiceCallback(htbot::mqueue::Request &req,htbot::mqueue::Response &res)
{
	ROS_INFO("Queue Command Services"); 
	char buf [100];
	string s1;
	int cmd;
	ros::NodeHandle rn;  
	cmd = req.cmd;
  //ROS_INFO("numLP : %d.",numLP);
	switch (cmd) {	
    case 1:  // push to queue
			//ROS_INFO("Push : %d.",nQP);
      if (noIQ < maxIQ) {
        qposeInfo[nQP][0] = req.tx;
        qposeInfo[nQP][1] = req.ty;
        qposeInfo[nQP][2] = req.tz;
        qposeInfo[nQP][3] = req.rx;
        qposeInfo[nQP][4] = req.ry;
        qposeInfo[nQP][5] = req.rz;
        qposeInfo[nQP][6] = req.rw;
        qposeInfo[nQP][7] = req.prd;
        qposeInfo[nQP][8] = req.pra;
        qposeInfo[nQP][9] = req.psd;
        qposeInfo[nQP][10] = req.psa;
        qposeInfo[nQP][11] = req.prd1;
        qposeInfo[nQP][12] = req.pra1;
        qposeInfo[nQP][13] = req.psd1;
        qposeInfo[nQP][14] = req.psa1;
				qposeInfo[nQP][15] = req.align;
				qposeInfo[nQP][16] = req.func;
				qLPInfo[nQP] = req.LP;
				LPString[nQP] = req.lps;
        noIQ = noIQ + 1;
        nQP = nQP + 1;
        if (nQP == MAXQ) {
          nQP = 0;
        }
				rn.setParam("noIQ",noIQ);
				//ROS_INFO("Q noIP : %d. align : %.3f",noIQ,req.align);
        res.status = 1;  // ok
      } else {
        res.status = 0; // fail. maxIQ
      }
      break;	
		case 2: // pop from queue
      if ((cQP != nQP) && (noIQ > 0)) {
				//ROS_INFO("Pop : %d.",cQP);
        res.tx = qposeInfo[cQP][0];
        res.ty = qposeInfo[cQP][1];
        res.tz = qposeInfo[cQP][2];
        res.rx = qposeInfo[cQP][3];
        res.ry = qposeInfo[cQP][4];
        res.rz = qposeInfo[cQP][5];
        res.rw = qposeInfo[cQP][6];
        res.prd = qposeInfo[cQP][7];
        res.pra = qposeInfo[cQP][8];
        res.psd = qposeInfo[cQP][9];
        res.psa = qposeInfo[cQP][10];
        res.prd1 = qposeInfo[cQP][11];
        res.pra1 = qposeInfo[cQP][12];
        res.psd1 = qposeInfo[cQP][13];
        res.psa1 = qposeInfo[cQP][14];    
				res.align = qposeInfo[cQP][15];
				res.func = qposeInfo[cQP][16];      
				res.LP = qLPInfo[cQP];    
				res.lps = LPString[cQP]; 
        cQP = cQP + 1;
        if (cQP == MAXQ) {
          cQP = 0;
        }
        noIQ = noIQ - 1;
        res.nIQ = noIQ;
				rn.setParam("noIQ",noIQ);
        res.status = 1;  // pop is ok
      } else {
        res.status = 0;  // queue is empty
      }
			break;	
		case 3: // clear queue
      initialisation();
      noIQ = 0;
      cQP = 0;
      nQP = 0;
			rn.setParam("noIQ",noIQ);
      res.status = 1;
			break;	
	}  
	return true;
}


 
int main(int argc, char **argv)
{
  ros::init(argc, argv, "queue node");  
  ros::NodeHandle rn;  		
	QNode qNode(rn);
	ros::Rate loop_rate(1.0);
	qNode.initialisation();
	while (true) {  	  	 	
  	qNode.publish_queue();
		ros::spinOnce();	
  	loop_rate.sleep();
  }
  
  return 0;
}


