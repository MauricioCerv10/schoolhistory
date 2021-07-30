#include <iostream>
#include <unistd.h>
#include <thread>
#include <atomic>
using namespace std;

atomic<int> globalv(0);

void funcion(int valor){
	printf("Hilo %ld Valor recibido: %d\n",this_thread::get_id(),valor);
	sleep(2);
}
void decrementa(){
	globalv--;
	sleep(1);
}
void incrementa(){
	globalv++;
	sleep(1);
}

void decrementaN(int n){
        for(int i = 0; i<n; i++) globalv--;
        sleep(1);
}
void incrementaN(int n){
        for(int i = 0; i<n; i++) globalv++;
        sleep(1);
}


int main(){
	int n; cin>>n;
	//printf("%d\n",n);
	thread th1(incrementaN,n), th2(decrementaN,n);
	printf("Proceso principal espera que los hilos terminen\n");
	th1.join();
	th2.join();
	cout<<globalv<<endl;
	printf("El hilo principal termina\n");
}
