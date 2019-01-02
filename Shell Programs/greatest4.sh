#!/bin/bash
echo "Enter 4 numbers:"
read a b c d
if ((a>b))
then 
	if((a>c))
	then
		if((a>d))
		then
			echo $a
		else echo $d
		fi
	elif ((c>d))
	then
		echo $c
	else echo $d
	fi
elif((b>c))
then 
	if((b>d))
	then
		echo $b
	else echo $d
	fi
elif((c>d))
then
	echo $c
else echo $d
fi
		
	
	
	
