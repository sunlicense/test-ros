# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from htbot/mqueueRequest.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class mqueueRequest(genpy.Message):
  _md5sum = "e4cb468e5ed01acf5ef7706e07bd3b67"
  _type = "htbot/mqueueRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """int8 cmd
int8 LP
int8 GN
string gps
string lps
string pw
float32 tx
float32 ty
float32 tz
float32 rx
float32 ry
float32 rz
float32 rw
float32 prd
float32 pra
float32 psd
float32 psa
float32 prd1
float32 pra1
float32 psd1
float32 psa1
float32 align
float32 autostart
"""
  __slots__ = ['cmd','LP','GN','gps','lps','pw','tx','ty','tz','rx','ry','rz','rw','prd','pra','psd','psa','prd1','pra1','psd1','psa1','align','autostart']
  _slot_types = ['int8','int8','int8','string','string','string','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       cmd,LP,GN,gps,lps,pw,tx,ty,tz,rx,ry,rz,rw,prd,pra,psd,psa,prd1,pra1,psd1,psa1,align,autostart

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(mqueueRequest, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.cmd is None:
        self.cmd = 0
      if self.LP is None:
        self.LP = 0
      if self.GN is None:
        self.GN = 0
      if self.gps is None:
        self.gps = ''
      if self.lps is None:
        self.lps = ''
      if self.pw is None:
        self.pw = ''
      if self.tx is None:
        self.tx = 0.
      if self.ty is None:
        self.ty = 0.
      if self.tz is None:
        self.tz = 0.
      if self.rx is None:
        self.rx = 0.
      if self.ry is None:
        self.ry = 0.
      if self.rz is None:
        self.rz = 0.
      if self.rw is None:
        self.rw = 0.
      if self.prd is None:
        self.prd = 0.
      if self.pra is None:
        self.pra = 0.
      if self.psd is None:
        self.psd = 0.
      if self.psa is None:
        self.psa = 0.
      if self.prd1 is None:
        self.prd1 = 0.
      if self.pra1 is None:
        self.pra1 = 0.
      if self.psd1 is None:
        self.psd1 = 0.
      if self.psa1 is None:
        self.psa1 = 0.
      if self.align is None:
        self.align = 0.
      if self.autostart is None:
        self.autostart = 0.
    else:
      self.cmd = 0
      self.LP = 0
      self.GN = 0
      self.gps = ''
      self.lps = ''
      self.pw = ''
      self.tx = 0.
      self.ty = 0.
      self.tz = 0.
      self.rx = 0.
      self.ry = 0.
      self.rz = 0.
      self.rw = 0.
      self.prd = 0.
      self.pra = 0.
      self.psd = 0.
      self.psa = 0.
      self.prd1 = 0.
      self.pra1 = 0.
      self.psd1 = 0.
      self.psa1 = 0.
      self.align = 0.
      self.autostart = 0.

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
      buff.write(_get_struct_3b().pack(_x.cmd, _x.LP, _x.GN))
      _x = self.gps
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.lps
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.pw
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_17f().pack(_x.tx, _x.ty, _x.tz, _x.rx, _x.ry, _x.rz, _x.rw, _x.prd, _x.pra, _x.psd, _x.psa, _x.prd1, _x.pra1, _x.psd1, _x.psa1, _x.align, _x.autostart))
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
      end += 3
      (_x.cmd, _x.LP, _x.GN,) = _get_struct_3b().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.gps = str[start:end].decode('utf-8')
      else:
        self.gps = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.lps = str[start:end].decode('utf-8')
      else:
        self.lps = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.pw = str[start:end].decode('utf-8')
      else:
        self.pw = str[start:end]
      _x = self
      start = end
      end += 68
      (_x.tx, _x.ty, _x.tz, _x.rx, _x.ry, _x.rz, _x.rw, _x.prd, _x.pra, _x.psd, _x.psa, _x.prd1, _x.pra1, _x.psd1, _x.psa1, _x.align, _x.autostart,) = _get_struct_17f().unpack(str[start:end])
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
      buff.write(_get_struct_3b().pack(_x.cmd, _x.LP, _x.GN))
      _x = self.gps
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.lps
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.pw
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_17f().pack(_x.tx, _x.ty, _x.tz, _x.rx, _x.ry, _x.rz, _x.rw, _x.prd, _x.pra, _x.psd, _x.psa, _x.prd1, _x.pra1, _x.psd1, _x.psa1, _x.align, _x.autostart))
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
      end += 3
      (_x.cmd, _x.LP, _x.GN,) = _get_struct_3b().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.gps = str[start:end].decode('utf-8')
      else:
        self.gps = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.lps = str[start:end].decode('utf-8')
      else:
        self.lps = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.pw = str[start:end].decode('utf-8')
      else:
        self.pw = str[start:end]
      _x = self
      start = end
      end += 68
      (_x.tx, _x.ty, _x.tz, _x.rx, _x.ry, _x.rz, _x.rw, _x.prd, _x.pra, _x.psd, _x.psa, _x.prd1, _x.pra1, _x.psd1, _x.psa1, _x.align, _x.autostart,) = _get_struct_17f().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3b = None
def _get_struct_3b():
    global _struct_3b
    if _struct_3b is None:
        _struct_3b = struct.Struct("<3b")
    return _struct_3b
_struct_17f = None
def _get_struct_17f():
    global _struct_17f
    if _struct_17f is None:
        _struct_17f = struct.Struct("<17f")
    return _struct_17f
# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from htbot/mqueueResponse.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class mqueueResponse(genpy.Message):
  _md5sum = "a6a4649df65d8320dbceeee83af7bd77"
  _type = "htbot/mqueueResponse"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """int8 status
