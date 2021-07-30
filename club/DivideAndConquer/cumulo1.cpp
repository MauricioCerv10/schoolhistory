#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;
void Cumulo(struct Punto *p, int num);
int ordena(const void *a,const void *b);
double distancia(double x1, double y1, double x2, double y2);
bool Igual(double a, double b);

struct Punto{
   double x, y;
};

struct Punto punto1,punto2;
double disMin = 10000000000;

int main(){
   int num;
   struct Punto p[56789];
   cin >> num;
   for(int i = 0;i < num;i++) 
      cin >> p[i].x >> p[i].y;
   
   Cumulo(p,num);
   printf("\n %.3f",disMin);
   return(0);
 }

//calcula la distancia entre dos puntos
double distancia(double x1, double y1, double x2, double y2) {
 return sqrt( (pow((x2-x1),2)) + (pow((y2-y1),2)) );
}
//retorna -1 si el punto b es mayor al punto a y 1 en caso contrario 
int ordena(const void *a,const void *b){
   return( ( ( *(struct Punto *)a ).x < ( *(struct Punto *)b) .x ) ? -1 : 1 );
}
//calcula la distancia minima entre un cumulo de estrellas
void Cumulo(struct Punto *p, int num){
   double d;
   int inicio,final,a,b;

   if(num <= 1)
    return;
   
   qsort(p, num,sizeof(struct Punto), ordena);
   Cumulo(p, num / 2);
   Cumulo(p + num / 2, ( num + 1 ) / 2);

   for(inicio = num / 2; inicio > 0 && p[num/2].x - p[inicio].x < disMin; inicio--);
   for(final = num / 2; final < num - 1 && p[final].x - p[num/2].x < disMin; final++);
   
   for(a = inicio ; a <= final; a++)
      for(b = a + 1; b <= final; b++)
         if( ( d = distancia(p[a].x, p[a].y, p[b].x, p[b].y) ) < disMin){
            disMin = d;
            punto1.x = p[0].x;
            punto1.y = p[0].y;
            punto2.x = p[1].x;
            punto2.y = p[1].y;
          }
 }


