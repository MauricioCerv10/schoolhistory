#include "PoligonoIrreg.h"
#include "Coordenada.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//PoligonoIrreg::PoligonoIrreg(Coordenada c1, Coordenada c2, Coordenada c3){
//	vertices.push_back(c1);
//	vertices.push_back(c2);
//	vertices.push_back(c3);
//}

int PoligonoIrreg::numVertices = 0;
bool func(Coordenada x, Coordenada y){
	if(x.obtenerX() < y.obtenerX()) return true;
	else if(x.obtenerX() == y.obtenerX() && x.obtenerY() < y.obtenerY()) return true;
	else return false;
}
PoligonoIrreg::PoligonoIrreg(){
}

void PoligonoIrreg::imprimeVertices(){
	for(int i = 0; i < vertices.size(); i++){
		cout << "Vértice " << i << ": " << endl;
		cout << "  X: " << vertices[i].obtenerX() << endl;
		cout << "  Y: " << vertices[i].obtenerY() << endl;
		cout << "=============" << endl;
	}
	return;
}

void PoligonoIrreg::anadeVertice(double x, double y){
	vertices.push_back(Coordenada(x, y));
	return;
}
void PoligonoIrreg::sumaVertices(int num){
	numVertices += num;
}
void PoligonoIrreg::iniVertices(){
	numVertices = 0;
}
int PoligonoIrreg::getVertices(){
	return numVertices;
}
vector<Coordenada> PoligonoIrreg::ordena(){
	sort(vertices.begin(),vertices.end(),func);
	return vertices;
}
