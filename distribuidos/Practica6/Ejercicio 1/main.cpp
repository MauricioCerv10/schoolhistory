#include <bits/stdc++.h>
#include "Coordenada.h"
#include "PoligonoIrreg.h"

int main(){
	int n = 10, i;
	PoligonoIrreg p;
	float r1, r2, r3, r4;
	for(i = 0; i < n; i++){
		r1 = -100 + (rand() % (100 + 100 + 1));
		r2 = 1 + (rand() % (1000 - 1 + 1));
		r3 = -100 + (rand() % (100 + 100 + 1));
		r4 = 1 + (rand() % (1000 - 1 + 1));
		p.anadeVertice(r1 + (r2/1000) , r3 + (r4/1000) );
	}
	p.imprimeVertices();
	vector<Coordenada> vec = p.ordena();
	for(int i = 0; i<vec.size();i++){
		float mag1=sqrt(
                                (vec[i].obtenerX()*vec[i].obtenerX()) +
                                (vec[i].obtenerY()*vec[i].obtenerY())
                             );
 ;
		cout<<mag1<<endl; 
	}
	return 0;
}
