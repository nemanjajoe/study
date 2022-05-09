#!/bin/bash

quit=0
while read command data;do
	case $command in
		echo)
			echo "echo: $data"
			;;
		upper)
			echo -en "upper: "
			echo $data | tr '[:lower:]' '[:upper:]'
			;;
		lower)
			echo -en "lower: "
			echo $data | tr '[:upper:]' '[:lower:]'
			;;
		quit)
			echo "Quiting..."
			quit=1
			break
			;;
		*)
			echo "valid command area echo, upper, lower, or quit"
			;;
	esac
done

if [ $quit -e 1 ];then
				echo "brokr out of the loop as directed."
else
				echo "Got to the end of the input without being told to quit."
fi
		
