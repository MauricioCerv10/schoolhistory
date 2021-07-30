#include <bits/stdc++.h>
using namespace std;

stack<char> pila;

string pro1 = "Da";
string pro2a = "Ea";
string pro2b = "b";
string pro3a = "ca";
string pro3b = "b";
string pro3c = "c";

void produccion1(){
 	for(int i = 0; i<pro1.length();i++) pila.push(pro1.at(i));
}
void produccion2(char c){
	if(c == 'a') for(int i = 0; i<pro2a.length();i++) pila.push(pro2a.at(i));
	else if(c == 'b') pila.push('b');
}
void produccion3(char c){
	if(c == 'a') for(int i = 0; i<pro3a.length();i++) pila.push(pro3a.at(i));
	else if(c == 'b') pila.push('b');
	else if(c == 'c')  pila.push('c');
}


int main(){
	string line;
	cin>>line;
	string cad = line + '$';
	pila.push('$');
	pila.push('S');
	int idx = 0;
	while(true){
		char c = cad.at(idx);
		if(c == 'a' && pila.top() == 'c' ) break;

		if(c != 'a' && c != 'b' && c !='c') break;
		if(pila.top() == c){ pila.pop(); idx++;}
		else if(c == 'a' && pila.top() == 'S'){ pila.pop(); produccion1(); }
		else if(c == 'a' && pila.top() == 'D'){ pila.pop(); produccion2('a'); }
		else if(c == 'a' && pila.top() == 'E'){ pila.pop(); produccion3('a');}
		else if(c == 'b' && pila.top() == 'D'){ pila.pop(); produccion2('b'); }
		else if(c == 'b' && pila.top() == 'E'){ pila.pop(); produccion3('b'); }
		else if(c == 'c' && pila.top() == 'E'){ pila.pop(); produccion3('c'); }	
		else if(c == 'b' && pila.top() == 'S') break;
		else if(c == 'c' && pila.top() == 'S') break;
		else if(c == 'c' && pila.top() == 'D') break;
		else if(c == '$' || pila.top() == '$') break;
	}
	if(pila.top() == '$' && cad.at(idx) == '$'){ cout<<"Aceptada"<<endl;}
	else cout<<"No aceptada"<<endl;
}
