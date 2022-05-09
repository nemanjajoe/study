#!/bin/bash

echo "My name is `basename -s .sh $0` - I was called as `basename -s .sh $0`"
echo "I was called with $# paramerters"
if [ "$#" -ne "2" ];then
	# the "$#" variable must tell us that we have exactly tow parameters,
	# if not, we will alarm the user how to run the script
	echo "Usage: "basename $0": first second."
	echo "You provided $# parameters, but 2 are required."
else 
	echo "My first parameter is: $1"
	echo "My second parameter is: $2"
fi
