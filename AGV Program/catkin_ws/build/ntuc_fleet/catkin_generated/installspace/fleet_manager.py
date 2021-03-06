#!/usr/bin/env python2
# Tkinter tkinter
from Tkinter import Tk, Frame, Label, Button, Entry, IntVar, END, W, E, StringVar, SUNKEN, BOTH, OptionMenu
from opcua import Server, ua
from opcua import Client		## Client to Lift Controller opcua
import time
import threading 
import rospy
import json
import pickle				## file serialization
from ntuc_fleet.msg import *

##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####  
##### fleet_manager.py ##### Reside in fleet manager #####   
##### -- Read ROS messages from call stations and update to OPCUA server parameters #####
##### -- Read OPC parameters from OPCUA server and send ROS messages to call stations #####
##### -- OPCUA client to Lift Controller, activate/deactivate beacon alarm  #####
##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####

##### CONSTANTS DEFINITION #####
DUMMY = 0

##### Initialize ROS Node #####
rospy.init_node('fleet_manager', anonymous=True)

##### Declare global ROS Publishers #####
pub_jobs = rospy.Publisher('rv_jobs', jobs, queue_size=10)
pub_status = rospy.Publisher('to_station', agv_status, queue_size=10)
## pub_task = rospy.Publisher('task', task, queue_size=10)	## dummy publisher, not used here

##### Global Lists to for tasks #####
task_Q = []			## queue of tasks
delete_Q = []		## tasks earmarked for deletion
unassigned_Q = []	## not used

##### Global Variables #####
task1_completed=False	## task assigned to AGV1 completed
ready4task1=False			## AGV1 ready for new task
task2_completed=False	## task assigned to AGV2 completed
ready4task2=False			## AGV2 ready for new task
last_time=rospy.Time.now().secs		## last ROS time
task_cmd_changed=False	## task cmd changed?


##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####
##### Establish connection to OPC server objects @ Lift Controller #####
##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####
##### OPC Server IP address and TCP port #####
"""
address = rospy.get_param("OPC_SERVER_ADDRESS")	# Get from ROS Launch File
url = "opc.tcp://"+address					# OPC Server URL

client = Client(url)
client.connect()
print("Connected to OPC Server @ %s" % address)
root = client.get_root_node()

varBeacon = root.get_child(["0:Objects", "2:Parameters", "2:Beacon"])
"""

##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####
##### ROS Listener callback for /rq_jobs topic, ntuc_fleet/jobs #####
##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####
def rq_jobs_callback(msg):
	global last_time, task_cmd_changed
	## rospy.loginfo("Input Received %d, toLP=%d", msg.cmd, msg.toLP);

	if msg.cmd==1:	## not used
		pass
	elif msg.cmd==2:	## request for task list
		task_cmd_changed=True	## force task list to be published to call stations
		print("task_cmd_changed=True")

rospy.Subscriber('rq_jobs', jobs, rq_jobs_callback)	

##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####
##### ROS Listener callback for /fr_station topic, ntuc_fleet/task #####
##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####
def fr_station_callback(msg):
	global last_time, task_cmd_changed, varBeacon
	## rospy.loginfo("Input Received %d, toLP=%d", msg.cmd, msg.toLP);

	if msg.cmd==1:	## new task
		rospy.loginfo("cmd %d, type %d, fromLP %d, toLP %d", msg.cmd, msg.type, msg.fromLP, msg.toLP);
		## Ensure unique time.secs field
		if (rospy.Time.now().secs<=last_time):
			time.sleep(1)
		## Add new task to task_Q
		task_Q.append([msg.cmd, rospy.Time.now().secs, msg.type, msg.fromLP, msg.toLP])
                # Update new task received
                # my_opc_server.task1_parameter.set_value([msg.cmd, msg.time.secs, msg.type, msg.fromLP, msg.toLP])
		last_time=rospy.Time.now().secs		## update last_time	
	elif msg.cmd==2:	## request for task list (another option)
		task_cmd_changed=True	## force task list to be published to call stations
	elif msg.cmd==3:	## cancel task
		rospy.loginfo("cmd %d, type %d, fromLP %d, toLP %d", msg.cmd, msg.type, msg.fromLP, msg.toLP);
		## Add cancelled task to delete_Q
		delete_Q.append([msg.cmd, msg.time.secs, msg.type, msg.fromLP, msg.toLP])	# preserve time
		### my_opc_server.task1_parameter.set_value([msg.cmd, msg.time.secs, msg.type, msg.fromLP, msg.toLP])	
	elif msg.cmd==4:	## deactivate L11 Kitchen beacon alarm 
		rospy.loginfo("cmd %d, type %d, fromLP %d, toLP %d", msg.cmd, msg.type, msg.fromLP, msg.toLP);
		print("DeActivate Beacon")
		my_opc_server.beaconalarm_parameter.set_value(0)
		varBeacon.set_value([8,0])		

	elif msg.cmd==5:	## activate L11 Kitchen beacon alarm
		rospy.loginfo("cmd %d, type %d, fromLP %d, toLP %d", msg.cmd, msg.type, msg.fromLP, msg.toLP);
		print("Activate Beacon")
		my_opc_server.beaconalarm_parameter.set_value(1)
		varBeacon.set_value([8,1])			

rospy.Subscriber('fr_station', task, fr_station_callback)	

					
##### ##### ##### ##### ##### ##### ##### #####  ##### 
#####   OPC Server Class with Tkinker GUI Frame as argument #####
##### ##### ##### ##### ##### ##### ##### #####  ##### 
class OPCServer(Frame):

