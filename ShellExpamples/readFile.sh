#!/bin/sh
while read f
do
	case $f in
		hello)		echo English	;;
		gday)		echo Autralian	;;
		bonjour)	echo French	;;
		*)		echo Unknown Language: ${f}
		;;
	esac
done < myfile.txt
