#include "Fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha(int dd, int mm, int aaaa){
	mes = mm;
	dia = dd;
	anio = aaaa;
}

void Fecha::inicializaFecha(int dd,int mm, int aaaa){
	anio = aaaa;
	mes = mm;
	dia = dd;
	return;
}

void Fecha::muestraFecha(){
	cout<<"La fecha es(dia-mes-año): "<<dia<<"-"<<mes<<"-"<<anio<<"\n";
	return;
}
int Fecha::convierte(){
	return anio*10000+mes*100+dia;
}
int Fecha::masVieja(Fecha *fecha1,Fecha *fecha2){
	if(fecha1->anio > fecha2->anio) return 1;
	else if(fecha1->anio > fecha2->anio) return -1;
	else if(fecha1->mes > fecha2->mes) return 1;
	else if(fecha1->mes < fecha2->mes) return -1;
	else if(fecha1->dia > fecha2->dia) return 1;
	else if(fecha1->dia < fecha2->dia) return -1;
	else return 0;
}
