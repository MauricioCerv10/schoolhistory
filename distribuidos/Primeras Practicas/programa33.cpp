#include "Fecha.h"
#include <iostream>
using namespace std;

int main(){
	int dia1,dia2,mes1,mes2,anio1,anio2;
	for(int i = 0; i<1000000; i++){
		dia1 = rand()%31;
		dia2 = rand()%31;
		mes1 = rand()%12;
		mes2 = rand()%12;
		anio1 = rand()%2019;
		anio2 = rand()%2019;
		Fecha a(dia1,mes1,anio1);
		Fecha b(dia2,mes2,anio2);
		int res = a.masVieja(&a,&b);
	} 
}

