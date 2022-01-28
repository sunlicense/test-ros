# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ntuc_fleet/jobs.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import genpy
import ntuc_fleet.msg

class jobs(genpy.Message):
  _md5sum = "d7b1ebb1ce6d0c3bb74e63fcb9b9e5cb"
  _type = "ntuc_fleet/jobs"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """##################################################
##### Message type: jobs.msg
##### Use in Topics: /rq_jobs, /rv_jobs
##################################################
int8 cmd				# command code	 
time time			# time queue is updated
task[] tasks		# list of task.msg (of type task.msg)

##################################################
## cmd		command code
## time		time in time.secs and and time.nsecs 
## task[]	list of pending tasks (of type task.msg)
##################################################

================================================================================
MSG: ntuc_fleet/task
##################################################
##### Message type: task.msg
##### Use in Topics: /fr_station, /fr_fleet, /fr_agv
##################################################
int8 cmd		# command code 
time time		# time task is queued
int8 type		# different trolley type
int8 fromLP		# starting LP
int8 toLP		# ending LP
int8 alloc		# 0:not allocated, 1:allocated to AGV1, 2:allocated to AGV2

##################################################
## cmd		1:new task, 2:assigned task, 3:cancel task
## time		time.secs and time.nsecs (ROS time)
## type		1:Bian Marie, 2:Food Warmer, 3:Linen
## fromLP	70:L1LRm3-9, 73:L1LRm3, 74:L1LRm4, 75:L1LRm5, 76:L1LRm6, 77:L1LRm7, 78:L1LRm8, 79:L1LRm9,
##				3:L3Ward3, 4:L4Ward4, 5:L5Ward5, 6:L6Ward6, 7:L7Ward7, 8:L8Ward8, 9:L9Ward9, 
##				10:L10StaffDorm, 11:L11Ktchen,
##				51:L1MainStore, 52:L1NonHalalPrepRoom
## toLP		73:L1LRm3, 74:L1LRm4, 75:L1LRm5, 76:L1LRm6, 77:L1LRm7, 78:L1LRm8, 79:L1LRm9,
##				3:L3Ward3, 4:L4Ward4, 5:L5Ward5, 6:L6Ward6, 7:L7Ward7, 8:L8Ward8, 9:L9Ward,
##				10: L10StaffDorm, 11:L11Ktchen,
##				51:L1MainStore, 52:L1NonHalalPrepRoom
## alloc	0:not allocated, 1:allocated to AGV1, 2:allocated to AGV2
##################################################	
## LP Range:: 	2-49: Lift Area, 50-69: Lobby Area, 70-100: Laundry Area 
##################################################	
"""
  __slots__ = ['cmd','time','tasks']
  _slot_types = ['int8','time','ntuc_fleet/task[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       cmd,time,tasks

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(jobs, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.cmd is None:
        self.cmd = 0
      if self.time is None:
        self.time = genpy.Time()
      if self.tasks is None:
        self.tasks = []
    else:
      self.cmd = 0
      self.time = genpy.Time()
      self.tasks = []

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_b2I().pack(_x.cmd, _x.time.secs, _x.time.nsecs))
      length = len(self.tasks)
      buff.write(_struct_I.pack(length))
      for val1 in self.tasks:
        _x = val1.cmd
        buff.write(_get_struct_b().pack(_x))
        _v1 = val1.time
        _x = _v1
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = val1
        buff.write(_get_struct_4b().pack(_x.type, _x.fromLP, _x.toLP, _x.alloc))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.time is None:
        self.time = genpy.Time()
      if self.tasks is None:
        self.tasks = None
      end = 0
      _x = self
      start = end
      end += 9
      (_x.cmd, _x.time.secs, _x.time.nsecs,) = _get_struct_b2I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.tasks = []
      for i in range(0, length):
        val1 = ntuc_fleet.msg.task()
        start = end
        end += 1
        (val1.cmd,) = _get_struct_b().unpack(str[start:end])
        _v2 = val1.time
        _x = _v2
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        _x = val1
        start = end
        end += 4
        (_x.type, _x.fromLP, _x.toLP, _x.alloc,) = _get_struct_4b().unpack(str[start:end])
        self.tasks.append(val1)
      self.time.canon()
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_b2I().pack(_x.cmd, _x.time.secs, _x.time.nsecs))
      length = len(self.tasks)
      buff.write(_struct_I.pack(length))
      for val1 in self.tasks:
        _x = val1.cmd
        buff.write(_get_struct_b().pack(_x))
        _v3 = val1.time
        _x = _v3
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = val1
        buff.write(_get_struct_4b().pack(_x.type, _x.fromLP, _x.toLP, _x.alloc))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.time is None:
        self.time = genpy.Time()
      if self.tasks is None:
        self.tasks = None
      end = 0
      _x = self
      start = end
      end += 9
      (_x.cmd, _x.time.secs, _x.time.nsecs,) = _get_struct_b2I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.tasks = []
      for i in range(0, length):
        val1 = ntuc_fleet.msg.task()
        start = end
        end += 1
        (val1.cmd,) = _get_struct_b().unpack(str[start:end])
        _v4 = val1.time
        _x = _v4
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        _x = val1
        start = end
        end += 4
        (_x.type, _x.fromLP, _x.toLP, _x.alloc,) = _get_struct_4b().unpack(str[start:end])
        self.tasks.append(val1)
      self.time.canon()
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_2I = None
def _get_struct_2I():
    global _struct_2I
    if _struct_2I is None:
        _struct_2I = struct.Struct("<2I")
    return _struct_2I
_struct_4b = None
def _get_struct_4b():
    global _struct_4b
    if _struct_4b is None:
        _struct_4b = struct.Struct("<4b")
    return _struct_4b
_struct_b = None
def _get_struct_b():
    global _struct_b
    if _struct_b is None:
        _struct_b = struct.Struct("<b")
    return _struct_b
_struct_b2I = None
def _get_struct_b2I():
    global _struct_b2I
    if _struct_b2I is None:
        _struct_b2I = struct.Struct("<b2I")
    return _struct_b2I