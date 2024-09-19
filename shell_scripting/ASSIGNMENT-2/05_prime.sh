#!/usr/bin/env bash

function prime() {
    num=$i 
    if [ $num -lt 2 ]; then
    echo "$num is not prime"
    else
        for ((i=2; i<= num/2 ; i++)); do
            if [ $((num % i)) -eq 0 ]; then
                echo "$num is not prime"
                return
            fi
        done
        echo "$num is prime"
    fi
}

read -p "Enter a number: " num
prime "$num"