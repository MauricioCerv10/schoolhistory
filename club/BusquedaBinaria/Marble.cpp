#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,Q;
	int cas = 1;
	while(cin>>N>>Q,(N||Q)){
		cout<<"CASE# "<<cas++<<":"<<endl;
		int marbs[N];
		for(int i = 0;i<N;i++) cin>>marbs[i];
		sort(marbs,marbs+N);
		while(Q--){
			int q;
			cin>>q;
			int ini = 0,fin = N-1, mid = 0, res = -1;
			while(ini <= fin){
				mid = (ini+fin)/2;
				if(marbs[mid] < q) ini = mid+1;
				else{ fin = mid-1; res = mid;}
			}
			if(marbs[res] == q) cout<<q<<" found at "<<res+1<<endl;
			else cout<<q<<" not found"<<endl;
		}
	}
}


