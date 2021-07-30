#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct param{
        int size;
	int ini;
	int fin;
	int arr[1005];
};


int compare(const void *_a, const void *_b) {
 
        int *a, *b;
        
        a = (int *) _a;
        b = (int *) _b;
        
        return (*a - *b);
}

void ordena(struct param *mensa){
	qsort(mensa->arr, mensa->size, sizeof(int), &compare);

}

int main(){
	struct param params[10];
	pthread_t ths[10];
	int aleatorios[1000];
	for(int i = 0; i < 1000; i++){
		int num = rand()%3800;
		aleatorios[i] = num;
	}
	int rangos = 0;
	printf("Teclee el numero de rangos que desea\n");
	scanf("%d",&rangos);
	
	int rtam = 1000/rangos;
	int ini = 0;
	int fin = rtam;
	for(int i = 0; i<rangos; i++){
		params[i].size = 0;
		params[i].ini = ini;
		params[i].fin = fin;
		for(int j = 0; j < 1000 ; j++){
			if(aleatorios[j] >= ini && aleatorios[j] <= fin){
				params[i].arr[params[i].size] = aleatorios[j];
				params[i].size += 1;
			}
		}
		if(i == rangos - 1){
			ini = fin + 1;
			fin = 1000;
		}else{
			ini = fin + 1;
			fin += rtam;
		}
	}
	for(int i = 0; i < rangos; i++){
               pthread_create (&ths[i], NULL, (void*)ordena, (void*)&params[i]); 
        }
	for(int i = 0; i < rangos; i++){
		pthread_join(ths[i], NULL);
	}
	for(int i = 0; i < rangos; i++){
		printf("Inicio = %d  Fin = %d \n",params[i].ini,params[i].fin);
		for(int j = 0; j < params[i].size; j++){
			printf("%d\n",params[i].arr[j]);
		}
	}
}
