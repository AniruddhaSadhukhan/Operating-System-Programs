#!/bin/bash
clear
echo "Hello $USER"
echo -e "Today is \c ";date
echo -e "Number of user login : \c ";who | wc -l
echo -e "Today is `date +%d-%m-%y:%r`"
echo "CALENDER"
cal 

