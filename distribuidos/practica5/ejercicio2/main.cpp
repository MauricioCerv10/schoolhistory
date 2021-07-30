#include <bits/stdc++.h>
#include <vector>
#include "Coordenada.h"
#include "PoligonoIrreg.h"

int main(){
	PoligonoIrreg p;
	int vertices = rand()%1000;
	p.sumaVertices(vertices);
	for(int j = 0; j<vertices; j++){
		int x = rand()%100;
		int y = rand()%100;
		p.anadeVertice(x,y);
	}
	vector<Coordenada> vec = p.ordena();
	for(int i = 0; i<vec.size(); i++){
		cout<<vec[i].obtenerX()<<" "<<vec[i].obtenerY()<<endl;
	}
	return 0;
}
