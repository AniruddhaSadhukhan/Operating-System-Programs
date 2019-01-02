#!/bin/bash
echo "Enter year:"
read n
if [ $(($n %4)) -eq 0 ] 
then
	if [[ $(($n %100)) -eq 0 && $(($n %400)) -ne 0 ]] 
	then
		echo "Not leap Year"
	else echo "Leap Year"
	fi
else echo "Not leap Year"
fi
