/*
 * This node is to service command request from websocket 
 */
/* 	History
*		Date Modified : 21.4.2021. 3pm
									: 5.5.21 2.45pm
									: 10.5.21 : 4.10 pm
                  : 20.5.21 : 11.30am
									: 24.5.21 : 10.45am
									: 15.6.21 : 7.00pm
									: 17.6.21 : 12pm
									: 18.6.21 : 2.30pm
*		Changes :
    19.5.21 : 5.40pm
    1. changed the detection of the legs to get alignment
    20.5.21 : 10.20am
    1. extended the scanning angle of front laser  
		24.5.21 : 10.45am
      1. Change 0.212 to 0.2. nleg > 2 to nleg > 4
    15.6.21 : 7pm
    	1. added checking for NaN and INF in detection of Right and Left Legs
		17.6.21 : 12pm
			1. increase nos of laser points to 5 instead of 3
		18.6.21 : 2.30pm
			1. changes to find shortest distance to leg
*/

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <signal.h>
#include <stdio.h>
#include <math.h>
#include <sensor_msgs/LaserScan.h>
#include "std_msgs/UInt16.h"
#include "std_msgs/Float32.h"
#include "std_msgs/String.h"

#define MAX_RANGEF 25.0
#define MIN_RANGEF 0.05  //0.03
#define SCANRANGE 1.2
#define RADPIDXF 0.0057596
#define MAX_RANGE 4.0
#define MIN_RANGE 0.04  //0.03
#define DWIDTH 0.3  //0.35// 0.4m
#define DBOX 2.0
#define DFRONT 0.02  //0.1
#define DEGPIDX 0.36
#define RADPIDX 0.006283
#define PI 3.14159
#define DM 77.9052 //28.07 // dm = atan(BOXL / BOXW) * (180.0 / PI);  // degree
#define DMIDX 216 //112  // (int)(dm / DEGPIDX)
#define DG  86 //70 // dg = atan(DWIDTH / DFRONT) * (180.0 / PI);  // degree
#define DGIDX 345 //280 // (int)(dg / DEGPIDX)
#define LASEROFFSET 0.03
#define BASEOFFSET 0.31
#define DISTGT350MM  0.6

#define FILTER_SCAN_SIZE 7
#define FILTER_SPIKE_SIZE 3
#define STEP 0.08  // m
#define FILTER_LEVEL_SIZE 0.04 // m

#define DEPTH_OF_OBJECT	0.1
#define NO_OF_POINTS 3

//#define BOXW	0.15
//#define BOXL  0.7

using namespace std;

ros::Subscriber laserF_sub;
ros::Subscriber laserR_sub;
ros::Subscriber laserL_sub;
//ros::Publisher scan_pub;
//ros::Publisher obs_pub;

int laserF_size;
int laserR_size;
int laserL_size;
int cidx,lidx,ridx;

bool rlegf,llegf;
bool rflag,lflag,fflag;
bool leginRzone,leginLzone,STARTDETECTLEG,STARTDETECTLEGFRONT,RESTARTDETECTLEGFRONT,LEFTLEGALIGN;
bool RightLeg,LeftLeg,trolley,TrolleyAlign;
int idx_data[50];
int rlegix,llegix;
double rlegdist,llegdist,rlan,llan;

double OUTLIMIT,INLIMIT,trolleyleg,BOXW,BOXL;

// prototype
void laserFCallBack(const sensor_msgs::LaserScan::ConstPtr& lscan);
void laserRCallBack(const sensor_msgs::LaserScan::ConstPtr& lscan);
void laserLCallBack(const sensor_msgs::LaserScan::ConstPtr& lscan);

