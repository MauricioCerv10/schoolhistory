#include <bits/stdc++.h>
using namespace std;
pair<int,int> v[10000];
int main(){
	int N,X;
	cin>>N>>X;
	for(int i = 0; i<N; i++){
		int vi,pi;
		cin>>vi>>pi;
		pair<int,int> in = make_pair(vi,pi);
		v[i] = in;
	}
	int res = 0;
	for(int i = 0; i<N; i++){
		int percent = v[i].first * v[i].second;
		res += percent;
		if(res > X*100){ cout<<i+1<<endl; break; }
		if(i == N-1) cout<<-1<<endl; 
	}
}
