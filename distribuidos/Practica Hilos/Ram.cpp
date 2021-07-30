
#include <iostream>

using namespace std;

#define numeroElementos 290001000

int main(){
	int *arreglo, i;

    arreglo = new int[numeroElementos];

	for(i = 0; i < numeroElementos; i++) 
		arreglo[i] = 0;

    for(i = 0; i < numeroElementos; i++){
        arreglo[rand()%numeroElementos] = rand();
	} 
}

