#!/bin/bash

max_pid=$(cat /proc/sys/kernel/pid_max)
echo "The maximum process ID value is: $max_pid"
