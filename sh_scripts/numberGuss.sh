#!/bin/bash

MAX=50
guess=-1
let answer=($RANDOM % $MAX)
let answer+=1
ceilling=$MAX
floor=0
guesses=0

while [ $guess -ne $answer ]
do
	echo "The magic number is between $floor and $ceilling"
	echo -en "Make your geuss:"
	read guess
	guesses=`expr $guesses + 1`
	if [ $guess -lt $answer ];then
		echo "$guess is too low"
		if [ $guess -gt $floor ];then
			floor=`expr $guess + 1`
		fi
	fi
	if [ $guess -gt $answer ];then
		echo "$guess is too high"
		if [ $guess -lt $ceilling ];then
			ceilling=`expr $guess - 1`
		fi
	fi
done
echo "You got it in $guesses guesses!"
