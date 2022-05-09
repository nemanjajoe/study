#!/bin/bash

echo -n "Enter a size in Kb: "
read kb
bytes=`expr $kb \* 1024`
mb=`expr $kb / 1024`
echo "${kb}kb is ${bytes}bytes, or approx ${mb}Mb."

