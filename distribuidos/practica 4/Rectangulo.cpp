#include "Rectangulo.h"
#include <iostream>
using namespace std;

Rectangulo::Rectangulo() : superiorIzq(0,0,0), inferiorDer(0,0,0)
{ }

Rectangulo::Rectangulo(double xSupIzq, double ySupIzq, double zSupIzq, double xInfDer, double yInfDer, double zInfIzq)
:superiorIzq(xSupIzq, ySupIzq, zSupIzq), inferiorDer(xInfDer, yInfDer,zInfIzq)
{ }

void Rectangulo::imprimeEsq()
{
	cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY()<< superiorIzq.obtenerZ() << endl;
	cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY() << inferiorDer.obtenerZ()<< endl; 
	cout << "x = " << inferiorDer.obtenerX() << " y = " << superiorIzq.obtenerY() << inferiorDer.obtenerZ()<< endl; 
	cout << "x = " << superiorIzq.obtenerX() << " y = " << inferiorDer.obtenerY() << inferiorDer.obtenerZ()<< endl; 
}

double Rectangulo::area(){
	double al = alto();
        double an = ancho();
	return an * al;
}

double Rectangulo::ancho(){
	return obtieneInfDer().obtenerX() -obtieneSupIzq().obtenerX();
}
double Rectangulo::alto(){
	return obtieneSupIzq().obtenerY() - obtieneInfDer().obtenerY();
}

Coordenada Rectangulo::obtieneSupIzq()
{
	return superiorIzq;
}

Coordenada Rectangulo::obtieneInfDer()
{
	return inferiorDer;
}