##### ##### ##### ##### ##### ##### ##### #####  ##### 
##### Method:  Constructor #####
##### ##### ##### ##### ##### ##### ##### #####  ##### 
	def __init__(self, master=None):
		Frame.__init__(self, master)               
		self.master = master
		self.bCloseThreadFlag = False
		self.bServerStarted = False
#        self.curTask=[0,0,0,0,0]
		self.task_cmd = IntVar(0)
		self.task_type = IntVar(0)
		self.task_fromLP = IntVar(0)
		self.task_toLP = IntVar(0)
		self.completed_cmd = IntVar(0)
		self.completed_type = IntVar(0)
		self.completed_fromLP = IntVar(0)
		self.completed_toLP = IntVar(0)
		# self.updatedFireAlarm = 0
		self.updatedFireAlarm = IntVar()
		# self.updatedBeaconAlarm = 0
		self.updatedBeaconAlarm = IntVar()
		self.init_window()
		self.server = Server()
		self.url = "opc.tcp://127.0.0.1:4845"
		# self.url = "opc.tcp://192.168.1.166:4840"
		self.server.set_endpoint(self.url)
		self.name = "OPCUA_FLEET_SERVER"
		self.addspace = self.server.register_namespace(self.name)
		self.rootnode = self.server.get_objects_node()                              # root node
		self.parameters = self.rootnode.add_object(self.addspace, "Parameters")     # parameters node
		# OPCUA Parameters
		self.firealarm_parameter = self.parameters.add_variable(self.addspace, "FireAlarm", 0,  ua.VariantType.Byte)            # fire alarm parameter
		self.beaconalarm_parameter = self.parameters.add_variable(self.addspace, "BeaconAlarm", 0, ua.VariantType.Byte)   		# beacon alarm parameter
		self.heartbeat1_parameter = self.parameters.add_variable(self.addspace, "Heartbeat1", 0, ua.VariantType.Byte)   		# heartbeat for AGV1 parameter
		self.heartbeat2_parameter = self.parameters.add_variable(self.addspace, "Heartbeat2", 0, ua.VariantType.Byte)   		# heartbeat for AGV2 parameter
		self.task1_parameter = self.parameters.add_variable(self.addspace, "Task1", ua.Variant([0,0,0,0,0], ua.VariantType.Byte))
		self.task2_parameter = self.parameters.add_variable(self.addspace, "Task2", ua.Variant([0,0,0,0,0], ua.VariantType.Byte))
		self.taskCompleted_parameter = self.parameters.add_variable(self.addspace, "TaskCompleted", ua.Variant([0,0,0,0,0], ua.VariantType.Byte))
		self.status1_parameter = self.parameters.add_variable(self.addspace, "Status1", ua.Variant([0,0,0,0,0,0,0,0,0], ua.VariantType.Byte))
		self.status2_parameter = self.parameters.add_variable(self.addspace, "Status2", ua.Variant([0,0,0,0,0,0,0,0,0], ua.VariantType.Byte))
		# OPCUA Client Writable Parameters
		self.heartbeat1_parameter.set_writable()	## AGV1
		self.heartbeat2_parameter.set_writable()	## AGV2
		self.task1_parameter.set_writable()			## AGV1
		self.task2_parameter.set_writable()			## AGV1		
		self.taskCompleted_parameter.set_writable()
		self.status1_parameter.set_writable()		## AGV1
		self.status2_parameter.set_writable()		## AGV1

##        self.server.start()
##        print("OPC Server Started")
##        self.bServerStarted = True    
       
