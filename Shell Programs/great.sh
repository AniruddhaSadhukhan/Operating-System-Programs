#!/bin/bash
echo "Enter 3 numbers:"
read a b c
if [ $a -gt $b -a $a -gt $c ] 
then
	echo $a
elif [ $b -gt $c ] 
then
	echo $b
else echo $c
fi

# Use \* for mul
d=`expr $a + $b + $c`
echo "Sum is $d"

d=$(( $a * $b * $c))
echo "Product is $d"

echo "Product is $(( $a * $b * $c))"
echo $(printf "%s\n" "$a"{+,-,\*,\/}"$b" | bc -l)
#echo $(printf "%s\n"{Add,Diff,Mul,Div} "$a"{+,-,\*,\/}"$b" | bc -l)
