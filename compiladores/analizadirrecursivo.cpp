#include <bits/stdc++.h>
using namespace std;
string palabra;
int idx;

void F(){
	if(palabra.at(idx) == 'x') idx++;
}

void E(){
	if(palabra.at(idx) == 'y') idx++;
}

void D(){
	E();
	F();
}

void Bp(){
	if(palabra.at(idx) == 'v'){idx++; Bp();}
}

void B(){
	if(palabra.at(idx) == 'w'){ idx++; Bp();}
	else cout<<"Error\n";
}

void S(){
	if(palabra.at(idx) == 'u'){ idx++; B(); D();}
	else cout<<"Error"<<endl;
}

int main(){
	cin>>palabra;
	palabra = palabra + '$';
	
	if(palabra.at(idx) == 'u'){
		S();
		if(palabra.at(idx) == 'z' && palabra.at(idx+1) == '$') cout<<"Aceptada"<<endl;
		else cout<<"Error"<<endl;
	}else{
		cout<<"Sentencia no aceptada\n";
	}
}
