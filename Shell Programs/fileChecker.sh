#!/bin/bash
echo -n "Enter file name: "
read file

if [ -a $file ]
then 
	echo File Exist
	[ -w $file ] && W="write = yes" || W="write = no"
	[ -x $file ] && X="execute = yes" || X="execute = no"
	[ -r $file ] && R="read = yes" || R="read = no"
	
	echo $file permissions
	echo $W
	echo $X
	echo $R
else 
	echo File does not exists
fi
	
	
	