void laserFCallBack(const sensor_msgs::LaserScan::ConstPtr& lscan) {	
	ros::NodeHandle nx;	
	double ld,shortest;
	int nleg,x;	
	
	
	nx.getParam("STARTDETECTLEGFRONT",STARTDETECTLEGFRONT);
	if (!STARTDETECTLEGFRONT) {
		//nx.setParam("TrolleyAlign",false);
		return;
	}
	nx.getParam("RESTARTDETECTLEGFRONT",RESTARTDETECTLEGFRONT);
	if (RESTARTDETECTLEGFRONT) {
		RESTARTDETECTLEGFRONT = false;	
		nx.setParam("RESTARTDETECTLEGFRONT",RESTARTDETECTLEGFRONT);
		rlegf = false;
		llegf = false;
	}
	nx.getParam("LEFTLEGALIGN",LEFTLEGALIGN);
	
	//ROS_INFO("--------- Trolley : Front Laser-------------------");
	laserF_size = lscan->ranges.size();
	cidx = (int)(laserF_size / 2.0);
	ridx = 140;  // around 45 deg
	lidx = 410;
	nleg = 0;
	// detect right leg
	
	if (!rlegf) {
		// find shortest ranges
		shortest = 1.3;
		//for (int i=cidx;i>ridx;i--) {
		for (int i=0;i<cidx;i++) {
			if (LEFTLEGALIGN) {
				if ((i>ridx) && (i<lidx)) {
					continue;
				}
			}
			if(!std::isnan(lscan->ranges[i]) && !std::isinf(lscan->ranges[i])){
				ld = lscan->ranges[i];			
				if ((ld > MIN_RANGEF) && (ld < shortest)) {
					shortest = ld;
				}
			}
		}
		//ROS_INFO("------------ Shortst Right : %.3f. ----------------",shortest);
		if (shortest < SCANRANGE) {
			//for (int i=cidx;i>ridx;i--) {
			for (int i=0;i<cidx;i++) {
				if (LEFTLEGALIGN) {
					if ((i>ridx) && (i<lidx)) {
						continue;
					}
				}
				if(!std::isnan(lscan->ranges[i]) && !std::isinf(lscan->ranges[i])){
					ld = lscan->ranges[i];					
					if ((ld > MIN_RANGEF) && (ld < (shortest+0.1))) {
						// detected leg
						idx_data[nleg] = i;
						nleg++;
					} 
				}
			}
			if (nleg > 2) {
				/*
				shortest = 2.0;
				for(int i=0;i<nleg;i++) {
					x = idx_data[i];
					ld = lscan->ranges[x];
					if (ld < shortest) {
						shortest = ld;
						rlegix = x;
					}		
				}
				if (shortest < 2.0) {
					rlegdist = shortest + 0.028;
				} else {
					ROS_INFO("---------- TrolleyNode : Error in Right Leg detection --------------");
					return;
				}
				*/
				x = (int)(nleg / 2.0);
				rlegix = idx_data[x];
				rlegdist = lscan->ranges[rlegix]+0.028; //0.212
				rlan = RADPIDXF * (cidx - rlegix);
				if(!std::isnan(rlegdist) && !std::isinf(rlegdist) && !std::isnan(rlan) && !std::isinf(rlan)) {
					rlegf = true;
					ROS_INFO("------- Detected Right Leg. id=%d. ld=%.3f an=%.3f -------",rlegix,rlegdist,rlan);
					nx.setParam("RightLegIdx",rlegix);
					nx.setParam("RightLegdist",rlegdist);
					nx.setParam("RightLegAngle",rlan);
				} else {
					ROS_INFO("------- Detected Right Leg Error : NaN & INF -----------");
				}
				//rlegf = true;
				//ROS_INFO("------- Detected Right Leg. id=%d. ld=%.3f an=%.3f -------",rlegix,rlegdist,rlan);
			}
		}
	}
	// detect left leg
	if (!llegf) {
		shortest = 1.3;
		for (int i=cidx;i<laserF_size;i++) {
			if (LEFTLEGALIGN) {
				if ((i>ridx) && (i<lidx)) {
					continue;
				}
			}
			if(!std::isnan(lscan->ranges[i]) && !std::isinf(lscan->ranges[i])){
				ld = lscan->ranges[i];
				if ((ld > MIN_RANGEF) && (ld < shortest)) {
					shortest = ld;
				}
			}
		}
		//ROS_INFO("------------ Shortst Left : %.3f. ----------------",shortest);
		nleg = 0;
		//llegf = false;
		if (shortest < SCANRANGE) {
			for (int i=cidx;i<laserF_size;i++) {
				if (LEFTLEGALIGN) {
					if ((i>ridx) && (i<lidx)) {
						continue;
					}
				}
				if(!std::isnan(lscan->ranges[i]) && !std::isinf(lscan->ranges[i])){
					ld = lscan->ranges[i];
					if ((ld > MIN_RANGEF) && (ld < (shortest+0.1))) {
						// detected leg
						//ROS_INFO("------- LL : range=%.3f. i=%d-------------",ld,i);
						idx_data[nleg] = i;
						nleg++;
					} 
				}
			}
			if (nleg > 2) {
				/*
				shortest = 2.0;
				for(int i=0;i<nleg;i++) {
					x = idx_data[i];
					ld = lscan->ranges[x];
					if (ld < shortest) {
						shortest = ld;
						llegix = x;
					}		
				}
				if (shortest < 2.0) {
					llegdist = shortest + 0.028;
				} else {
					ROS_INFO("---------- TrolleyNode : Error in Left Leg detection --------------");
					return;
				}
				*/
				x = (int)(nleg / 2.0);
				llegix = idx_data[x];
				llegdist = lscan->ranges[llegix]+0.028;
				llan = RADPIDXF * (llegix - cidx);
				if(!std::isnan(llegdist) && !std::isinf(llegdist) && !std::isnan(llan) && !std::isinf(llan)) {
					llegf = true;
					ROS_INFO("------- Detected Left Leg. id=%d. ld=%.3f an=%.3f -------",llegix,llegdist,llan);
					nx.setParam("LeftLegIdx",llegix);
					nx.setParam("LeftLegdist",llegdist);
					nx.setParam("LeftLegAngle",llan);
				} else {
					ROS_INFO("------- Detected Left Leg Error : NaN & INF -----------");
				}
				//llegf = true;
				//ROS_INFO("------- Detected Left Leg. id=%d. ld=%.3f an=%.3f -------",llegix,llegdist,llan);
			}
		}
	}
	if (rlegf && llegf) {
		//ROS_INFO("----------- Trolley Front.-----------");
		nx.setParam("TrolleyAlign",true);
		//nx.setParam("RightLegIdx",rlegix);
		//nx.setParam("RightLegdist",rlegdist);
		//nx.setParam("RightLegAngle",rlan);
		//nx.setParam("LeftLegIdx",llegix);
		//nx.setParam("LeftLegdist",llegdist);
		//nx.setParam("LeftLegAngle",llan);
		STARTDETECTLEGFRONT = false;
		nx.getParam("STARTDETECTLEGFRONT",STARTDETECTLEGFRONT);
	} 
}

