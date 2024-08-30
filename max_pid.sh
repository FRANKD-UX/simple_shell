#!/bin/bash

# Check if /proc/sys/kernel/pid_max exists
if [ -f /proc/sys/kernel/pid_max ]; then
	# Read the maximum PID value from /proc/sys/kernel/pid_max
	max_pid=$(cat /proc/sys/kernel/pid_max)
	echo "The maximum value a process ID can be is: $max_pid"
else
	echo "Cannot determine the maximum PID value. /proc/sys/kernel/pid_max not found."
	exit 1
fi