##### ##### ##### ##### ##### ##### ##### #####  ##### 
##### Method:  Creation of GUI window #####
##### ##### ##### ##### ##### ##### ##### #####  #####         
	# Creation of init_window
	def init_window(self):
		# changing the title of our master widget      
		self.master.title("Fleet Manager OPC Server")

		# allowing the widget to take the full space of the root window
		self.pack(fill=BOTH, expand=1)
		self.status = StringVar()
		self.status.set("Ready")

		# Widgets
		self.start_button = Button(self, text="Start OPC Server", command=lambda: self.update("start"))
		self.start_button.configure(state = 'active')
		self.stop_button = Button(self, text="Stop OPC Server", command=lambda: self.update("stop"))
		self.stop_button.configure(state = 'disabled')
		self.close_button = Button(self, text="Close", command=lambda: self.update("close"))

		vcmdFA = self.register(self.validateFA) # we have to wrap the command
		vcmdBA = self.register(self.validateBA) # we have to wrap the command

		self.firealarmLabel = Label(self, text="Fire Alarm")
		self.beaconalarmLabel = Label(self, text="Beacon Alarm")
		self.firealarmEntry = Entry(self, validate = 'key', validatecommand = (vcmdFA, '%P'), text=self.updatedFireAlarm)
		self.beaconalarmEntry = Entry(self, validate = 'key', validatecommand = (vcmdBA, '%P'), text=self.updatedBeaconAlarm)
		self.updatedFireAlarm = 0
		self.updatedBeaconAlarm = 0
		self.update_button = Button(self, text="Update Parameters", command=lambda: self.update("update"))
		self.update_button.configure(state = 'disabled')
		self.status_display = Label(self, bd=1, width=55, relief=SUNKEN, anchor=W, textvariable=self.status, font=('arial',10,'normal'))

		self.taskLabel = Label(self, text="Assigned Task:")
		self.taskLabel_cmd = Label(self, text="cmd")
		self.taskLabel_cmd_value = Label(self, textvariable=self.task_cmd)
		self.taskLabel_type = Label(self, text="type")
		self.taskLabel_type_value = Label(self, textvariable=self.task_type)
		self.taskLabel_fromLP = Label(self, text="fromLP")
		self.taskLabel_fromLP_value = Label(self, textvariable=self.task_fromLP)
		self.taskLabel_toLP = Label(self, text="toLP")
		self.taskLabel_toLP_value = Label(self, textvariable=self.task_toLP)

		self.taskCompletedLabel = Label(self, text="Completed Task:")
		self.taskCompletedLabel_cmd = Label(self, text="cmd")
		self.taskCompletedLabel_cmd_value = Label(self, textvariable=self.completed_cmd)
		self.taskCompletedLabel_type = Label(self, text="type")
		self.taskCompletedLabel_type_value = Label(self, textvariable=self.completed_type)
		self.taskCompletedLabel_fromLP = Label(self, text="fromLP")
		self.taskCompletedLabel_fromLP_value = Label(self, textvariable=self.completed_fromLP)
		self.taskCompletedLabel_toLP = Label(self, text="toLP")
		self.taskCompletedLabel_toLP_value = Label(self, textvariable=self.completed_toLP)

		# Layout
		self.start_button.place(x=10, y=0)
		self.stop_button.place(x=250, y=0)
		self.firealarmLabel.place(x=10, y=50)
		self.firealarmEntry.place(x=140, y=50)
		self.beaconalarmLabel.place(x=10, y=80)
		self.beaconalarmEntry.place(x=140, y=80)
		self.update_button.place(x=10, y=120)

		self.taskLabel.place(x=10, y=160)
		self.taskLabel_cmd.place(x=10, y=190)
		self.taskLabel_type.place(x=10, y=210)
		self.taskLabel_fromLP.place(x=10, y=230)
		self.taskLabel_toLP.place(x=10, y=250)
		self.taskLabel_cmd_value.place(x=110, y=190)
		self.taskLabel_type_value.place(x=110, y=210)
		self.taskLabel_fromLP_value.place(x=110, y=230)
		self.taskLabel_toLP_value.place(x=110, y=250)

		self.taskCompletedLabel.place(x=200, y=160)
		self.taskCompletedLabel_cmd.place(x=200, y=190)
		self.taskCompletedLabel_type.place(x=200, y=210)
		self.taskCompletedLabel_fromLP.place(x=200, y=230)
		self.taskCompletedLabel_toLP.place(x=200, y=250)
		self.taskCompletedLabel_cmd_value.place(x=300, y=190)
		self.taskCompletedLabel_type_value.place(x=300, y=210)
		self.taskCompletedLabel_fromLP_value.place(x=300, y=230)
		self.taskCompletedLabel_toLP_value.place(x=300, y=250)
		self.close_button.place(x=320, y=280)
		self.status_display.place(x=0, y=330)

##### ##### ##### ##### ##### ##### ##### #####  ##### 
##### Setup Threads and Start Threads #####
##### ##### ##### ##### ##### ##### ##### #####  ##### 	
      # self.threadGetTasks = threading.Thread(target=self.getTasks, args=(), daemon=True)
		self.threadManageHeartbeats = threading.Thread(target=self.manageHeartbeats, args=()).start()
		## self.threadManageHeartbeats.start() 
		self.threadManageTasks = threading.Thread(target=self.manageTasks, args=()).start()
		## self.threadManageTasks.start() 
		self.threadManageStatus = threading.Thread(target=self.manageStatus, args=())
		self.threadManageStatus.start()          
        
      

##### ##### ##### ##### ##### ##### ##### #####  ##### 
##### Thread manageHeartbeats  #####
##### Get new heartbeats from fleet_proxy to ascertain connectivity
##### Heartbeat1 and Heartbeat2 parameters for AGV1 and AGV2 respectively
##### ##### ##### ##### ##### ##### ##### #####  ##### 	
	def manageHeartbeats(self):
		prev_heartbeat1=rospy.Time.now().secs		## prev ROS time
		prev_heartbeat2=rospy.Time.now().secs		## prev ROS time
		start_time1=start_time2 = time.time()
		heartbeat1_count=heartbeat2_count = 0

		while True:
			if self.bCloseThreadFlag:
				break
			if self.bServerStarted:
				heartbeat1 = self.heartbeat1_parameter.get_value()			## get parameters from OPC server
				heartbeat2 = self.heartbeat2_parameter.get_value()			## get parameters from OPC server

				##### ##### ##### ##### ##### ##### ##### #####  ##### 
				### Process Heartbeat for AGV1
				##### ##### ##### ##### ##### ##### ##### #####  ##### 
				if (heartbeat1!=prev_heartbeat1):
					heartbeat1_count+=1												
				else:
					pass
				prev_heartbeat1=heartbeat1

				## print("time.time() - start_time1", time.time() - start_time1)
				if (time.time() - start_time1)>18:
					if (heartbeat1_count>=3):
						print("Heartbeat1 Count %d" % heartbeat1_count)
					else:
						print("Missed Heartbeat1 Count %d" % heartbeat1_count)
						newStatus1 = self.status1_parameter.get_value()		## status1 parameters from OPC server
						newStatus1[1]=rospy.Time.now().secs		## new ROS time
						newStatus1[7]=3			## not ready status
						## self.status1_parameter.set_value(newStatus1)		## status1 parameters from OPC server
						## ready4task1=False
					heartbeat1_count=0
					start_time1 = time.time()
				
				"""
				##### ##### ##### ##### ##### ##### ##### #####  ##### 	
				### Process Heartbeat for AGV2
				##### ##### ##### ##### ##### ##### ##### #####  ##### 
				if (heartbeat2!=prev_heartbeat2):
					heartbeat2_count+=1												
				else:
					pass
				prev_heartbeat2=heartbeat2

				## print("time.time() - start_time2", time.time() - start_time2)
				if (time.time() - start_time2)>18:
					if (heartbeat2_count>=3):
						print("Heartbeat2 Count %d" % heartbeat2_count)
					else:
						print("Missed Heartbeat2 Count %d" % heartbeat2_count)
						newStatus2 = self.status1_parameter.get_value()		## status2 parameters from OPC server
						newStatus2[1]=rospy.Time.now().secs		## new ROS time
						newStatus2[7]=3			## not ready status
						## self.status2_parameter.set_value(newStatus2)		## status2 parameters from OPC server
						## ready4task2=False
					heartbeat2_count=0
					start_time2 = time.time()
				"""
			time.sleep(1)


