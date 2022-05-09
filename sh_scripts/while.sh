#!/bin/bash

i=1
while [ $i -lt 1000 ];do
	echo "i is $i"
	let i=2*$i
done
echo "Finished because i is now $i"
