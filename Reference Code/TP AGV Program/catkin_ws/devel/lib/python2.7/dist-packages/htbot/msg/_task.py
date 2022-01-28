# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from htbot/task.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import genpy

class task(genpy.Message):
  _md5sum = "d9335104b860e9530a386a51f33ebb59"
  _type = "htbot/task"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """int8 cmd
time time
int8 type
int8 fromLP
int8 toLP
int8 alloc
"""
  __slots__ = ['cmd','time','type','fromLP','toLP','alloc']
  _slot_types = ['int8','time','int8','int8','int8','int8']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       cmd,time,type,fromLP,toLP,alloc

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(task, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.cmd is None:
        self.cmd = 0
      if self.time is None:
        self.time = genpy.Time()
      if self.type is None:
        self.type = 0
      if self.fromLP is None:
        self.fromLP = 0
      if self.toLP is None:
        self.toLP = 0
      if self.alloc is None:
        self.alloc = 0
    else:
      self.cmd = 0
      self.time = genpy.Time()
      self.type = 0
      self.fromLP = 0
      self.toLP = 0
      self.alloc = 0

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
      buff.write(_get_struct_b2I4b().pack(_x.cmd, _x.time.secs, _x.time.nsecs, _x.type, _x.fromLP, _x.toLP, _x.alloc))
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
      end = 0
      _x = self
      start = end
      end += 13
      (_x.cmd, _x.time.secs, _x.time.nsecs, _x.type, _x.fromLP, _x.toLP, _x.alloc,) = _get_struct_b2I4b().unpack(str[start:end])
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
      buff.write(_get_struct_b2I4b().pack(_x.cmd, _x.time.secs, _x.time.nsecs, _x.type, _x.fromLP, _x.toLP, _x.alloc))
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
      end = 0
      _x = self
      start = end
      end += 13
      (_x.cmd, _x.time.secs, _x.time.nsecs, _x.type, _x.fromLP, _x.toLP, _x.alloc,) = _get_struct_b2I4b().unpack(str[start:end])
      self.time.canon()
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_b2I4b = None
def _get_struct_b2I4b():
    global _struct_b2I4b
    if _struct_b2I4b is None:
        _struct_b2I4b = struct.Struct("<b2I4b")
    return _struct_b2I4b