##### ##### ##### ##### ##### ##### ##### #####  ##### 
##### Thread manageTasks  #####
##### Get new tasks submitted by call stations and assigned to
##### Task1 and Task2 parameters for AGV1 and AGV2 respectively
##### ##### ##### ##### ##### ##### ##### #####  ##### 	
	def manageTasks(self):
		global ready4task1, ready4task2, task1_completed, unassigned_Q, task_cmd_changed, varBeacon
		curTask1=curTask2=[0,0,0,0,0]		## initialize temp list
		curBeacon=0						
		taskQsize=0
		
		while True:
			if self.bCloseThreadFlag:
				break
			if self.bServerStarted:
				## remove deleted tasks from task_Q
				for deleted in delete_Q:
					[task_Q.remove(x) for x in task_Q if deleted[1] in x]	## if time.secs matches
				task1_completed=False		## may not need
##				task2_completed=False		## may not need
								
##				if task_Q:	## list not empty
##					self.task1_parameter.set_value([task_Q[0][0], task_Q[0][1], task_Q[0][2], task_Q[0][3], task_Q[0][4]])
##					del task_Q[0]	## remove from list

				##### ##### ##### ##### ##### ##### ##### #####  ##### 	
				# Assign next task in the queue to AGV1
				##### ##### ##### ##### ##### ##### ##### #####  ##### 
				if task_Q and ready4task1:		## list not empty and ready
					if task_Q[0][0]==1:			## first task in queue not assigned
						task_Q[0][0]=2			## set to assigned task
						task_cmd_changed=True				## task_cmd_changed							
						self.task1_parameter.set_value([task_Q[0][0], task_Q[0][1], task_Q[0][2], task_Q[0][3], task_Q[0][4]])
						ready4task1=False
					elif task_Q[1][0]==1:		## second task in queue not assigned
						task_Q[1][0]=2				## set to assigned task
						task_cmd_changed=True				## task_cmd_changed							
						self.task1_parameter.set_value([task_Q[1][0], task_Q[1][1], task_Q[1][2], task_Q[1][3], task_Q[1][4]])
						ready4task1=False
					print(task_Q)
				
				##### ##### ##### ##### ##### ##### ##### #####  ##### 	
				# Assign next task in the queue to AGV2
				##### ##### ##### ##### ##### ##### ##### #####  ##### 
				if task_Q and ready4task2:		## list not empty and ready
					if task_Q[0][0]==1:			## first task in queue not assigned
						task_Q[0][0]=2				## set to assigned task
						task_cmd_changed=True	## task_cmd_changed						
						self.task2_parameter.set_value([task_Q[0][0], task_Q[0][1], task_Q[0][2], task_Q[0][3], task_Q[0][4]])
						ready4task2=False
					elif task_Q[1][0]==1:		## second task in queue not assigned
						task_Q[1][0]=2				## set to assigned task
						task_cmd_changed=True	## task_cmd_changed						
						self.task2_parameter.set_value([task_Q[1][0], task_Q[1][1], task_Q[1][2], task_Q[1][3], task_Q[1][4]])
						ready4task2=False
					print(task_Q)

				# Reset GUI display when list is empty 
				if not task_Q:					## list is empty
					## Reset task1 (assigned) OPC parameters
					self.task1_parameter.set_value([0,0,0,0,0])
					## Reset task1 (assigned) on GUI ##						
					self.task_cmd.set(self.task1_parameter.get_value()[0])
					self.task_type.set(self.task1_parameter.get_value()[2])
					self.task_fromLP.set(self.task1_parameter.get_value()[3])
					self.task_toLP.set(self.task1_parameter.get_value()[4])	
					## Reset taskCompleted OPC parameters
					self.taskCompleted_parameter.set_value([0,0,0,0,0])
					## Reset taskCompleted on GUI ##
					self.completed_cmd.set(self.taskCompleted_parameter.get_value()[0])
					self.completed_type.set(self.taskCompleted_parameter.get_value()[2])
					self.completed_fromLP.set(self.taskCompleted_parameter.get_value()[3])
					self.completed_toLP.set(self.taskCompleted_parameter.get_value()[4])		

				"""
				elif not ready4task2:		## not ready received
					## Reset taskCompleted OPC parameters
					self.taskCompleted_parameter.set_value([0,0,0,0,0])
					## Reset taskCompleted on GUI ##
					self.completed_cmd.set(self.taskCompleted_parameter.get_value()[0])
					self.completed_type.set(self.taskCompleted_parameter.get_value()[2])
					self.completed_fromLP.set(self.taskCompleted_parameter.get_value()[3])
					self.completed_toLP.set(self.taskCompleted_parameter.get_value()[4])					
				"""
				newTask1 = self.task1_parameter.get_value()			## get parameters from OPC server
				completedTask = self.taskCompleted_parameter.get_value()	## get parameters from OPC server
				"""
				if completedTask[0]!=0 and not ready4task1:		## not ready received
					## Reset taskCompleted OPC parameters
					self.taskCompleted_parameter.set_value([0,0,0,0,0])
					## Reset taskCompleted on GUI ##
					self.completed_cmd.set(self.taskCompleted_parameter.get_value()[0])
					self.completed_type.set(self.taskCompleted_parameter.get_value()[2])
					self.completed_fromLP.set(self.taskCompleted_parameter.get_value()[3])
					self.completed_toLP.set(self.taskCompleted_parameter.get_value()[4])
				"""
				### Update GUI
				if (curTask1[0] != newTask1[0] or curTask1[1] != newTask1[1] or
					curTask1[2] != newTask1[2] or curTask1[3] != newTask1[3] or curTask1[4] != newTask1[4]):
				
					if (newTask1[0]==2):	## assigned task
						## Display on UI as New Task
						##print("newTask1[0] is %d" % newTask1[0])
						self.task_cmd.set(newTask1[0])
						self.task_type.set(newTask1[2])
						self.task_fromLP.set(newTask1[3])
						self.task_toLP.set(newTask1[4])
						"""
						## Reset taskCompleted OPC parameters
						self.taskCompleted_parameter.set_value([0,0,0,0,0])
						## Reset taskCompleted on GUI ##
						self.completed_cmd.set(self.taskCompleted_parameter.get_value()[0])
						self.completed_type.set(self.taskCompleted_parameter.get_value()[2])
						self.completed_fromLP.set(self.taskCompleted_parameter.get_value()[3])
						self.completed_toLP.set(self.taskCompleted_parameter.get_value()[4])
						"""
					elif (newTask1[0]==3 and not task1_completed):	## cancel task
						## Reset task1 (assigned) OPC parameters
						## print("newTask1[0] is %d" % newTask1[0])
						## self.task1_parameter.set_value([0,0,0,0,0])		## Note cannot set Task1 to NULL at this moment (20210410)
						self.task_cmd.set(0)
						self.task_type.set(0)
						self.task_fromLP.set(0)
						self.task_toLP.set(0)
					"""
					elif (newTask1[0]==3 and newTask1[4]==self.task_toLP.get()):	## cancel task
					##print("newTask1[0] is %d" % newTask1[0])
						self.task1_parameter.set_value([0,0,0,0,0])
						self.task_cmd.set(self.task1_parameter.get_value()[0])
						self.task_type.set(self.task1_parameter.get_value()[2])
						self.task_fromLP.set(self.task1_parameter.get_value()[3])
						self.task_toLP.set(self.task1_parameter.get_value()[4])
					"""
					curTask1 = list(newTask1)			## update curTask1

					## Update taskCompleted on GUI ##
					if (completedTask[0] != 0):
					## Update to GUI ##
						self.completed_cmd.set(self.taskCompleted_parameter.get_value()[0])
						self.completed_type.set(self.taskCompleted_parameter.get_value()[2])
						self.completed_fromLP.set(self.taskCompleted_parameter.get_value()[3])
						self.completed_toLP.set(self.taskCompleted_parameter.get_value()[4])			
				## end if

				## Publish when task list not empty and (task_cmd changed or change in task_Q size)
				if (task_Q and (task_cmd_changed or taskQsize!=len(task_Q))):  
				### Publish all tasks in queue to call stations via ROSbridge	
					###print(task_Q)			
					pub_msg = jobs()							### an instant of ntuc_fleet/jobs message type
					pub_msg.cmd = 1								### cmd==1
					pub_msg.time = rospy.Time.now()				### ROS time
					### Add all tasks to ROS message array				
					for each in task_Q:			 			### build task ROS message for each task in queue
						task_msg = task()
						task_msg.cmd = each[0]
						task_msg.time.secs = each[1]		### only secs is stored in task 
						task_msg.type = each[2]		
						task_msg.fromLP = each[3]	
						task_msg.toLP = each[4]	
						pub_msg.tasks.append(task_msg)
					pub_jobs.publish(pub_msg)				### publish to ROS topic
					taskQsize = len(task_Q)					### update taskQsize
					task_cmd_changed=False					### reset task_cmd_changed

					### open output file for writing (default written to .ros @home)
					with open('../catkin_ws/src/ntuc_fleet/data/list_of_tasks.txt', 'w') as filehandle:
						json.dump(task_Q, filehandle)
