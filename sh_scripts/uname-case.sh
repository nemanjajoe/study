#!/bin/bash

OS=`uname -s`

case $OS in 
	FreeBSD) echo "this is FreeBSD";;
	Minix) echo "this is Minix";;
	Linux) echo "this is Linux";;
	*) echo "Failed to identify this OS";;
esac
