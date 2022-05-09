#!/bin/bash

for file in `pwd`/*.sh
do
	if [ -f $file ];then
		if [ -e $file.bak ];then
			echo "Error: $file.bak existed!"
		else 
			echo "Backing up $file..."
			cp $file $file.bak
		fi
	fi
done
