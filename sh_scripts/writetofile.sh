#!/bin/bash

myfunc(){
	thefile=$1
	echo "Helloe number $2" >> $thefile				
}

file1=/tmp/file.1
file2=`mktemp`

for i in `seq 1 10000`;do
		myfunc $file1 $i
		myfunc $file2 `expr $RANDOM % 10 \* $i`
done

echo "file1 says:"
cat $file1
echo "file2 says:"
cat $file2

rm -f $file1 $file2
