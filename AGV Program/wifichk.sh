#!/bin/bash -e

while true ; do
	if ifconfig wlan0 | grep -q "inet addr:" ; then
		sleep 10
	else
		echo "Network connection down! Attempting reconnection."
		sudo ifup --force wlan0
		sleep 10
	fi
done
