#!/bin/bash

echo "My name is `basename -s .sh $0`."
echo "I was called with $# parameters."
count=1
while [ "$#" -ge "1" ]; do
	echo "We have $# parameters left now."
	echo "I am the '$count'th one. Called $1"
	let count=$count+1
	shift
done
