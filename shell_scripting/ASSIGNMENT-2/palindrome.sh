#!/usr/bin/env bash

palindrome() {
    string=$(echo "$1" | tr "[:upper:]" "[:lower:]") 
    if [ "$(echo $string | rev)" == $string ]; then 
        echo "String is palindrome"
    else
        echo "String is not palindrome"
    fi
}

read -p "Enter a string: " string
palindrome "$string"