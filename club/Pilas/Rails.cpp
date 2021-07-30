#include <bits/stdc++.h>
using namespace std;
int caso;
int main(){
	int N;
	while(cin>>N,N){
		int n;
		int con = 1;
		int iter = 0;
		vector<int> pila;
		bool esquivar = false;
		while(true){
		
			cin>>n;
			if(esquivar == true && iter != N){
				iter++;
				continue;
			}
			if(iter == N){
				iter = 0;
				con = 1;
				esquivar = false;
				
				if(pila.empty() == true){
					cout<<"Yes\n";
				}
				else{
					cout<<"No\n";
				}
				pila.clear();
			}
			
			if(n == 0){
				break;
			}
			
			if( pila.empty() == false && pila.back() == n){
				pila.pop_back();
				iter++;
				continue;
			}

			if(pila.empty() == false && con == N+1 && pila.back() != n){
				esquivar = true;
				iter++;
				continue;
			}
			for(int i = con;i<=N;i++){
				if(i != n){
					pila.push_back(i);
					con++;
					continue;
				}
				con++;
				break;
			}
			iter++;
		}
		cout<<"\n";
	}
}
