#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	cin.clear();
	cin.ignore();
	for(int i = 0; i<n;i++){
		int k,m;
		cin>>k;
		cin.clear();
		cin.ignore();
		pair<char,int> caracteres[k];
		int precio = 0;
		for(int i = 0; i<k;i++){
			caracteres[i].first = 0;
			caracteres[i].second = 0;
		}

		for(int i = 0; i<k; i++){
			cin>>caracteres[i].first>>caracteres[i].second;
			cin.clear();
			cin.ignore();
		}

		cin>>m;
		cin.clear();
		cin.ignore();
		for(int i = 0; i<m;i++){
			string line;
			getline(cin,line);
			for(int j = 0; j<line.length();j++){
				for(int c = 0; c<k;c++){
					if(caracteres[c].first == line.at(j)){
						precio +=caracteres[c].second;
					}
				}
			}
		}
		
		int unidades = precio % 10;
		int y = precio - unidades;
		y = y%100;
		int decenas = y/10;
		y = precio - decenas*10 - unidades;
		int centenas = y/100;
		
		cout<<centenas<<"."<<decenas<<unidades<<"$\n";
	}
}
