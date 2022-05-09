#!/bin/bash

beatles=(John Paul Ringo George)
for index in `seq 0 $((${#beatles[@]} - 1))`
do
				echo "Beatles $index is ${beatles[$index]}."
done
