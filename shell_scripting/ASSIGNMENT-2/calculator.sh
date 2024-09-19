#!/usr/bin/env bash

read -p "Enter num1: " num1
read -p "Enter num2: " num2

sum=$(echo $num1 + $num2 | bc -l) # -l = --mathlib
echo -e "Sum is: $sum"

log=$(echo "scale=3; l($num1)" | bc -l)
echo -e "Log is: $log"