#!/bin/bash
echo "Enter a 5 digit number:"
read n

sum=0
sum=$((sum+n%10))
n=$((n/10))
sum=$((sum+n%10))
n=$((n/10))
sum=$((sum+n%10))
n=$((n/10))
sum=$((sum+n%10))
n=$((n/10))
sum=$((sum+n%10))
n=$((n/10))

echo $sum


