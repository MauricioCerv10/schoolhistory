#include "Rectangulo.h"
#ifndef ORTAEDRO_H_
#define ORTAEDRO_H_
class Ortaedro
{
private:
        Rectangulo tSup;
        Rectangulo tInf;
        Rectangulo l1;
        Rectangulo l2;
        Rectangulo l3;
        Rectangulo l4;
public:
        Ortaedro();
        Ortaedro(double xtSupS, double ytSupS, double ztSupS, double xtSupI, double ytSupI, double ztSupI,
		double xtInfS, double ytInfS, double ztInfS, double xtInfI, double ytInfI, double ztInfI, 	
		double xl1S, double yl1S, double zl1S, double xl1I, double yl1I, double zl1I,
		double xl2S, double yl2S, double zl2S,double xl2I, double yl2I, double zl2I,
		double xl3S, double yl3S, double zl3S,double xl3I, double yl3I, double zl3I,
		double xl4S, double yl4S, double zl4S,double xl4I, double yl4I, double zl4I
	);
        void imprimeVertices();//imprime esquinas de las dos tapas
	double areaO();
	double volumen();
        //Coordenada obtieneSupIzq();
        //Coordenada obtieneInfDer();
};
#endif

