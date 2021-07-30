#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include<string.h>  
#include<fcntl.h> 

int const Tam = 10;

void Invierte(int Dim, float Sist[][Tam], float Inv[][Tam])
{
	int NoCero,Col,C1,C2,A;
        float Pivote,V1,V2;
 
        /*Se inicializa la matriz inversa, como la matriz identidad:*/
        for(C1=1;C1<=Dim;C1++) 	
                for(C2=1;C2<=Dim;C2++)
                        if (C1==C2) Inv[C1][C2]=1; 
                        else Inv[C1][C2]=0;
	
 
        for(Col=1;Col<=Dim;Col++){
                NoCero=0;A=Col;
                while(NoCero==0){
                        if((Sist[A][Col]>0.0000001)||((Sist[A][Col]<-0.0000001))){
                                NoCero=1;
                        }else A++;
                }
                Pivote=Sist[A][Col];
                for(C1=1;C1<=Dim;C1++){
                        V1=Sist[A][C1];
                        Sist[A][C1]=Sist[Col][C1];
                        Sist[Col][C1]=V1/Pivote;
                        V2=Inv[A][C1];
                        Inv[A][C1]=Inv[Col][C1];
                        Inv[Col][C1]=V2/Pivote;
                }
                for(C2=Col+1;C2<=Dim;C2++){
                        V1=Sist[C2][Col];
                        for(C1=1;C1<=Dim;C1++){
                                Sist[C2][C1]=Sist[C2][C1]-V1*Sist[Col][C1];
                                Inv[C2][C1]=Inv[C2][C1]-V1*Inv[Col][C1];
                        }
                }
        }
	
	
	/*Aqui ya esta triangularizada, con 1s en diagonal, ahora se diagonaliza*/
        for(Col=Dim;Col>=1;Col--) 
                for(C1=(Col-1);C1>=1;C1--)
                {
                        V1=Sist[C1][Col]; 
                        for(C2=1;C2<=Dim;C2++){
                                Sist[C1][C2]=Sist[C1][C2]-V1*Sist[Col][C2];
                                Inv[C1][C2]=Inv[C1][C2]-V1*Inv[Col][C2];
                        }
                }
 	
}

pthread_t t1,t2,t3,t4,t5,t6;
void *suma(){
	float matr1[11][11]={ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
				{-1,0,11,23,4,5,7,8,3,0,10},
				{-1,7,45,34,2,0,1,9,3,6,1},
				{-1,2,0,3,5,5,6,7,8,9,10},
                              	{-1,1,0,0,3,6,7,9,1,5,0},
				{-1,2,4,4,5,8,6,0,0,1,9},
				{-1,1,1,8,9,3,4,2,1,1,0},
				{-1,5,0,8,6,4,5,3,10,9,11},
                                {-1,0,0,0,4,5,7,2,32,10,5},
				{-1,4,5,9,6,3,1,10,0,2,7},
				{-1,3,5,6,7,2,3,4,6,9,9} };
	float matr2[11][11]={ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
				{-1,0,0,1,3,2,9,4,0,3,8},
				{-1,0,7,0,2,4,1,7,8,3,0},
				{-1,1,7,5,4,2,0,1,9,3,3},
				{-1,2,0,8,1,1,3,5,18,3,10},
                                {-1,1,0,10,3,3,7,9,0,1,0},
				{-1,2,4,4,1,8,3,0,0,1,9},
				{-1,13,21,8,9,3,0,2,7,11,0},
				{-1,3,0,0,3,4,21,20,10,9,11},
                                {-1,0,10,0,4,1,7,12,3,10,1},
				{-1,7,1,0,4,3,0,6,10,2,8} };
	float matrRes[11][11];	
	int i,j;
        for(i=1; i<=10; i++)
        	for(j=1; j<=10; j++)
                	matrRes[i][j]=matr1[i][j]+matr2[i][j];


	FILE *file = fopen("sumMatr.txt","w");
	fprintf(file,"\nSuma de Matrices \n");
	fprintf(file,"\n");

	for(i=1; i<=10; i++)
        	for(j=1; j<=10; j++){
			fprintf(file," %.02f ", matrRes[i][j]);
                        if(j==10)
                        	fprintf(file,"\n");
        }
 	fprintf(file,"\n");
	fclose(file);
}

