#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		bool q = true,s = true,pq = true;
		stack<int> pila;
		queue<int> cola;
		priority_queue<int,vector<int>,less<int>> coladp;
		while(n--){
			
			int c,x;
			cin>>c>>x;
			if(c == 1){
				pila.push(x);
				cola.push(x);
				coladp.push(x);
			}else{
				
				if(!pila.empty() && pila.top() == x && s)  pila.pop();
				else s = false;
				
				if(!cola.empty() && cola.front() == x && q) cola.pop();
				else q = false;
				
				if(!coladp.empty() && coladp.top() == x && pq) coladp.pop();
				else pq = false;
				
			}
		}

		if(s == true && q == false && pq == false) cout<<"stack\n";
		else if(q == true && s == false && pq == false) cout<<"queue\n";
		else if(pq == true && s == false && q == false) cout<<"priority queue\n";
		else if(pq == false && s == false && q == false) cout<<"impossible\n";
		else cout<<"not sure\n";
	}
}
