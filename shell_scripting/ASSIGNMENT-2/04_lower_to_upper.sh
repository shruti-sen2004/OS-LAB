#!/usr/bin/env bash

read -p "Enter a string: " string

echo "$string" | tr "[:lower:]" "[:upper:]"