float32 tx
float32 ty
float32 tz
float32 rx
float32 ry
float32 rz
float32 rw
float32 prd
float32 pra
float32 psd
float32 psa
float32 prd1
float32 pra1
float32 psd1
float32 psa1
int8 LP
int8 cLP
int8 nGP
int8 cGN
int8 nIQ
int8 marked
string gps
string lps
string lps1
string lps2
string lps3
string lps4
string lps5
string lps6
string lps7
string lps8
int8 marked1
int8 marked2
int8 marked3
int8 marked4
int8 marked5
int8 marked6
int8 marked7
int8 marked8
float32 align
float32 autostart

"""
  __slots__ = ['status','tx','ty','tz','rx','ry','rz','rw','prd','pra','psd','psa','prd1','pra1','psd1','psa1','LP','cLP','nGP','cGN','nIQ','marked','gps','lps','lps1','lps2','lps3','lps4','lps5','lps6','lps7','lps8','marked1','marked2','marked3','marked4','marked5','marked6','marked7','marked8','align','autostart']
  _slot_types = ['int8','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','int8','int8','int8','int8','int8','int8','string','string','string','string','string','string','string','string','string','string','int8','int8','int8','int8','int8','int8','int8','int8','float32','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       status,tx,ty,tz,rx,ry,rz,rw,prd,pra,psd,psa,prd1,pra1,psd1,psa1,LP,cLP,nGP,cGN,nIQ,marked,gps,lps,lps1,lps2,lps3,lps4,lps5,lps6,lps7,lps8,marked1,marked2,marked3,marked4,marked5,marked6,marked7,marked8,align,autostart

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(mqueueResponse, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.status is None:
        self.status = 0
      if self.tx is None:
        self.tx = 0.
      if self.ty is None:
        self.ty = 0.
      if self.tz is None:
        self.tz = 0.
      if self.rx is None:
        self.rx = 0.
      if self.ry is None:
        self.ry = 0.
      if self.rz is None:
        self.rz = 0.
      if self.rw is None:
        self.rw = 0.
      if self.prd is None:
        self.prd = 0.
      if self.pra is None:
        self.pra = 0.
      if self.psd is None:
        self.psd = 0.
      if self.psa is None:
        self.psa = 0.
      if self.prd1 is None:
        self.prd1 = 0.
      if self.pra1 is None:
        self.pra1 = 0.
      if self.psd1 is None:
        self.psd1 = 0.
      if self.psa1 is None:
        self.psa1 = 0.
      if self.LP is None:
        self.LP = 0
      if self.cLP is None:
        self.cLP = 0
      if self.nGP is None:
        self.nGP = 0
      if self.cGN is None:
        self.cGN = 0
      if self.nIQ is None:
        self.nIQ = 0
      if self.marked is None:
        self.marked = 0
      if self.gps is None:
        self.gps = ''
      if self.lps is None:
        self.lps = ''
      if self.lps1 is None:
        self.lps1 = ''
      if self.lps2 is None:
        self.lps2 = ''
      if self.lps3 is None:
        self.lps3 = ''
      if self.lps4 is None:
        self.lps4 = ''
      if self.lps5 is None:
        self.lps5 = ''
      if self.lps6 is None:
        self.lps6 = ''
      if self.lps7 is None:
        self.lps7 = ''
      if self.lps8 is None:
        self.lps8 = ''
      if self.marked1 is None:
        self.marked1 = 0
      if self.marked2 is None:
        self.marked2 = 0
      if self.marked3 is None:
        self.marked3 = 0
      if self.marked4 is None:
        self.marked4 = 0
      if self.marked5 is None:
        self.marked5 = 0
      if self.marked6 is None:
        self.marked6 = 0
      if self.marked7 is None:
        self.marked7 = 0
      if self.marked8 is None:
        self.marked8 = 0
      if self.align is None:
        self.align = 0.
      if self.autostart is None:
        self.autostart = 0.
    else:
      self.status = 0
      self.tx = 0.
      self.ty = 0.
      self.tz = 0.
      self.rx = 0.
      self.ry = 0.
      self.rz = 0.
      self.rw = 0.
      self.prd = 0.
      self.pra = 0.
      self.psd = 0.
      self.psa = 0.
      self.prd1 = 0.
      self.pra1 = 0.
      self.psd1 = 0.
      self.psa1 = 0.
      self.LP = 0
      self.cLP = 0
      self.nGP = 0
      self.cGN = 0
      self.nIQ = 0
      self.marked = 0
      self.gps = ''
      self.lps = ''
      self.lps1 = ''
      self.lps2 = ''
      self.lps3 = ''
      self.lps4 = ''
      self.lps5 = ''
      self.lps6 = ''
      self.lps7 = ''
      self.lps8 = ''
      self.marked1 = 0
      self.marked2 = 0
      self.marked3 = 0
      self.marked4 = 0
      self.marked5 = 0
      self.marked6 = 0
      self.marked7 = 0
      self.marked8 = 0
      self.align = 0.
      self.autostart = 0.

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
      buff.write(_get_struct_b15f6b().pack(_x.status, _x.tx, _x.ty, _x.tz, _x.rx, _x.ry, _x.rz, _x.rw, _x.prd, _x.pra, _x.psd, _x.psa, _x.prd1, _x.pra1, _x.psd1, _x.psa1, _x.LP, _x.cLP, _x.nGP, _x.cGN, _x.nIQ, _x.marked))
      _x = self.gps
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.lps
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.lps1
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.lps2
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.lps3
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.lps4
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.lps5
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.lps6
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.lps7
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.lps8
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_8b2f().pack(_x.marked1, _x.marked2, _x.marked3, _x.marked4, _x.marked5, _x.marked6, _x.marked7, _x.marked8, _x.align, _x.autostart))
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
      end += 67
      (_x.status, _x.tx, _x.ty, _x.tz, _x.rx, _x.ry, _x.rz, _x.rw, _x.prd, _x.pra, _x.psd, _x.psa, _x.prd1, _x.pra1, _x.psd1, _x.psa1, _x.LP, _x.cLP, _x.nGP, _x.cGN, _x.nIQ, _x.marked,) = _get_struct_b15f6b().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.gps = str[start:end].decode('utf-8')
      else:
        self.gps = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.lps = str[start:end].decode('utf-8')
      else:
        self.lps = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.lps1 = str[start:end].decode('utf-8')
      else:
        self.lps1 = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.lps2 = str[start:end].decode('utf-8')
      else:
        self.lps2 = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.lps3 = str[start:end].decode('utf-8')
      else:
        self.lps3 = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.lps4 = str[start:end].decode('utf-8')
      else:
        self.lps4 = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.lps5 = str[start:end].decode('utf-8')
      else:
        self.lps5 = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.lps6 = str[start:end].decode('utf-8')
      else:
        self.lps6 = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.lps7 = str[start:end].decode('utf-8')
      else:
        self.lps7 = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.lps8 = str[start:end].decode('utf-8')
      else:
        self.lps8 = str[start:end]
      _x = self
      start = end
      end += 16
      (_x.marked1, _x.marked2, _x.marked3, _x.marked4, _x.marked5, _x.marked6, _x.marked7, _x.marked8, _x.align, _x.autostart,) = _get_struct_8b2f().unpack(str[start:end])
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
      buff.write(_get_struct_b15f6b().pack(_x.status, _x.tx, _x.ty, _x.tz, _x.rx, _x.ry, _x.rz, _x.rw, _x.prd, _x.pra, _x.psd, _x.psa, _x.prd1, _x.pra1, _x.psd1, _x.psa1, _x.LP, _x.cLP, _x.nGP, _x.cGN, _x.nIQ, _x.marked))
      _x = self.gps
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.lps
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.lps1
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.lps2
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.lps3
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.lps4
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.lps5
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.lps6
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.lps7
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.lps8
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_8b2f().pack(_x.marked1, _x.marked2, _x.marked3, _x.marked4, _x.marked5, _x.marked6, _x.marked7, _x.marked8, _x.align, _x.autostart))
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
      end += 67
      (_x.status, _x.tx, _x.ty, _x.tz, _x.rx, _x.ry, _x.rz, _x.rw, _x.prd, _x.pra, _x.psd, _x.psa, _x.prd1, _x.pra1, _x.psd1, _x.psa1, _x.LP, _x.cLP, _x.nGP, _x.cGN, _x.nIQ, _x.marked,) = _get_struct_b15f6b().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.gps = str[start:end].decode('utf-8')
      else:
        self.gps = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.lps = str[start:end].decode('utf-8')
      else:
        self.lps = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.lps1 = str[start:end].decode('utf-8')
      else:
        self.lps1 = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.lps2 = str[start:end].decode('utf-8')
      else:
        self.lps2 = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.lps3 = str[start:end].decode('utf-8')
      else:
        self.lps3 = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.lps4 = str[start:end].decode('utf-8')
      else:
        self.lps4 = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.lps5 = str[start:end].decode('utf-8')
      else:
        self.lps5 = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.lps6 = str[start:end].decode('utf-8')
      else:
        self.lps6 = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.lps7 = str[start:end].decode('utf-8')
      else:
        self.lps7 = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.lps8 = str[start:end].decode('utf-8')
      else:
        self.lps8 = str[start:end]
      _x = self
      start = end
      end += 16
      (_x.marked1, _x.marked2, _x.marked3, _x.marked4, _x.marked5, _x.marked6, _x.marked7, _x.marked8, _x.align, _x.autostart,) = _get_struct_8b2f().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_b15f6b = None
def _get_struct_b15f6b():
    global _struct_b15f6b
    if _struct_b15f6b is None:
        _struct_b15f6b = struct.Struct("<b15f6b")
    return _struct_b15f6b
_struct_8b2f = None
def _get_struct_8b2f():
    global _struct_8b2f
    if _struct_8b2f is None:
        _struct_8b2f = struct.Struct("<8b2f")
    return _struct_8b2f
class mqueue(object):
  _type          = 'htbot/mqueue'
  _md5sum = '8063f205c633b3b5b9493f7d4b8b6575'
  _request_class  = mqueueRequest
  _response_class = mqueueResponse
