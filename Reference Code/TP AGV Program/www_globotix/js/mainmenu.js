var hostIP = "ws://"+location.host+":8080";
var ros = new ROSLIB.Ros();
ros.connect(hostIP);
var cmdsrv = new ROSLIB.Service({
    ros : ros,
    name : '/web_cmd',
    serviceType : 'htbot/mqueue'
});

var cmdreq = new ROSLIB.ServiceRequest({
    cmd : 1,
    LP : 0,
    GN : 0,
    gps : "",
    lps : "POWER",
		pw : "",
    tx : 1.0,
    ty : 2.0,
    tz : 3.0,
    rx : 0.0,
		ry : 0.0,
    rz : 0.0,
    rw : 0.0,
    prd : 0.0,
		pra : 0.0,
    psd : 0.0,
    psa : 0.0,
    prd1 : 0.0,
    pra1 : 0.0,
    psd1 : 0.0,
    psa1 : 0.0,
    align : 0.0,
    autostart : 0.0 
});

var PM = new ROSLIB.Param({
    ros : ros,
    name : 'mapflag'
});


function mainmenustart() {
	cmdreq.cmd = 91;	
	cmdsrv.callService(cmdreq, function(result) {
    console.log('Result for service call on '
      + cmdsrv.name
      + ': '
      + result.status);
		if (result.status == -1) {
			location.replace("index.html");
		} 
  });
}

function logout() {
	cmdreq.cmd = 58;	
	cmdsrv.callService(cmdreq, function(result) {
    console.log('Result for service call on '
      + cmdsrv.name
      + ': '
      + result.status);
  });
	if(typeof(Storage) !== "undefined") {
    localStorage.clear();	
  } 
	location.replace("index.html");
}

function exitsys() {
	cmdreq.cmd = 580;	
	cmdsrv.callService(cmdreq, function(result) {
    console.log('Result for service call on '
      + cmdsrv.name
      + ': '
      + result.status);
  });
	if(typeof(Storage) !== "undefined") {
    localStorage.clear();	
  } 
	location.replace("index.html");
}

function shutdown_nopwd() {	
	cmdreq.cmd = 2;	
	cmdsrv.callService(cmdreq, function(result) {
    console.log('Result for service call on '
      + cmdsrv.name
      + ': '
      + result.status);		
  });
}