##					filehandle.close()

					with open('../catkin_ws/src/ntuc_fleet/data/listfile.data', 'wb') as filehandle:
					# store the data as binary data stream
						pickle.dump(task_Q, filehandle)
##					filehandle.close()

				newBeacon = self.beaconalarm_parameter.get_value()			## get parameters from OPC server
				if (curBeacon != newBeacon):
					## varBeacon.set_value([8,0])
					curBeacon = newBeacon			## update curBeaconn

			time.sleep(0.5) 
		## end while
	## end manageTasks()  


##### ##### ##### ##### ##### ##### ##### #####  ##### 
##### Thread manageStatus Definition #####
##### ##### ##### ##### ##### ##### ##### #####  ##### 	
	def manageStatus(self):
		global ready4task1, ready4task2, task1_completed, task_cmd_changed
		curStatus1 = [0,0,0,0,0,0,0,0,0]			# AGV1
		curStatus2 = [0,0,0,0,0,0,0,0,0]			# AGV2	
		
		while True:
			if self.bCloseThreadFlag:
				break
			if self.bServerStarted:
				newTask1 = self.task1_parameter.get_value()			## task1 parameters from OPC server
				newTask2 = self.task2_parameter.get_value()			## task2 parameters from OPC server
				newStatus1 = self.status1_parameter.get_value()		## status1 parameters from OPC server
				newStatus2 = self.status2_parameter.get_value()		## status2 parameters from OPC server				
				##completedTask = self.taskCompleted_parameter.get_value()	## get parameters from OPC server

