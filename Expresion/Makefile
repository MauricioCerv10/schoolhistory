a.out: main.o archivos.o solucion.o expresion.o hash.o
	gcc main.o archivos.o solucion.o expresion.o hash.o
main.o: main.c
	gcc -c main.c
archivos.o: archivos.c
	gcc -c archivos.c
solucion.o: solucion.c
	gcc -c solucion.c
expresion.o: expresion.c
	gcc -c expresion.c
hash.o: hash.c
	gcc -c hash.c
clean: main.o archivos.o solucion.o expresion.o hash.o
	rm main.o archivos.o solucion.o expresion.o hash.o
run: a.out
	./a.out
