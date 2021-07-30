#include <iostream>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <math.h>
#define Max 100000000

using namespace std;

mutex m;

int funcion1(){
	double i2 = 0;
	double seno2=0, coseno2=0, tangente2=0, logaritmo2=0, raizCuad2=0;
	while (i2 < Max){
		m.lock();
		seno2 += sin(i2);
		coseno2 += cos(i2);
		tangente2 += tan(i2);
		logaritmo2 += log(i2);
		raizCuad2 += sqrt(i2);
		i2++;
		m.unlock();
	}
	return 0;
}

int funcion2(){
	double i = 0;
	double seno=0, coseno=0, tangente=0, logaritmo=0, raizCuad=0;
	while (i < Max){
		m.lock();
		seno += sin(i);
		coseno += cos(i);
		tangente += tan(i);
		logaritmo += log(i);
		raizCuad += sqrt(i);
		i++;
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
