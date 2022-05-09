#!/bin/bash

oIFS=$IFS
IFS="
"
count=1
txt=(`cat ./wget_manual.txt`)
for i in ${txt[@]}
do
			echo "line $count: $i"
			count=`expr $count + 1`
done	

