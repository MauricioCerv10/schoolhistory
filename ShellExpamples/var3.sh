#!/bin/sh
echo "What is your name?"
read name
echo "I will create you a file called ${name}_file"
touch "${name}_file" 

