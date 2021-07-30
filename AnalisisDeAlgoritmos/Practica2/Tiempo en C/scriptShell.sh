#!/bin/bash
clear 
gcc -c tiempo.c 
gcc -o main main.c tiempo.o
./main 100 < numeros10millones.txt >> salidaShell.txt
./main 1000 < numeros10millones.txt >> salidaShell.txt
./main 5000 < numeros10millones.txt >> salidaShell.txt
./main 10000 < numeros10millones.txt >> salidaShell.txt
./main 50000 < numeros10millones.txt >> salidaShell.txt
./main 100000 < numeros10millones.txt >> salidaShell.txt
./main 200000 < numeros10millones.txt >> salidaShell.txt
./main 400000 < numeros10millones.txt >> salidaShell.txt
./main 600000 < numeros10millones.txt >> salidaShell.txt
./main 800000 < numeros10millones.txt >> salidaShell.txt
./main 1000000 < numeros10millones.txt >> salidaShell.txt
./main 2000000 < numeros10millones.txt >> salidaShell.txt
./main 3000000 < numeros10millones.txt >> salidaShell.txt
./main 4000000 < numeros10millones.txt >> salidaShell.txt
./main 5000000 < numeros10millones.txt >> salidaShell.txt
./main 6000000 < numeros10millones.txt >> salidaShell.txt
./main 7000000 < numeros10millones.txt >> salidaShell.txt
./main 8000000 < numeros10millones.txt >> salidaShell.txt
./main 9000000 < numeros10millones.txt >> salidaShell.txt
./main 10000000 < numeros10millones.txt >> salidaShell.txt



