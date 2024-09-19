#!/bin/bash

read -p "Enter first number: " num1
read -p "Enter second number: " num2
read -p "Enter third number: " num3

smallest=$num1
middle=$num2
largest=$num3

if [ "$num1" -le "$num2" ] && [ "$num1" -le "$num3" ]; then
    smallest=$num1
    if [ "$num2" -le "$num3" ]; then
        middle=$num2
        largest=$num3
    else
        middle=$num3
        largest=$num2
    fi
elif [ "$num2" -le "$num1" ] && [ "$num2" -le "$num3" ]; then
    smallest=$num2
    if [ "$num1" -le "$num3" ]; then
        middle=$num1
        largest=$num3
    else
        middle=$num3
        largest=$num1
    fi
else
    smallest=$num3
    if [ "$num2" -le "$num1" ]; then
        middle=$num2
        largest=$num1
    else
        middle=$num1
        largest=$num2
    fi
fi

echo -e "Smallest: $smallest \nMiddle : $middle \nLargest: $largest"


    