void *resta(void *argp2){
	float matr1[11][11]={ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
				{-1,0,11,23,4,5,7,8,3,0,10},
				{-1,7,45,34,2,0,1,9,3,6,1},
				{-1,2,0,3,5,5,6,7,8,9,10},
                              	{-1,1,0,0,3,6,7,9,1,5,0},
				{-1,2,4,4,5,8,6,0,0,1,9},
				{-1,1,1,8,9,3,4,2,1,1,0},
				{-1,5,0,8,6,4,5,3,10,9,11},
                                {-1,0,0,0,4,5,7,2,32,10,5},
				{-1,4,5,9,6,3,1,10,0,2,7},
				{-1,3,5,6,7,2,3,4,6,9,9} };
	float matr2[11][11]={ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
				{-1,0,0,1,3,2,9,4,0,3,8},
				{-1,0,7,0,2,4,1,7,8,3,0},
				{-1,1,7,5,4,2,0,1,9,3,3},
				{-1,2,0,8,1,1,3,5,18,3,10},
                                {-1,1,0,10,3,3,7,9,0,1,0},
				{-1,2,4,4,1,8,3,0,0,1,9},
				{-1,13,21,8,9,3,0,2,7,11,0},
				{-1,3,0,0,3,4,21,20,10,9,11},
                                {-1,0,10,0,4,1,7,12,3,10,1},
				{-1,7,1,0,4,3,0,6,10,2,8} };
			FILE *file = fopen("restMatr.txt","w"); 
			fprintf(file,"\nResta de Matrices\n");
			float matrRes[11][11];
        		int i,j;

        		for(i=1; i<=10; i++)
                		for(j=1; j<=10; j++)
                        		matrRes[i][j]=matr1[i][j]-matr2[i][j];

			fprintf(file,"\n");
        		for(i=1; i<=10; i++)
                		for(j=1; j<=10; j++)
                		{

                        		fprintf(file," %.02f ", matrRes[i][j]);
                        		if(j==10)
                                		fprintf(file,"\n");
                		}
 			fprintf(file,"\n");
			fclose(file);
}

void *mult(void *argp3){
	
	float matr1[11][11]={ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
				{-1,0,11,23,4,5,7,8,3,0,10},
				{-1,7,45,34,2,0,1,9,3,6,1},
				{-1,2,0,3,5,5,6,7,8,9,10},
                              	{-1,1,0,0,3,6,7,9,1,5,0},
				{-1,2,4,4,5,8,6,0,0,1,9},
				{-1,1,1,8,9,3,4,2,1,1,0},
				{-1,5,0,8,6,4,5,3,10,9,11},
                                {-1,0,0,0,4,5,7,2,32,10,5},
				{-1,4,5,9,6,3,1,10,0,2,7},
				{-1,3,5,6,7,2,3,4,6,9,9} };
	float matr2[11][11]={ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
				{-1,0,0,1,3,2,9,4,0,3,8},
				{-1,0,7,0,2,4,1,7,8,3,0},
				{-1,1,7,5,4,2,0,1,9,3,3},
				{-1,2,0,8,1,1,3,5,18,3,10},
                                {-1,1,0,10,3,3,7,9,0,1,0},
				{-1,2,4,4,1,8,3,0,0,1,9},
				{-1,13,21,8,9,3,0,2,7,11,0},
				{-1,3,0,0,3,4,21,20,10,9,11},
                                {-1,0,10,0,4,1,7,12,3,10,1},
				{-1,7,1,0,4,3,0,6,10,2,8} };
	FILE *file = fopen("multMatr.txt","w");
	fprintf(file,"\nMultiplicacion de Matrices \n"); 
	float matrRes[11][11];

       	int f,c,i, sum=0;


        for(f=1; f<=10; f++){
        	for(c=1; c<=10; c++){
                	for(i=1; i<=10; i++)
                        	sum= sum+ (matr1[f][i] * matr2[i][c]);
				matrRes[f][c]=sum;
                        	sum=0;
                	}

        }

       	for(f=1; f<=10; f++)
        	for(c=1; c<=10; c++){
                	fprintf(file," %.02f ", matrRes[f][c]);
                       	if(c==10)
                        	fprintf(file,"\n");
                }
	fprintf(file,"\n");
	fclose(file);
}

void *trans(void *argp4){
	float matr1[11][11]={ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
				{-1,0,11,23,4,5,7,8,3,0,10},
				{-1,7,45,34,2,0,1,9,3,6,1},
				{-1,2,0,3,5,5,6,7,8,9,10},
                              	{-1,1,0,0,3,6,7,9,1,5,0},
				{-1,2,4,4,5,8,6,0,0,1,9},
				{-1,1,1,8,9,3,4,2,1,1,0},
				{-1,5,0,8,6,4,5,3,10,9,11},
                                {-1,0,0,0,4,5,7,2,32,10,5},
				{-1,4,5,9,6,3,1,10,0,2,7},
				{-1,3,5,6,7,2,3,4,6,9,9} };
	float matr2[11][11]={ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
				{-1,0,0,1,3,2,9,4,0,3,8},
				{-1,0,7,0,2,4,1,7,8,3,0},
				{-1,1,7,5,4,2,0,1,9,3,3},
				{-1,2,0,8,1,1,3,5,18,3,10},
                                {-1,1,0,10,3,3,7,9,0,1,0},
				{-1,2,4,4,1,8,3,0,0,1,9},
				{-1,13,21,8,9,3,0,2,7,11,0},
				{-1,3,0,0,3,4,21,20,10,9,11},
                                {-1,0,10,0,4,1,7,12,3,10,1},
				{-1,7,1,0,4,3,0,6,10,2,8} };
	FILE *file = fopen("transMatr.txt","w");
	int i,j;
	fprintf(file,"\nMatriz transpuesta 1\n");
	for(i = 1;i <= 10;i++){
      		for(j = 1;j <= 10;j++){
          		fprintf(file," %.02f ", matr1[j][i]);
			if(j == 10) fprintf(file,"\n");
		}
        }
	fprintf(file,"\nMatriz transpuesta 2\n");

	for(i = 1;i <= 10;i++){
      		for(j = 1;j <= 10;j++){
         		fprintf(file," %.02f ", matr2[j][i]);				
			if(j == 10) fprintf(file,"\n");
          	}
	} 
	fprintf(file,"\n");
	fclose(file);
}

