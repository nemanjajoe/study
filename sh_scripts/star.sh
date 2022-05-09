#!/bin/sh

echo  Dollar Star is $*
echo "Dollar Star in double quotes is $*"
echo 'Dollar Star in single quotes is $*'
echo  Dollar At is $@
echo "Dollar At in double quotes is $@"
echo 'Dollar At in single quotes is $@'
echo "////////////////////////////////"
echo "Looping through Dollar Star:"
for i in $*
do
	echo Parameter is $i
done
echo "////////////////////////////////"
echo
echo "Looping through Dollar At:"
for i in $@
do
	echo Parameter is $i
done
echo "//////////////////////////////"
echo
echo "Looping through Dollar Star in quotes:"
for i in $*
do
	echo "Parameter is $i"
done
echo "/////////////////////////////"
echo
echo "Looping through Dollar At in quotes:"
for i in $@
do
	echo "Parameter is $i"
done
