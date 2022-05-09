#!/bin/bash

function print_usage(){
	echo "Usage: `basename $0` min max n"
	echo "min and max: the random number range"
	echo "n : generated n random number"
}

	if [ "$#" -ne "3" ] 
	then
		print_usage
		exit
	fi
	for i in $1 $2 $3
	do
		grep -q '^[0-9]*$' <<< "$i"
		if [ "$?" -ne "0" ]; then
			echo "$i is a number"	
		fi
	done
	if [ "$?" -ne "0" ]
	then
		print_usage
		exit
	fi

let  scope="$2 - $1"
if [ "$scope" -le "0" ] 
then
	echo "Error - max is less than min"
fi

for i in `seq 1 $3`
do
	let result="$RANDOM % $scope + $1"
	echo "random number$i between $1 and $2 is $result"
done
