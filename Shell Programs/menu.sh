#!/bin/bash
c=0
while [ $c -lt 4 ]
do
tput clear
echo 1.Contents of etc/passwd
echo 2.List of users logged in
echo 3.Present Working Directory
echo 4.Exit
echo Enter Choice:
read c

if [ $c -eq 1 ]
then 
	cat /etc/passwd | more
	read a
elif [ $c -eq 2 ]
then 
	who | more
	read a
elif [ $c -eq 3 ]
then 
	pwd
	read a
fi
done
