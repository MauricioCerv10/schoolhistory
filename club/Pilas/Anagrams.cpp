#include <bits/stdc++.h>
using namespace std;
string line1, line2;
int indiceIn, indiceOut;
string cadena;
vector<char> pila;

void busca(string secuencia, string cadena){
	if(cadena.compare(line2) == 0){
		for(int i = 0; i<secuencia.length();i++){
			if(i == (secuencia.length()-1)){
				cout<<secuencia[i]<<"\n";
			}else{
				cout<<secuencia[i]<<" ";
			}
		}
		return;
	}
	if( indiceIn+1 <= line1.length() ){

		pila.push_back(line1.at(indiceIn));
		indiceIn++;
		busca(secuencia+'i',cadena);
		indiceIn--;
		pila.pop_back();
	}
	if( indiceOut+1 <= indiceIn  && indiceOut+1 <= line2.length()){
		char top = pila.back();
		if(top != line2.at(indiceOut)){
			return;
		}
		pila.pop_back();
		indiceOut++;
		busca(secuencia+'o',cadena+top);
		indiceOut--;
		pila.push_back(top);
	}
}
int main(){
	//validar pila vacia
	while(getline(cin,line1)){
		getline(cin,line2);
		string secuencia = "";
		cadena = "";
		indiceIn = indiceOut = 0;
		pila.clear();
		cout<<"[\n";
		busca(secuencia,cadena);
		cout<<"]\n";
	}
}
