#include "Fecha.h"
#include <iostream>
using namespace std;

int main(){
        Fecha a,b,c(21,9,1973);
        b.inicializaFecha(17,6,2000);
        a.muestraFecha();
        b.muestraFecha();
        c.muestraFecha();
        cout<<"Metodo convierte: "<<a.convierte()<<endl;
	cout<<"Mas vieja de a y b :"<<a.masVieja(&a,&b)<<endl;
	int dia1,dia2,mes1,mes2,anio1,anio2;
	for(int i = 0; i<1000; i++){
		dia1 = rand()%31;
		dia2 = rand()%31;
		mes1 = rand()%12;
		mes2 = rand()%12;
		anio1 = rand()%2019;
		anio2 = rand()%2019;
		Fecha a(dia1,mes1,anio1);
		Fecha b(dia2,mes2,anio2);
		a.muestraFecha();
		b.muestraFecha();
		int res = a.masVieja(&a,&b);
		if(res == 1) cout<<"Más vieja es a\n";
		else if(res == 0) cout<<"Son iguales\n";
		else cout<<"Mas vieja b\n";
	} 
}