##				print("Into mangageStatus() curStatus1", curStatus1[0],curStatus1[1],curStatus1[2],curStatus1[3],curStatus1[4],curStatus1[5],curStatus1[6],curStatus1[7])
##				print("Into mangageStatus() newStatus1", newStatus1[0],newStatus1[1],newStatus1[2],newStatus1[3],newStatus1[4],newStatus1[5],newStatus1[6],newStatus1[7])
##				if newStatus1[7]!=curStatus1[7]:
##					print("Inside mangageStatus(), newStatus1[7]", newStatus1[7])	
				
				##### ##### ##### ##### ##### ##### ##### #####  ##### 	
				### process status message for AGV1	
				##### ##### ##### ##### ##### ##### ##### #####  ##### 
				if (curStatus1[0]!=newStatus1[0] or curStatus1[1]!=newStatus1[1] or curStatus1[2]!=newStatus1[2] or
					curStatus1[3]!=newStatus1[3] or curStatus1[4]!=newStatus1[4] or curStatus1[5]!=newStatus1[5] or 
					curStatus1[6]!=newStatus1[6] or curStatus1[7]!=newStatus1[7] or curStatus1[8]!=newStatus1[8]):
										
					print("Inside manageStatus(),newStatus1[7],newStatus1[8]",newStatus1[7],newStatus1[8])	
				
					if (newStatus1[0]==1):	## operational status

						if (newStatus1[7]==4):					## dispatch task aborted
							if (len(task_Q)>=2):
								if (task_Q[0][1]==newTask1[1]): 		## first task in queue matches ROS time
									task_Q[0][0]=1;						## change first task in the queue to unassigned
									task_cmd_changed=True				## task_cmd_changed
									##print(task_Q)	
									newTask1[0]=3						## mark for deletion of task1_parameter
									## self.task1_parameter.set_value(newTask1)			## not needed
									##task1_completed=False
									##ready4task1=False

								elif (task_Q[1][1]==newTask1[1]): 		## second task in queue matches ROS time
									task_Q[1][0]=1;						## change second task in the queue to unassigned
									task_cmd_changed=True				## task_cmd_changed									
									##print(task_Q)	
									newTask1[0]=3						## mark for deletion of task1_parameter
									## self.task1_parameter.set_value(newTask1)			## not needed
									##task1_completed=False
									##ready4task1=False	
							elif (len(task_Q)==1):													
								if (task_Q[0][1]==newTask1[1]): 		## first task in queue matches ROS time
									task_Q[0][0]=1;						## change first task in the queue to unassigned
									task_cmd_changed=True				## task_cmd_changed									
									##print(task_Q)	
									newTask1[0]=3						## mark for deletion of task1_parameter
									## self.task1_parameter.set_value(newTask1)			## not needed
									##task1_completed=False
									##ready4task1=False

							print(task_Q)	
							task1_completed=False
							ready4task1=False	
																
							## Reset taskCompleted OPC parameters
							self.taskCompleted_parameter.set_value([0,0,0,0,0])
							## Reset taskCompleted on GUI ##
							self.completed_cmd.set(self.taskCompleted_parameter.get_value()[0])
							self.completed_type.set(self.taskCompleted_parameter.get_value()[2])
							self.completed_fromLP.set(self.taskCompleted_parameter.get_value()[3])
							self.completed_toLP.set(self.taskCompleted_parameter.get_value()[4])
						#### end if (newStatus1[7]==4):
						elif (newStatus1[7]==3):					## AGV not ready for dispatch task
							print(task_Q)			
							ready4task1=False

						## Assigned Task is completed
						## Update task1_completed and ready4task
						elif (newStatus1[7]==1 or newStatus1[7]==2):				## assigned task completed
						
							if newTask1[0]==2:								## assigned task
								delete_Q.append(newTask1)					## mark for deletion												
								task1_completed=True
							##	newTask1[0]=0								## invalid task
							print(task_Q)			
							
							## Update taskCompleted OPC parameters
							self.taskCompleted_parameter.set_value(newTask1)
							## Update taskCompleted on GUI ##
							self.completed_cmd.set(self.taskCompleted_parameter.get_value()[0])
							self.completed_type.set(self.taskCompleted_parameter.get_value()[2])
							self.completed_fromLP.set(self.taskCompleted_parameter.get_value()[3])
							self.completed_toLP.set(self.taskCompleted_parameter.get_value()[4])	
							time.sleep(1)						

							## AGV ready for dispatch task
							if (newStatus1[7]==1):			## AGV ready for dispatch task
								print(task_Q)								
								ready4task1=True
						#### end elif (newStatus1[7]==1 or newStatus1[7]==2):
						elif (newStatus1[7]==0):			## just ready for task
							ready4task1=True						
							print(task_Q)	

						### Additional checking to prevent errorneous publishing of task completion when no task is assigned
						### to prevent sounding of alarm at call stations when actually empty trolley was not delivered
						if (newStatus1[7]==1 and newTask1[0]!=2):			## No task was assigned, complete should be 0 [Ready]
							newStatus1[7]=0				
						elif (newStatus1[7]==2 and newTask1[0]!=2):			## No task was assigned, complete should be 3 [Not Ready]
							newStatus1[7]=3	

						## Send update to call station via ROSbridge
						pub_msg = agv_status()				### an instant of ntuc_fleet/agv_status message type
						pub_msg.cmd = newStatus1[0]			### cmd==1
						pub_msg.time.secs = newStatus1[1]	### time in secs
						pub_msg.status = newStatus1[2]		### status of AGV	
						pub_msg.location = newStatus1[3]		### location LP
						pub_msg.arrival.secs = newStatus1[4]	### estimated arrival time secs
						pub_msg.b_level = newStatus1[5]		### battery level in percent	
						pub_msg.e_status = newStatus1[6]		### elevator status		
						pub_msg.complete = newStatus1[7]		### task completion and readiness	
						pub_msg.lastLP = newStatus1[8]		### lastLP of just completed task
						pub_status.publish(pub_msg)

					elif (newStatus1[0]==2):	## alert status
						pass
						
					elif (newStatus1[0]==3):	## alarm status
						pass

					elif (newStatus1[0]==4):	## agv status

						## Send update to call station via ROSbridge
						pub_msg = agv_status()				### an instant of ntuc_fleet/agv_status message type
						pub_msg.cmd = newStatus1[0]			### cmd==1
						pub_msg.time.secs = newStatus1[1]	### time in secs
						pub_msg.status = newStatus1[2]		### status of AGV	
						pub_msg.location = newStatus1[3]		### location LP
						pub_msg.arrival.secs = newStatus1[4]	### estimated arrival time secs
						pub_msg.b_level = newStatus1[5]		### battery level in percent	
						pub_msg.e_status = newStatus1[6]		### elevator status		
						pub_msg.complete = newStatus1[7]		### task completion and readiness	
						pub_msg.lastLP = newStatus1[8]		### lastLP of just completed task
						pub_status.publish(pub_msg)	
						
					curStatus1 = list(newStatus1)			## update curStatus1
				
					
				##### ##### ##### ##### ##### ##### ##### #####  ##### 	
				### process status message for AGV2	
				##### ##### ##### ##### ##### ##### ##### #####  ##### 
				if (curStatus2[0]!=newStatus2[0] or curStatus2[1]!=newStatus2[1] or curStatus2[2]!=newStatus2[2] or 
					curStatus2[3]!=newStatus2[3] or curStatus2[4]!=newStatus2[4] or curStatus2[5]!=newStatus2[5] or
					curStatus2[6]!=newStatus2[6] or curStatus2[7]!=newStatus2[7] or curStatus2[8]!=newStatus2[8] ):
									
					print("Inside manageStatus(),newStatus1[7],newStatus1[8]",newStatus1[7],newStatus1[8])
				
					if (newStatus2[0]==1):	## operational status

						if (newStatus2[7]==4):					## dispatch task aborted
							if (len(task_Q)>=2):
								if (task_Q[0][1]==newTask2[1]): 		## first task in queue matches ROS time
									task_Q[0][0]=1;						## change first task in the queue to unassigned
									task_cmd_changed=True				## task_cmd_changed
									##print(task_Q)	
									newTask2[0]=3						## mark for deletion of task2_parameter
									## self.task2_parameter.set_value(newTask2)			## not needed
									##task2_completed=False
									##ready4task2=False

								elif (task_Q[1][1]==newTask2[1]): 		## second task in queue matches ROS time
									task_Q[1][0]=1;						## change second task in the queue to unassigned
									task_cmd_changed=True				## task_cmd_changed									
									##print(task_Q)	
									newTask2[0]=3						## mark for deletion of task2_parameter
									## self.task2_parameter.set_value(newTask2)			## not needed
									##task2_completed=False
									##ready4task2=False	
							elif (len(task_Q)==1):													
								if (task_Q[0][1]==newTask2[1]): 		## first task in queue matches ROS time
									task_Q[0][0]=1;						## change first task in the queue to unassigned
									task_cmd_changed=True				## task_cmd_changed									
									##print(task_Q)	
									newTask2[0]=3						## mark for deletion of task2_parameter
									## self.task2_parameter.set_value(newTask2)			## not needed
									##task2_completed=False
									##ready4task2=False

							print(task_Q)	
							task2_completed=False
							ready4task2=False	
																
							## Reset taskCompleted OPC parameters
							self.taskCompleted_parameter.set_value([0,0,0,0,0])
							## Reset taskCompleted on GUI ##
							self.completed_cmd.set(self.taskCompleted_parameter.get_value()[0])
							self.completed_type.set(self.taskCompleted_parameter.get_value()[2])
							self.completed_fromLP.set(self.taskCompleted_parameter.get_value()[3])
							self.completed_toLP.set(self.taskCompleted_parameter.get_value()[4])
						#### end if (newStatus2[7]==4):
						elif (newStatus2[7]==3):					## AGV2 not ready for dispatch task
							print(task_Q)			
							ready4task2=False

						## Assigned Task is completed
						## Update task2_completed and ready4task
						elif (newStatus2[7]==1 or newStatus2[7]==2):				## assigned task completed
						
							if newTask2[0]==2:								## assigned task
								delete_Q.append(newTask2)					## mark for deletion
								task2_completed=True
							##	newTask2[0]=0								## invalid task
							print(task_Q)			
							
							## Update taskCompleted OPC parameters
							self.taskCompleted_parameter.set_value(newTask1)
							## Update taskCompleted on GUI ##
							self.completed_cmd.set(self.taskCompleted_parameter.get_value()[0])
							self.completed_type.set(self.taskCompleted_parameter.get_value()[2])
							self.completed_fromLP.set(self.taskCompleted_parameter.get_value()[3])
							self.completed_toLP.set(self.taskCompleted_parameter.get_value()[4])	
							time.sleep(1)																		

							## AGV ready for dispatch task
							if (newStatus2[7]==1):			## AGV ready for dispatch task
								print(task_Q)								
								ready4task2=True
						#### end elif (newStatus2[7]==1 or newStatus2[7]==2):
						elif (newStatus2[7]==0):			## just ready for task
							ready4task2=True						
							print(task_Q)	

						### Additional checking to prevent errorneous publishing of task completion when no task is assigned
						### to prevent sounding of alarm at call stations when actually empty trolley was not delivered
						if (newStatus2[7]==1 and newTask2[0]!=2):			## No task was assigned, complete should be 0 [Ready]
							newStatus2[7]=0				
						elif (newStatus2[7]==2 and newTask2[0]!=2):			## No task was assigned, complete should be 3 [Not Ready]
							newStatus2[7]=3	

						## Send update to call station via ROSbridge
						pub_msg = agv_status()				### an instant of ntuc_fleet/agv_status message type
						pub_msg.cmd = newStatus2[0]			### cmd==1
						pub_msg.time.secs = newStatus2[1]	### time in secs
						pub_msg.status = newStatus2[2]		### status of AGV	
						pub_msg.location = newStatus2[3]		### location LP
						pub_msg.arrival.secs = newStatus2[4]	### estimated arrival time secs
						pub_msg.b_level = newStatus2[5]		### battery level in percent	
						pub_msg.e_status = newStatus2[6]		### elevator status		
						pub_msg.complete = newStatus2[7]		### task completion and readiness	
						pub_msg.lastLP = newStatus2[8]		### lastLP of just completed task
						pub_status.publish(pub_msg)	

					elif (newStatus2[0]==2):	## alert status
						pass
						
					elif (newStatus2[0]==3):	## alarm status
						pass

					elif (newStatus2[0]==4):	## agv status

						## Send update to call station via ROSbridge
						pub_msg = agv_status()				### an instant of ntuc_fleet/agv_status message type
						pub_msg.cmd = newStatus2[0]			### cmd==1
						pub_msg.time.secs = newStatus2[1]	### time in secs
						pub_msg.status = newStatus2[2]		### status of AGV	
						pub_msg.location = newStatus2[3]		### location LP
						pub_msg.arrival.secs = newStatus2[4]	### estimated arrival time secs
						pub_msg.b_level = newStatus2[5]		### battery level in percent	
						pub_msg.e_status = newStatus2[6]		### elevator status		
						pub_msg.complete = newStatus2[7]		### task completion and readiness	
						pub_msg.lastLP = newStatus2[8]		### lastLP of just completed task
						pub_status.publish(pub_msg)	
						
					curStatus2 = list(newStatus2)			## update curStatus2
			
				## end if
			time.sleep(0.5)
		## end while
 ## end manageStatus()  

                
