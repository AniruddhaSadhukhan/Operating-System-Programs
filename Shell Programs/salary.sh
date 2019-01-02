#!/bin/bash
echo Enter Salary
read sal
ta=$((sal*15/100))
echo TA = $ta
da=$((sal*2/100))
echo DA = $da
hrl=$((sal*10/100))
echo HRL = $hrl
sal=$((sal+ta+da+hrl))
echo Salary = $sal
it=$((sal*5/100))
echo Income Tax = $it
pf=$((sal*10/100))
echo Provident Fund = $pf
sal=$((sal-it-pf))
echo Salary = $sal
