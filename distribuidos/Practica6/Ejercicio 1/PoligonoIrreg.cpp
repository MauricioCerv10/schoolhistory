#include "PoligonoIrreg.h"
#include "Coordenada.h"
#include <bits/stdc++.h>
using namespace std;

//PoligonoIrreg::PoligonoIrreg(Coordenada c1, Coordenada c2, Coordenada c3){
//	vertices.push_back(c1);
//	vertices.push_back(c2);
//	vertices.push_back(c3);
//}
bool func(Coordenada x, Coordenada y){
	float mag1= sqrt(
                                (vertices[i].obtenerX()*vertices[i].obtenerX()) +
                                (vertices[i].obtenerY()*vertices[i].obtenerY())
                             );
;
	float mag2= sqrt(
                                (vertices[i].obtenerX()*vertices[i].obtenerX()) +
                                (vertices[i].obtenerY()*vertices[i].obtenerY())
                             );
;
	return mag1 < mag2;
}
PoligonoIrreg::PoligonoIrreg(){
}

void PoligonoIrreg::imprimeVertices(){
	float pitagorazo;
	for(int i = 0; i < vertices.size(); i++){
		cout << "=============" << endl;
		cout << "Vértice " << i+1 << ": " << endl;
		cout << "  X: " << vertices[i].obtenerX() << endl;
		cout << "  Y: " << vertices[i].obtenerY() << endl;
		cout << "==" << endl;
		pitagorazo = sqrt(
				(vertices[i].obtenerX()*vertices[i].obtenerX()) +
				(vertices[i].obtenerY()*vertices[i].obtenerY())
			     );
		cout << "Magnitud: " << pitagorazo << endl;
		cout << "=============" << endl << endl;
	}
	return;
}

void PoligonoIrreg::anadeVertice(float x, float y){
	vertices.push_back(Coordenada(x, y));
	return;
}
vector<Coordenada> PoligonoIrreg::ordena(){
	sort(vertices.begin(),vertices.end(),func);
	return vertices;
}