void laserRCallBack(const sensor_msgs::LaserScan::ConstPtr& lscan) {	
	ros::NodeHandle nx;	
	double ld,ld1,ld2,ld3,degperindx,rr,an,radperindx,dm;
	int nleg,nrleg;
	
	nx.getParam("STARTDETECTLEG",STARTDETECTLEG);
	if (!STARTDETECTLEG) {
		RightLeg = false;
		//nx.setParam("RightZone",false);
		nx.setParam("RightLeg",RightLeg);
		rflag = false;
		return;
	}

	nx.getParam("BOXW",BOXW);
	nx.getParam("BOXL",BOXL);
	laserR_size = lscan->ranges.size();
	degperindx = 180.0 / laserR_size;
	radperindx = degperindx * (PI / 180.0);	
	cidx = (int)(laserR_size / 2.0);
	dm = atan(BOXL / BOXW) * (180.0 / PI);
	ridx = (int)(dm / degperindx) + cidx ; 
	if (!rflag) {
		rflag = true;
		ROS_INFO("--- RLaser : BOXW=%.3f. BOXL=%.3f. trolleyleg=%.2f. ------",BOXW,BOXL,trolleyleg);
		ROS_INFO("--- RLaser : size=%d. cidx=%d. degidx=%.3f. radidx=%.3f. ridx=%d. dm=%.3f -------",laserR_size,cidx,degperindx,radperindx,ridx,dm);
	}
			
	// look for trolley legs
	//ROS_INFO("--- Right Laser : BOXW=%.3f. BOXL=%.3f. trolleyleg=%.2f. ------",BOXW,BOXL,trolleyleg);
	leginRzone = false;
	nleg = 0;
	for (int i=cidx;i<ridx;i++) {
		// right laser
		if(!std::isnan(lscan->ranges[i]) && !std::isinf(lscan->ranges[i])){
			ld = lscan->ranges[i];
			an = (i-cidx) * radperindx;
			rr = (double)(BOXW / cos(an));			
			if (ld < rr) {
				nleg++;
				if (nleg >= 2) {
					leginRzone = true;
					break;
				}
			}
		}
	}
	
	if (!RightLeg) {
		ld = MAX_RANGE;
		nrleg = 0;
		RightLeg = false;
		for (int i=cidx;i<cidx+24;i++) {
			if(!std::isnan(lscan->ranges[cidx]) && !std::isinf(lscan->ranges[cidx])){
				ld = lscan->ranges[i];
				if (ld < trolleyleg) {
					nrleg++;
					//if (nrleg > 15) {
					if (nrleg > 1) {
						RightLeg = true;
						//nx.setParam("RightLeg",RightLeg);	
						ROS_INFO("\n****************** Trolley : RightLeg Detected. ***********************\n");	
						break;
					}
				}
			}
		}
		nx.setParam("RightLeg",RightLeg);	
		
	}
	if (leginRzone) {
		nx.setParam("RightZone",true);	
		//ROS_INFO("----------- Trolley : RightZone Detected ----------");
		return;
	}
	nleg = 0;
	for (int i=ridx;i<laserR_size;i++) {
		// right laser
		if(!std::isnan(lscan->ranges[i]) && !std::isinf(lscan->ranges[i])){
			ld = lscan->ranges[i];
			an = (i-cidx) * radperindx;
			rr = (double)(BOXL / sin(an));			
			if (ld < rr) {
				nleg++;
				if (nleg >= 2) {
					leginRzone = true;
					break;
				}
			}
		}
	}
	if (leginRzone) {
		nx.setParam("RightZone",true);	
		//ROS_INFO("----------- Trolley : RightZone Detected ----------");
	} else {
		nx.setParam("RightZone",false);
		//ROS_INFO("----------- Trolley : RightZone Clear ----------");
	}
	
}

