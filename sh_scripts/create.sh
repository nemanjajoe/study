#!/bin/bash

LOGFILE=/tmp/sh_create.log

showfile(){
	if [ -f $1 ];then
					ls -l $1
					echo "--- the content are:"
					cat $1
					echo "--- end of file"
	else
					echo "The file does not currently exist"
	fi
	
}

	echo "Testing  $LOGFILE	for the first time."
	showfile	$LOGFILE
	
	echo "Writing to $LOGFILE"
	date > $LOGFILE
	
	echo "Testing  $LOGFILE	for the second time."
	showfile  $LOGFILE

	sleep 5
	echo "Writing to  $LOGFILE again."
	date >  $LOGFILE 
	echo "Testing  $LOGFILE for the third and file time."
	showfile  $LOGFILE