##### ##### ##### ##### ##### ##### ##### #####  ##### 
##### GUI update method #####
##### ##### ##### ##### ##### ##### ##### #####  #####             
	def update(self, method):
		if method == "start":
			self.server.start()
			print("OPC Server Started")
			self.start_button.configure(state = 'disabled')
			self.stop_button.configure(state = 'active')
			self.update_button.configure(state = 'active')
			self.bServerStarted = True
		elif method == "stop":
			self.server.stop()
			print("OPC Server Stopped")
			self.start_button.configure(state = 'active')
			self.stop_button.configure(state = 'disabled')
			self.update_button.configure(state = 'disabled')
			self.bServerStarted = False
		elif method == "update":
			self.firealarm_parameter.set_value(self.updatedFireAlarm)
			## self.firealarmEntry.setText(self.updatedFireAlarm)
			self.beaconalarm_parameter.set_value(self.updatedBeaconAlarm)
			## self.beaconalarmEntry.setText(self.updatedBeaconAlarm)
		elif method == "close":
			# Set close thread flag so that the started thread(s) threads can exit
			self.bCloseThreadFlag = True
			time.sleep(0.1)
			self.master.destroy()
 ## end update() 

##### ##### ##### ##### ##### ##### ##### #####  #####   ##### 
##### Input data validation for GUI textbox firealarmEntry  #####
##### Input field firealarmEntry accepts only 0 or 1 #####
##### ##### ##### ##### ##### ##### ##### #####  #####   ##### 
	def validateFA(self, new_value):
		if new_value == "":
			self.updatedFireAlarm = 0
			return True
		if str.isdigit(new_value):
			if int(new_value) == 0 or int(new_value) == 1:
				self.updatedFireAlarm = int(new_value)
				return True
			else:
				self.updatedFireAlarm = 0
				return False
		else:
			self.updatedFireAlarm = 0
			return False
 ## end validateFA() 

##### ##### ##### ##### ##### ##### ##### #####  #####   ##### 
##### Input data validation for GUI textbox beaconalarmEntry  #####
##### Input field beaconalarmEntry accepts only 0 or 1 #####
##### ##### ##### ##### ##### ##### ##### #####  #####   ##### 	
	def validateBA(self, new_value):
		if new_value == "":
			self.updatedBeaconAlarm = 0
			return True
		if str.isdigit(new_value):
			if int(new_value) == 0 or int(new_value) == 1:
				self.updatedBeaconAlarm = int(new_value)
				return True
			else:
				self.updatedBeaconAlarm = 0
				return False
		else:
			self.updatedBeaconAlarm = 0
			return False
 ## end validateBA() 
 ## end class OPCServer
        
root = Tk()			## Initialize root GUI window
root.geometry("400x350")	## size of the window
my_opc_server = OPCServer(root)	## an instance of OPCServer
root.mainloop()			## GUI event loop
##rospy.spin()			## ROS messages event loop
