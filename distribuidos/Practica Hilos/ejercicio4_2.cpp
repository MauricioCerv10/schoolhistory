#include <iostream>
#include <unistd.h>
#include <thread>
#include <mutex>
#define numeroElementos 100000000

using namespace std;

mutex m;

int funcion1(){
	int *arreglo2, i2;
	arreglo2 = new int[numeroElementos];
	for(i2 = 0; i2 < numeroElementos; i2++)
		arreglo2[i2] = 0;
	for(i2 = 0; i2 < 100000000; i2++){
		m.lock();
		arreglo2[rand()%numeroElementos] = rand();
		m.unlock();
	}
	return 0;
}

int funcion2(){
	int *arreglo, i;
	arreglo = new int[numeroElementos];
	for(i = 0; i < numeroElementos; i++)
		arreglo[i] = 0;
	for(i = 0; i < 100000000; i++){
		m.lock();
		arreglo[rand()%numeroElementos] = rand();
		m.unlock();
	}
	return 0;
}

int main(){
	printf("Proceso principal espera que los hilos terminen\n");
	thread th1(funcion1);
	thread th2(funcion2);
	th1.join();
	th2.join();
	exit(0);
}
