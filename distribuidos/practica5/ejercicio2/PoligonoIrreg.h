#include "Coordenada.h" 
#include <vector>
using namespace std;
#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_


class PoligonoIrreg{
	static int numVertices;

	private: 
			vector<Coordenada> vertices; 
	public: 
			PoligonoIrreg();
			void anadeVertice(double x, double y);
			void imprimeVertices();
			void sumaVertices(int suma);
			void iniVertices();
			int getVertices();
			vector<Coordenada> ordena();
 
};

#endif 
