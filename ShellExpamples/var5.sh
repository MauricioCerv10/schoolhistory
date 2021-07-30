#!/bin/sh
echo "Whats is your name [ `whoami` ] \c"
read myname
if [ -z "$myname" ]; then
	myname=`whoami`
fi
echo "Yor name is ${myname}"
