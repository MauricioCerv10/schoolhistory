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
int main(){
	Fecha a,b,c(21,9,1973);
	b.inicializaFecha(17,6,2000);
	a.muestraFecha();
	b.muestraFecha();
	c.muestraFecha();
	cout<<"Metodo convierte: "<<a.convierte()<<endl;
}
