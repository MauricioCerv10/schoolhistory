#include <bits/stdc++.h>
using namespace std;
int caso;
int main(){
	int c;
	cin>>c;
	while(c--){
		queue<int> left;
		queue<int> right;
		int l,m;
		cin>>l>>m;
		int current[m];

		for(int i = 0; i<m;i++){

			string bank;
			int length;
			cin>>length>>bank;
			if(bank.compare("left") == 0) left.push(length);
			else right.push(length);

		}

		int times = 0;
		queue<int> ferry;
		l = l*100;
		while(!right.empty() || !left.empty()){
		
			//cargar Ferry
			int size = 0;
			while(!left.empty() && size+left.front() <= l){
				size += left.front(); 
				//ferry.push(left.front());
				left.pop();
			}
			times++;
			if(left.empty() && right.empty()) break;
			
			//descarga Ferry
			size = 0;
			//carga ferry
			while(!right.empty() && size+right.front() <= l){
				size += right.front();
                                right.pop();
			}
			//descarga Ferry
			times++;
			
		}
		cout<<times<<"\n";
	}
}