void laserLCallBack(const sensor_msgs::LaserScan::ConstPtr& lscan) {	
	ros::NodeHandle nx;	
	double ld,ld1,ld2,ld3,degperindx,rr,an,radperindx,dm;
	int nleg,nlleg;
	
	nx.getParam("STARTDETECTLEG",STARTDETECTLEG);
	if (!STARTDETECTLEG) {
		LeftLeg = false;
		nx.setParam("LeftLeg",LeftLeg);	
		//nx.setParam("LeftZone",false);
		lflag = false;
		return;
	}
	nx.getParam("BOXW",BOXW);
	nx.getParam("BOXL",BOXL);		

	laserL_size = lscan->ranges.size();
	degperindx = 180.0 / laserL_size;
	radperindx = degperindx * (PI / 180.0);
	cidx = (int)(laserL_size / 2.0);
	dm = atan(BOXW / BOXL) * (180.0 / PI);
	lidx = (int)(dm / degperindx) ; 
	
	if (!lflag) {
		lflag = true;
		ROS_INFO("--- LLaser : BOXW=%.3f. BOXL=%.3f. trolleyleg=%.2f. ------",BOXW,BOXL,trolleyleg);
		ROS_INFO("--- LLaser : size=%d. cidx=%d. degidx=%.3f. radidx=%.3f. lidx=%d. dm=%.3f --------",laserL_size,cidx,degperindx,radperindx,lidx,dm);
	}
	
	// look for trolley legs
	//ROS_INFO("--- Left Laser : BOXW=%.3f. BOXL=%.3f. trolleyleg=%.2f. ------",BOXW,BOXL,trolleyleg);
	leginLzone = false;
	nleg = 0;
	for (int i=0;i<lidx;i++) {
		// left laser
		if(!std::isnan(lscan->ranges[i]) && !std::isinf(lscan->ranges[i])){
			ld = lscan->ranges[i];
			an = (i) * radperindx;
			rr = (double)(BOXL / cos(an));			
			if (ld < rr) {
				nleg++;
				if (nleg >= 2) {
					leginLzone = true;
					break;
				}
			}
		}
	}
	if (!LeftLeg) {
		ld3 = MAX_RANGE;
		nlleg = 0;
		LeftLeg = false;
		for (int i=cidx-24;i<cidx;i++) {
			if(!std::isnan(lscan->ranges[cidx]) && !std::isinf(lscan->ranges[cidx])){
				ld = lscan->ranges[i];
				if (ld < trolleyleg) {
					nlleg++;
					//if (nlleg > 15) {
					if (nlleg > 1) {
						LeftLeg = true;
						//nx.setParam("LeftLeg",LeftLeg);	
						ROS_INFO("\n****************** Trolley : LeftLeg Detected. ***********************\n");	
						break;
					}
				}
			}
		}
		nx.setParam("LeftLeg",LeftLeg);	
		/*
		if(!std::isnan(lscan->ranges[cidx-3]) && !std::isinf(lscan->ranges[cidx-3])){
			ld3 = lscan->ranges[cidx-3];
		}
		ld = MAX_RANGE;
		if(!std::isnan(lscan->ranges[cidx-2]) && !std::isinf(lscan->ranges[cidx-2])){
			ld = lscan->ranges[cidx-2];
		}
		ld1 = MAX_RANGE;
		if(!std::isnan(lscan->ranges[cidx-1]) && !std::isinf(lscan->ranges[cidx-1])){
			ld1 = lscan->ranges[cidx-1];
		}
		ld2 = MAX_RANGE;
		if(!std::isnan(lscan->ranges[cidx]) && !std::isinf(lscan->ranges[cidx])){
			ld2 = lscan->ranges[cidx];
		}
		//ROS_INFO("--- LLASER : ld=%.2f. ld1=%.2f. ld2=%.2f. trolleyleg=%.2f ------",ld,ld1,ld2,trolleyleg);
		if ((ld < trolleyleg) || (ld1 < trolleyleg) || (ld2 < trolleyleg) || (ld3 < trolleyleg)){
			// hit leg of trolley
			LeftLeg = true;
			nx.setParam("LeftLeg",LeftLeg);	
			ROS_INFO("\n***************** Trolley : LeftLeg Detected ***********************\n");			
		} else {
			//nx.setParam("LeftLeg",false);	
		}
		*/
	}
	if (leginLzone) {
		nx.setParam("LeftZone",true);	
		//ROS_INFO("----------- Trolley : LeftZone Detected ----------");
		return;
	} 
	nleg = 0;
	for (int i=lidx;i<cidx;i++) {
		// left laser
		if(!std::isnan(lscan->ranges[i]) && !std::isinf(lscan->ranges[i])){
			ld = lscan->ranges[i];
			an = (i) * radperindx;
			rr = (double)(BOXW / sin(an));			
			if (ld < rr) {
				nleg++;
				if (nleg >= 2) {
					leginLzone = true;
					break;
				}
			}
		}
	}
	if (leginLzone) {
		nx.setParam("LeftZone",true);	
		//ROS_INFO("----------- Trolley : LeftZone Detected ----------");
	} else {
		nx.setParam("LeftZone",false);
		//ROS_INFO("----------- Trolley : LeftZone Clear ----------");
	}
	
}

