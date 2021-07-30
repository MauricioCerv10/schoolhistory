#include <bits/stdc++.h>
using namespace std;
#define MAXIN 10000;
int con,con2;
string line1, line2;
int indiceIn, indiceOut;
char top;
string cadena;
vector<char> pila;
bool stopi;
bool busca(char accion, string secuencia,char top){
	//cout<<"Top actual: "<<top<<endl;
	if(stopi == true && accion == 'i'){
		return false;
	}
	if(con == (line1.length()*2)-1 && secuencia.compare(line2)){
		con--;
		//cout<<"regresa ccon >>>>"<<endl;
		return false;
	}else if(con == line1.length()-1 && accion == 'i'){
                pila.push_back(line1.at(indiceIn));
                //cout<<" push "<<line1.at(indiceIn)<<" ";
                //cout<<con<<endl;
                secuencia += accion;
		stopi = true;
		busca('o',secuencia,top);
		stopi = false;
		pila.pop_back();
		//cout<<"regresa i"<<endl;
		return false;
	}else if(con2 == line1.length()-1 && accion == 'o'){
		//cout<<"regresa o"<<endl;
		top = pila.back();
                //cout<<"top "<<top<<endl;
                if(top != line2.at(indiceOut)){
                        //cout<<"regresa o por dif"<<endl;
                        return false;
                }
                cadena += top; 
                cout<<"cadena agregado"<<cadena<<endl;
                secuencia += accion;
		if(cadena.compare(line2) == 0){
			cout<<secuencia<<"\n";
			cadena.erase(cadena.length()-1);
			secuencia.erase(secuencia.length()-1);
			cout<<"exito"<<endl;
		}
                //con2--;
		return false;
	}
	//cout<<" "<<accion<<" "<<top<<" "<<con<<" "<<con2<<" "<<indiceOut<<" "<<indiceIn<<endl;
	if(accion == 'i' &&  con<line1.length()){
		//cout<<"entro i"<<endl;
		pila.push_back(line1.at(indiceIn));
		//cout<<" push "<<line1.at(indiceIn)<<" ";
		//cout<<con<<endl;
		indiceIn++;
		con++;
		secuencia += accion;
	}else if(accion == 'o' && pila.empty() == false && con<line2.length()){
		top = pila.back();
		//cout<<"entro o"<<endl;
		//cout<<"top "<<top<<endl;
		if(top != line2.at(indiceOut)){
			//cout<<"regresa o por dif"<<endl;
			return false;
		}
		cadena += top; 
		//cout<<"cadena agregado"<<cadena<<endl;
		indiceOut++;
		secuencia += accion;
		con2++;
		pila.pop_back();
	}
	cout<<"pasa sin condicion y pasa i"<<endl;
	busca('i',secuencia,top);
	cout<<"pasa o"<<endl;
	busca('o',secuencia,top);
	if(accion == 'i'){
		indiceIn--;
		cout<<"pop"<<pila.back()<<" ";
		pila.pop_back();
		con--;
		cout<<"regresa i por fin"<<endl;
	}else if(accion == 'o'){
		pila.push_back(top);
		cout<<"push"<<top<<" ";
		indiceOut--;
		con2--;
		cadena.erase(cadena.length()-1);
		cout<<"regresa o por fin"<<endl;
	}
	secuencia.erase(secuencia.length()-1);
	
}
int main(){
	//validar pila vacia
	while(getline(cin,line1)){
		getline(cin,line2);
		string secuencia = "";
		cadena = "";
		indiceIn = indiceOut = 0;
		con = con2 = 0;
		stopi = false;
		pila.clear();
		cout<<"[\n";
		busca('i',secuencia,top);
		cout<<"]\n";
	}
}

