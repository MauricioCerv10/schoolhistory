
#include "Coordenada.h" 
#include <vector>
using namespace std;
#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_


class PoligonoIrreg{
	private: 
			vector<Coordenada> vertices; 
	public: 
			PoligonoIrreg();
			void anadeVertice(float x, float y);
			void imprimeVertices();
			vector<Coordenada> ordena(); 
};

#endif 
