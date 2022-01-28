# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from htbot/stat.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class stat(genpy.Message):
  _md5sum = "e06faac651c5c8ab03e4e96be2620bbd"
  _type = "htbot/stat"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """int8 speed
int8 trip
int8 time
float32 maxspeed
float32 minspeed
float32 avgspeed
float32 curspeed
float32 totaltriptime
float32 totaltripdist
float32 avgvolt
float32 avgcurr
float32 maxcurr
float32 mincurr
float32 amphr
float32 batlevel
int16 clearops
int16 estop
int16 motordisable
"""
  __slots__ = ['speed','trip','time','maxspeed','minspeed','avgspeed','curspeed','totaltriptime','totaltripdist','avgvolt','avgcurr','maxcurr','mincurr','amphr','batlevel','clearops','estop','motordisable']
  _slot_types = ['int8','int8','int8','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','int16','int16','int16']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       speed,trip,time,maxspeed,minspeed,avgspeed,curspeed,totaltriptime,totaltripdist,avgvolt,avgcurr,maxcurr,mincurr,amphr,batlevel,clearops,estop,motordisable

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(stat, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.speed is None:
        self.speed = 0
      if self.trip is None:
        self.trip = 0
      if self.time is None:
        self.time = 0
      if self.maxspeed is None:
        self.maxspeed = 0.
      if self.minspeed is None:
        self.minspeed = 0.
      if self.avgspeed is None:
        self.avgspeed = 0.
      if self.curspeed is None:
        self.curspeed = 0.
      if self.totaltriptime is None:
        self.totaltriptime = 0.
      if self.totaltripdist is None:
        self.totaltripdist = 0.
      if self.avgvolt is None:
        self.avgvolt = 0.
      if self.avgcurr is None:
        self.avgcurr = 0.
      if self.maxcurr is None:
        self.maxcurr = 0.
      if self.mincurr is None:
        self.mincurr = 0.
      if self.amphr is None:
        self.amphr = 0.
      if self.batlevel is None:
        self.batlevel = 0.
      if self.clearops is None:
        self.clearops = 0
      if self.estop is None:
        self.estop = 0
      if self.motordisable is None:
        self.motordisable = 0
    else:
      self.speed = 0
      self.trip = 0
      self.time = 0
      self.maxspeed = 0.
      self.minspeed = 0.
      self.avgspeed = 0.
      self.curspeed = 0.
      self.totaltriptime = 0.
      self.totaltripdist = 0.
      self.avgvolt = 0.
      self.avgcurr = 0.
      self.maxcurr = 0.
      self.mincurr = 0.
      self.amphr = 0.
      self.batlevel = 0.
      self.clearops = 0
      self.estop = 0
      self.motordisable = 0

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
      buff.write(_get_struct_3b12f3h().pack(_x.speed, _x.trip, _x.time, _x.maxspeed, _x.minspeed, _x.avgspeed, _x.curspeed, _x.totaltriptime, _x.totaltripdist, _x.avgvolt, _x.avgcurr, _x.maxcurr, _x.mincurr, _x.amphr, _x.batlevel, _x.clearops, _x.estop, _x.motordisable))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 57
      (_x.speed, _x.trip, _x.time, _x.maxspeed, _x.minspeed, _x.avgspeed, _x.curspeed, _x.totaltriptime, _x.totaltripdist, _x.avgvolt, _x.avgcurr, _x.maxcurr, _x.mincurr, _x.amphr, _x.batlevel, _x.clearops, _x.estop, _x.motordisable,) = _get_struct_3b12f3h().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_3b12f3h().pack(_x.speed, _x.trip, _x.time, _x.maxspeed, _x.minspeed, _x.avgspeed, _x.curspeed, _x.totaltriptime, _x.totaltripdist, _x.avgvolt, _x.avgcurr, _x.maxcurr, _x.mincurr, _x.amphr, _x.batlevel, _x.clearops, _x.estop, _x.motordisable))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 57
      (_x.speed, _x.trip, _x.time, _x.maxspeed, _x.minspeed, _x.avgspeed, _x.curspeed, _x.totaltriptime, _x.totaltripdist, _x.avgvolt, _x.avgcurr, _x.maxcurr, _x.mincurr, _x.amphr, _x.batlevel, _x.clearops, _x.estop, _x.motordisable,) = _get_struct_3b12f3h().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3b12f3h = None
def _get_struct_3b12f3h():
    global _struct_3b12f3h
    if _struct_3b12f3h is None:
        _struct_3b12f3h = struct.Struct("<3b12f3h")
    return _struct_3b12f3h
