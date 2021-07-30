#include <bits/stdc++.h>
using namespace std;

int L,N;
string cadena;
int main(){
	int caso = 0;
	cin >> L;
	while(L--){
		int cantidad = 0;
		cin >> N;
		cin >> cadena;
		for(int i = 0; i < cadena.size(); i++){
			if(cadena[i] == '.'){
				cantidad++;
				i += 2;
			}
		}
		cout << "Case " << ++caso << ": " << cantidad << endl;
	}
}
