#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX 256
int main(){
	int tuberia1[2], tuberia2[2], pid;
	char men[MAX], mensaje[MAX];
	if(pipe(tuberia1) == -1 || pipe(tuberia2) == -1){ perror("Error: "); exit(-1);}
	if((pid = fork()) == -1) {perror("Error"); exit(-1);}
	strcpy(mensaje,"hola como estas");
	if(pid == 0){
		read(tuberia1[0], men, MAX);
		strcat(men, " el dia de hoy");
		strcpy(mensaje, men);
		printf("Mensaje recibido %s\n",mensaje);
		write(tuberia2[1],mensaje,strlen(mensaje)+1);
		exit(0);
	}else{
		write(tuberia1[1],mensaje,strlen(mensaje)+1);
		read(tuberia2[0], men,MAX);
		printf("Mensaje recibido %s\n",mensaje);
		wait();
	}
	exit(0);
}
