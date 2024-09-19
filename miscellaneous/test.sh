#!/usr/bin/env bash

read -p "Enter your name: " name
echo -e "${name}"

"$var"      # use the variable
"${var}"    # same as above
"${var}bar" # expand var, and append "bar" too
"$varbar"   # same as ${varbar}, i.e expand a variable called varbar, if it exists.