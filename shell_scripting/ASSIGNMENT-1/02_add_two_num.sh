#!/usr/bin/env bash

read -p "Enter first number: " num1
read -p "Enter second number: " num2

echo -e "Sum of two numbers $num1 and $num2: $(( num1+num2 ))"
echo -e "Sum of two numbers $num1 and $num2: $(expr $num1 + $num2)"