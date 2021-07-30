#include <bits/stdc++.h>
using namespace std;
int caso;
int main(){
	int c;
	cin>>c;
	while(c--){
		if(caso++) cout<<"\n";
		queue<pair<int,int>> left;
		queue<pair<int,int>> right;
		int n,t,m;
		cin>>n>>t>>m;
		int times[m];

		for(int i = 0; i<m;i++){

			string bank;
			int time;
			cin>>time>>bank;
			if(bank.compare("left") == 0) left.push(pair<int,int>(i,time));
			else right.push(pair<int,int>(i,time));

		}

		int mins = 0;
		int conN = 0;
		queue<pair<int,int>> ferry;
		int side = 0;
		while(!right.empty() || !left.empty()){
			//esperar hasta que llegue uno
			
			int first = 900000;
			if(!left.empty()) first = left.front().second;
			if(!right.empty()) first = min(first,right.front().second);

			mins = max(mins,first);
			//cargar Ferry
			while(!left.empty()){
				int car = left.front().second;
				pair<int,int> front = left.front();
				if( car <= mins && ferry.size() < n) ferry.push(front);
				else break;
				left.pop();
			}
			//descargar en derecha Ferry
			mins += t;
			while(!ferry.empty()){
				times[ferry.front().first] = mins;
				ferry.pop();
			}
			//esperar hasta que llegue uno
			
			if(!left.empty()) first = left.front().second;
                        if(!right.empty()) first = min(first,right.front().second);

			mins = max(mins,first);
			
			//carga Ferry
			while(!right.empty()){
				int car = right.front().second;
				pair<int,int> front = right.front();
                                if( car <= mins && ferry.size() < n) ferry.push(front);
                                else break;
                                right.pop();
			}
			//descarga Ferry
			mins += t;
			while(!ferry.empty()){
                                times[ferry.front().first] = mins;
                                ferry.pop();
                        }
		}
		for (int i = 0; i < m; ++i)
            		cout << times[i] << endl;
	}
}
