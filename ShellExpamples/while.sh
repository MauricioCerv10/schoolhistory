#!/bin/sh
inputStr="hola"
while [ ${inputStr} != "bye" ]
do
	echo "TU mensaje es ${inputStr}. Escribe algo"
	read inputStr
done
