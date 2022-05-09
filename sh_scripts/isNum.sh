#!/bin/bash

while [ "$#" -ge "1" ];
do
	if grep -q '^[0-9]*$' <<< $1 ; then
		echo "$1 is a number.";
	else 
		echo "$1 is not a number.";
	fi
	shift
done