void *inversa(void *argp5){
	float matr1[11][11]={ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
				{-1,0,11,23,4,5,7,8,3,0,10},
				{-1,7,45,34,2,0,1,9,3,6,1},
				{-1,2,0,3,5,5,6,7,8,9,10},
                              	{-1,1,0,0,3,6,7,9,1,5,0},
				{-1,2,4,4,5,8,6,0,0,1,9},
				{-1,1,1,8,9,3,4,2,1,1,0},
				{-1,5,0,8,6,4,5,3,10,9,11},
                                {-1,0,0,0,4,5,7,2,32,10,5},
				{-1,4,5,9,6,3,1,10,0,2,7},
				{-1,3,5,6,7,2,3,4,6,9,9} };
	float matr2[11][11]={ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
				{-1,0,0,1,3,2,9,4,0,3,8},
				{-1,0,7,0,2,4,1,7,8,3,0},
				{-1,1,7,5,4,2,0,1,9,3,3},
				{-1,2,0,8,1,1,3,5,18,3,10},
                                {-1,1,0,10,3,3,7,9,0,1,0},
				{-1,2,4,4,1,8,3,0,0,1,9},
				{-1,13,21,8,9,3,0,2,7,11,0},
				{-1,3,0,0,3,4,21,20,10,9,11},
                                {-1,0,10,0,4,1,7,12,3,10,1},
				{-1,7,1,0,4,3,0,6,10,2,8} };
	int i,j;
	int C,Dimension;
	float inversa1[11][11], inversa2[11][11];
        		
	FILE *file = fopen("InvMatr.txt","w");
			
        Invierte(10,matr1,inversa1);
        fprintf(file,"\nLa inversa de la matriz 1 es: \n\n");
	for(i=1; i<=10; i++)
        	for(j=1; j<=10; j++){
               		fprintf(file," %.2f ", inversa1[i][j]);
                        if(j==10)
                        	fprintf(file,"\n");
                }
      	fprintf(file,"\n");
	Invierte(10,matr2,inversa2);
        fprintf(file,"\nLa inversa de la matriz 2 es: \n\n");
        for(i=1; i<=10; i++)
        	for(j=1; j<=10; j++){
			fprintf(file," %.2f ", inversa2[i][j]);
                        if(j==10)
                        	fprintf(file,"\n");
                        }
        fprintf(file,"\n");
	fclose(file); 
}

void *leer(void *argp6){
	char caracter;
	
    	FILE *file = fopen("sumMatr.txt","r");

   	if (file == NULL) printf("\nError de apertura del archivo. \n\n");
       	else while((caracter = fgetc(file)) != EOF) printf("%c",caracter);
        fclose(file);
	
	FILE *file2 = fopen("restMatr.txt","r");

        if (file2 == NULL) printf("\nError de apertura del archivo. \n\n");
        else while((caracter = fgetc(file2)) != EOF) printf("%c",caracter);
        fclose(file2);

	FILE *file3 = fopen("multMatr.txt","r");

       	if (file3 == NULL) printf("\nError de apertura del archivo. \n\n");
        else while((caracter = fgetc(file3)) != EOF) printf("%c",caracter);
        fclose(file3);

	FILE *file4 = fopen("transMatr.txt","r");

       	if (file4 == NULL) printf("\nError de apertura del archivo. \n\n");
        else while((caracter = fgetc(file4)) != EOF) printf("%c",caracter);
        fclose(file4);
	
	FILE *file5 = fopen("InvMatr.txt","r");

        if (file5 == NULL) printf("\nError de apertura del archivo. \n\n");
        else while((caracter = fgetc(file5)) != EOF) printf("%c",caracter);
        fclose(file5);
	
}

int main(){
	clock_t tiempo_inicio, tiempo_final;
	double segundos;

	tiempo_inicio = clock();

	pthread_create(&t1, NULL, suma, NULL);
	pthread_join(t1, NULL);

	pthread_create(&t2, NULL, resta, NULL);
	pthread_join(t2, NULL);

	pthread_create(&t3, NULL, mult, NULL);
	pthread_join(t3, NULL);

	pthread_create(&t4, NULL, trans, NULL);
	pthread_join(t4, NULL);

	pthread_create(&t5, NULL, inversa, NULL);
	pthread_join(t5, NULL);

 
	pthread_create(&t6, NULL, leer, NULL);
	pthread_join(t6, NULL);

	printf("\nTiempo de ejecucion: ");
	tiempo_final = clock();

	segundos = (double)(-tiempo_inicio+tiempo_final) / CLOCKS_PER_SEC; /*según que estes midiendo el tiempo en segundos es demasiado grande*/

	printf("%f s \n",segundos); 
	return 0;

}



