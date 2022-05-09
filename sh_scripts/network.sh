#!/bin/bash

[ -z "$_definitions" ] && . definitions
[ -f /etc/debian_version ] && . ./debian_network

for thisnic in $*
do
				thisip=`getipddr $thisnic`
				case $? in
					$SUCCESS) echo "the IP Address configured for $thisnic is $thisip";;
					$_NO_IP) echo "No IP Address defined for thisnic";;
					$_NO_CONFIG) echo "No configuration found for $thisnic";;
				esac
done