void TrolleyAlignmentCallBack(const sensor_msgs::LaserScan::ConstPtr& lscan) {	
	ros::NodeHandle nx;	
	double ld,shortest,bx,ax;
	int nleg,x,sc,pp;	
	double objdataRange[100];
	double objdataAngle[100];
	double scandata[1000];
	int start,sx,ex,cn,t;
	FILE *pfp;
	
	
	nx.getParam("STARTDETECTLEGFRONT",STARTDETECTLEGFRONT);
	if (!STARTDETECTLEGFRONT) {
		//nx.setParam("TrolleyAlign",false);
		return;
	}
	
	laserF_size = lscan->ranges.size();
	cidx = (int)(laserF_size / 2.0);
	ROS_INFO("--------- Trolley Node : New Alignment using Front Laser size = %d-------------------",laserF_size);
		
	for (int i=0;i<laserF_size;i++) {
		if(!std::isnan(lscan->ranges[i]) && !std::isinf(lscan->ranges[i]) && (lscan->ranges[i] > MIN_RANGEF) && (lscan->ranges[i] < MAX_RANGEF)){
			scandata[i] = lscan->ranges[i];			
		} else {
			scandata[i] = MAX_RANGEF;
		}
	}
	for(int i=0;i<laserF_size;i=i+1) {
    ld = scandata[i];
    if (ld == MAX_RANGEF) {
     	if ( (i>0) && (i<(laserF_size-1)) ) {
   			ld = ((scandata[i-1] + scandata[i+1])/2.0);
     	} else if (i>0) {
        ld = ((scandata[i-2] + scandata[i-1])/2.0);
      } else {
       	ld = ((scandata[i+1] + scandata[i+2])/2.0);
      }
    }
   	scandata[i] = ld;
  }
	start = 0;
	cn = 0;
	ex = 0;
	sx = 0;
	t = 0;
	for (int i=0;i<laserF_size;i++) {		
		ld = scandata[i];					
		if (start == 0) {
    	bx = ld;
      start = 1;
      continue;
    }
		ax = ld;
		if (ax < bx) {
    	if ((bx-ax) > DEPTH_OF_OBJECT) {
    		// start edge of object
     		sx = i;
    	}
    } else {
      if ( ((ax-bx) > DEPTH_OF_OBJECT) && (sx > 0) && (cn > NO_OF_POINTS) ) {
      	// end edge
        ex = i;
        ex = (int)((sx + ex) / 2.0);
				objdataAngle[t] = (double)(RADPIDXF * ex);
        objdataRange[t] = scandata[ex];    
				ROS_INFO("------------ cn = %d. ---------------------",cn);
				t++;    		
        ex = 0;
        sx = 0;
        cn = 0;
      }
   	}
		if (sx > 0) {
    	cn++;
    }
    bx = ax;
	}
	
	if (t > 1) {
		pfp = fopen("/home/rac/catkin_ws/src/htbot/data/trolley.txt", "w+");  // w : open new file

  	if (pfp == NULL) {
  		ROS_INFO("I couldn't open trolley.txt for writing.\n");    
  		return;
 	 	}
		ROS_INFO("------------ Trolley Node : Save Trolley Legs Info to File. noLeg : %d. ----------------",t);
		x = 0;
		for (int j=0;j<t;j++) {
			ax = objdataAngle[j];
			ld = objdataRange[j];
			ROS_INFO("----------- Legs : %d. Angle : %.3f. Range = %.3f. -------------",j,ax,ld);
			if (ld > 1.5) {
				continue;
			}
			x++;			
			//fprintf(pfp," Leg : %d. Angle : %.3f. Range = %.3f. \n",j,ax,ld);				
			fprintf(pfp,"%.3f %.3f\n",ax,ld);	
		}	
  	fclose(pfp);	
		STARTDETECTLEGFRONT = false;
		nx.setParam("STARTDETECTLEGFRONT",STARTDETECTLEGFRONT);
		nx.setParam("TrolleyAlignCount",x);
		nx.setParam("TrolleyAlign",true);
	}
}


