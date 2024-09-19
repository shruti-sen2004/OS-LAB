#!/usr/bin/env bash

#METHOD-1
for i in {1..10..2} #..2 will increment it by 2 
do 
    echo "Output: $i"
done

#METHOD-2

read -p "ENTER THE MAXIMUM LIMIT: " max

for i in $(seq 2 3 "$max" )   #format <start> <increment> <last>
do 
    echo "$i"
done
