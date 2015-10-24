#!/bin/bash 

msg=$1
coreid=$2

if [ -z $coreid ]
then 
	echo "Usage:$0 msg coreid"
	exit 1
fi

taskset -c $coreid ./test $msg
