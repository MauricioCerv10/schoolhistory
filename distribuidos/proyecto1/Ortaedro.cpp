//#include "Rectangulo.h"
#include "Ortaedro.h"
#include <iostream>
using namespace std;

Ortaedro::Ortaedro() : tSup(0,0,0,0,0,0), tInf(0,0,0,0,0,0), l1(0,0,0,0,0,0), l2(0,0,0,0,0,0), l3(0,0,0,0,0,0), l4(0,0,0,0,0,0)
{ }

Ortaedro::Ortaedro(double xtSupS, double ytSupS, double ztSupS, double xtSupI, double ytSupI, double ztSupI,
		double xtInfS, double ytInfS, double ztInfS, double xtInfI, double ytInfI, double ztInfI, 	
		double xl1S, double yl1S, double zl1S, double xl1I, double yl1I, double zl1I,
		double xl2S, double yl2S, double zl2S,double xl2I, double yl2I, double zl2I,
		double xl3S, double yl3S, double zl3S,double xl3I, double yl3I, double zl3I,
		double xl4S, double yl4S, double zl4S,double xl4I, double yl4I, double zl4I)
:tSup(xtSupS,ytSupS,ztSupS,xtSupI,ytSupI,ztSupI), 
	tInf(xtInfS,ytInfS,ztInfS,xtInfI,ytInfI,ztInfI), 
	l1(xl1S,yl1S,zl1S,xl1I,yl1I,zl1I),
	l2(xl2S,yl2S,zl2S,xl2I,yl2I,zl2I),
	l3(xl3S,yl3S,zl3S,xl3I,yl3I,zl3I),
	l4(xl4S,yl4S,zl4S,xl4I,yl4I,zl4I)
{ }

void Ortaedro::imprimeVertices()
{
	tSup.imprimeEsq();
        tInf.imprimeEsq(); 
}

double Ortaedro::areaO(){
	double res = 0;
	res += tSup.area();
        res += tInf.area();
        res += l1.area();
        res += l2.area();
        res += l3.area();
        res += l4.area(); 
	return res;
}

double Ortaedro::volumen(){
	double res = 0;
	res = tSup.ancho() * tSup.alto() * l1.ancho();
	return res;
}


