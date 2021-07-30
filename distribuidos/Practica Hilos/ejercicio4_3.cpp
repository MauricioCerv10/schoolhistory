#include <iostream>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <math.h>
#define numeroElementos 100000000
#define Max 90000000
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
int main(){
	printf("Proceso principal espera que los hilos terminen\n");
	thread th1(funcion1);
	thread th2(funcion1);
	th1.join();
	th2.join();
	exit(0);
}
