#!/bin/bash

while read filename
do
if [! -e "$filename" ];then
	echo "The file dose not exist."
	continue
fi

ls -ld "$filename"

if [ -L "$filename" ];then
	echo "$filename is a symbolic link"
elif [ -f "$filename" ];then
	echo "$filename is a regular file"
elif [ -b "$filename" ];then
	echo "$filename is a block device"
elif [ -c "$filename" ];then
	echo "$filename is a character device"
elif [ -d "$filename" ];then
	echo "$filename is a directory"
elif [ -p "$filename" ];then
	echo "$filename is a pipe"
elif [ -S "$filename" ];then
	echo "$filename is a socket"
else
	echo "I don't know what kind of file that is"
fi
done
