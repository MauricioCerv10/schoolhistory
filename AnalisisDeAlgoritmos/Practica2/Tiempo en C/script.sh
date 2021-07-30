#!/bin/bash
clear 
gcc -c tiempo.c 
gcc -o mainBST mainBST.c tiempo.o
./mainBST 100 < numeros10millones.txt >> salidaBST.txt
./mainBST 1000 < numeros10millones.txt >> salidaBST.txt
./mainBST 5000 < numeros10millones.txt >> salidaBST.txt
./mainBST 10000 < numeros10millones.txt >> salidaBST.txt
./mainBST 50000 < numeros10millones.txt >> salidaBST.txt
./mainBST 100000 < numeros10millones.txt >> salidaBST.txt
./mainBST 200000 < numeros10millones.txt >> salidaBST.txt
./mainBST 400000 < numeros10millones.txt >> salidaBST.txt
./mainBST 600000 < numeros10millones.txt >> salidaBST.txt
./mainBST 800000 < numeros10millones.txt >> salidaBST.txt
./mainBST 1000000 < numeros10millones.txt >> salidaBST.txt
./mainBST 2000000 < numeros10millones.txt >> salidaBST.txt
./mainBST 3000000 < numeros10millones.txt >> salidaBST.txt
./mainBST 4000000 < numeros10millones.txt >> salidaBST.txt
./mainBST 5000000 < numeros10millones.txt >> salidaBST.txt
./mainBST 6000000 < numeros10millones.txt >> salidaBST.txt
./mainBST 7000000 < numeros10millones.txt >> salidaBST.txt
./mainBST 8000000 < numeros10millones.txt >> salidaBST.txt
./mainBST 9000000 < numeros10millones.txt >> salidaBST.txt
./mainBST 10000000 < numeros10millones.txt >> salidaBST.txt


