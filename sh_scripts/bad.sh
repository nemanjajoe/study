#!/bin/bash

for i in 	`seq -w 1 10` 14 19 13
do
				j=`expr $i \* $i`
				echo "`date`: I am `basename $0` and I can count to $i," \
						 "Which is not particularly impressive, especially as I get a bit" \
						 "
