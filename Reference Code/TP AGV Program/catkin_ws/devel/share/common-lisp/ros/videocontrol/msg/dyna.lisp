; Auto-generated. Do not edit!


(cl:in-package videocontrol-msg)


;//! \htmlinclude dyna.msg.html

(cl:defclass <dyna> (roslisp-msg-protocol:ros-message)
  ((paramid
    :reader paramid
    :initarg :paramid
    :type cl:fixnum
    :initform 0)
   (intValue
    :reader intValue
    :initarg :intValue
    :type cl:integer
    :initform 0)
   (doubleValue
    :reader doubleValue
    :initarg :doubleValue
    :type cl:float
    :initform 0.0)
   (strValue
    :reader strValue
    :initarg :strValue
    :type cl:string
    :initform "")
   (boolValue
    :reader boolValue
    :initarg :boolValue
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass dyna (<dyna>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <dyna>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'dyna)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name videocontrol-msg:<dyna> is deprecated: use videocontrol-msg:dyna instead.")))

(cl:ensure-generic-function 'paramid-val :lambda-list '(m))
(cl:defmethod paramid-val ((m <dyna>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader videocontrol-msg:paramid-val is deprecated.  Use videocontrol-msg:paramid instead.")
  (paramid m))

(cl:ensure-generic-function 'intValue-val :lambda-list '(m))
(cl:defmethod intValue-val ((m <dyna>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader videocontrol-msg:intValue-val is deprecated.  Use videocontrol-msg:intValue instead.")
  (intValue m))

(cl:ensure-generic-function 'doubleValue-val :lambda-list '(m))
(cl:defmethod doubleValue-val ((m <dyna>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader videocontrol-msg:doubleValue-val is deprecated.  Use videocontrol-msg:doubleValue instead.")
  (doubleValue m))

(cl:ensure-generic-function 'strValue-val :lambda-list '(m))
(cl:defmethod strValue-val ((m <dyna>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader videocontrol-msg:strValue-val is deprecated.  Use videocontrol-msg:strValue instead.")
  (strValue m))

(cl:ensure-generic-function 'boolValue-val :lambda-list '(m))
(cl:defmethod boolValue-val ((m <dyna>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader videocontrol-msg:boolValue-val is deprecated.  Use videocontrol-msg:boolValue instead.")
  (boolValue m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <dyna>) ostream)
  "Serializes a message object of type '<dyna>"
  (cl:let* ((signed (cl:slot-value msg 'paramid)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'intValue)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'doubleValue))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'strValue))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'strValue))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'boolValue) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <dyna>) istream)
  "Deserializes a message object of type '<dyna>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'paramid) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'intValue) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'doubleValue) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'strValue) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'strValue) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:slot-value msg 'boolValue) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<dyna>)))
  "Returns string type for a message object of type '<dyna>"
  "videocontrol/dyna")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'dyna)))
  "Returns string type for a message object of type 'dyna"
  "videocontrol/dyna")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<dyna>)))
  "Returns md5sum for a message object of type '<dyna>"
  "6d03e42ff56dea7eeef77a3e537361b9")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'dyna)))
  "Returns md5sum for a message object of type 'dyna"
  "6d03e42ff56dea7eeef77a3e537361b9")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<dyna>)))
  "Returns full string definition for message of type '<dyna>"
  (cl:format cl:nil "int8 paramid~%int32 intValue~%float64 doubleValue~%string strValue~%bool boolValue~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'dyna)))
  "Returns full string definition for message of type 'dyna"
  (cl:format cl:nil "int8 paramid~%int32 intValue~%float64 doubleValue~%string strValue~%bool boolValue~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <dyna>))
  (cl:+ 0
     1
     4
     8
     4 (cl:length (cl:slot-value msg 'strValue))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <dyna>))
  "Converts a ROS message object to a list"
  (cl:list 'dyna
    (cl:cons ':paramid (paramid msg))
    (cl:cons ':intValue (intValue msg))
    (cl:cons ':doubleValue (doubleValue msg))
    (cl:cons ':strValue (strValue msg))
    (cl:cons ':boolValue (boolValue msg))
))
