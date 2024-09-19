#!/usr/bin/env bash

read -p "Enter name: " name

case $name in
    "Ritu" | "Rituja" | "Riyu" ) echo -e "Hi Ritu";;
    "Shruti" | "shruti" | "shru" | "Shru" ) echo -e "Hi Shru";;
esac


echo "THE LENGTH OF THE STRING: ${#name}" #to find the length of the string use "#"