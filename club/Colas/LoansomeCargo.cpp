#include <bits/stdc++.h>
using namespace std;

#define MAX 110

int main(){
	int set;
	while(cin>>set){
		while(set--){

			stack<int> cargo;
			queue<int> pB[MAX];
			int min = 0;
			int n,s,q;
			cin>>n>>s>>q;
			bool hecho[MAX];

			for(int i = 1;i<=n;i++) hecho[i] = false;
			

			for(int i = 1; i<=n;i++){
				int qi;
				cin>>qi;
				while(qi--){
					int dest;
					cin>>dest;
					pB[i].push(dest);
					
				}
				
			}
			bool notFin = true;
			int station = 1;
			while(notFin){
				//descargar  del cargo
				while(!cargo.empty()){
					int cargoe = cargo.top();
					if(cargoe != station && pB[station].size() < q){
						pB[station].push(cargoe);
						cargo.pop();
						min++;
					}else if(cargoe == station){
						cargo.pop();
						min++;
						
					}else{
						break;
					}
				}
				//cargar del cargo
				while( cargo.size() < s && pB[station].empty() != true){
					int cargoe = pB[station].front();
					cargo.push(cargoe);
					pB[station].pop();
					min++;
				}
				
				if(pB[station].empty()) hecho[station] = true;
				else hecho[station] = false;

				notFin = false;
				for(int i = 1;i<=n;i++) if(hecho[i] == false) notFin = true;
				if(!cargo.empty()) notFin = true;
				if(station == n) station = 0;
				station++;
				min += 2;
			}
			min -= 2;
			cout<<min<<"\n";
		}
	}
}
