#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main(){
	optimizar_io;
	int q;
	cin>>q;
	stack<int> cola, pila;
	for(int i = 0; i<q;i++){
		int type;
		cin>>type;
		if(type == 1){
			int num;
			cin>>num;
			pila.push(num);
		}
		if(cola.empty()){
			while(!pila.empty()){
				cola.push(pila.top());
				pila.pop();
			}	
		}
		if(type == 2){
			cola.pop();
		}
		if(type == 3){
			int front = cola.top();
			cout<<front<<"\n";
		}
	}
}