int main(int argc, char **argv)
{
	ros::init(argc, argv, "laser_trolley");
  ros::NodeHandle n;
	
	//n.setParam("MainLaserStatus",0);	
	OUTLIMIT = 1.5;
	INLIMIT = 0.5;
	trolleyleg = 0.5;
	n.getParam("OUTLIMIT",OUTLIMIT);
	n.getParam("INLIMIT",INLIMIT);
	n.getParam("trolleyleg",trolleyleg);
	
	ROS_INFO("---------- Trolley : trolleyleg = %.2f. -----------",trolleyleg);
	rflag = false;
	lflag = false;
	fflag = false;
	rlegf = false;
	llegf = false;
	leginRzone = false;
	leginLzone = false;
	RightLeg = false;
	LeftLeg = false;
	STARTDETECTLEG = false;
	STARTDETECTLEGFRONT = false;
	RESTARTDETECTLEGFRONT = false;
	TrolleyAlign = false;
	n.setParam("TrolleyAlign",TrolleyAlign);
	n.setParam("STARTDETECTLEGFRONT",STARTDETECTLEGFRONT);

	laserF_sub= n.subscribe<sensor_msgs::LaserScan>("/scanF",100, laserFCallBack);	 // /scan_base - org
	//laserR_sub= n.subscribe<sensor_msgs::LaserScan>("/scanRt",100, laserRCallBack);
	//laserL_sub= n.subscribe<sensor_msgs::LaserScan>("/scanLt",100, laserLCallBack);
	//scan_pub = n.advertise<sensor_msgs::LaserScan>("scanx", 10);
	//laserF_sub= n.subscribe<sensor_msgs::LaserScan>("/scanF",100, TrolleyAlignmentCallBack);	 // /scan_base - org
  ros::spin();

  return 0;
}



