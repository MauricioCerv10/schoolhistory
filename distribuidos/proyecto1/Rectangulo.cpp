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
	cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY() <<" z = " <<  superiorIzq.obtenerZ() << endl;
	cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY() <<" z = " << inferiorDer.obtenerZ()<< endl; 
	cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY() <<" z = " << superiorIzq.obtenerZ()<< endl; 
	cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY() <<" z = " << inferiorDer.obtenerZ()<< endl; 
}

double Rectangulo::area(){
	double al = alto();
        double an = ancho();
	return an * al;
}

double Rectangulo::ancho(){
	double res = 0;
	if(obtieneInfDer().obtenerY() == obtieneSupIzq().obtenerY()) 
		res = abs(obtieneInfDer().obtenerX() - obtieneSupIzq().obtenerX());
	else 
		res = abs(obtieneInfDer().obtenerY() - obtieneSupIzq().obtenerY());
	
	return res;
}
double Rectangulo::alto(){
	double res = 0;
        if(obtieneInfDer().obtenerY() == obtieneSupIzq().obtenerY()) 
                res = abs(obtieneInfDer().obtenerZ() - obtieneSupIzq().obtenerZ());
        else if(obtieneInfDer().obtenerZ() == obtieneSupIzq().obtenerZ())
                res = abs(obtieneInfDer().obtenerX() - obtieneSupIzq().obtenerX());
	else 
		res = abs(obtieneInfDer().obtenerZ() - obtieneSupIzq().obtenerZ());
        
        return res;

}

Coordenada Rectangulo::obtieneSupIzq()
{
	return superiorIzq;
}

Coordenada Rectangulo::obtieneInfDer()
{
	return inferiorDer;
}
