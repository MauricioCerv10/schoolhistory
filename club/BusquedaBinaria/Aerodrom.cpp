#include <bits/stdc++.h>
using namespace std;

long long int desk[100010];
long long int timeOk(long long int time, int n){
	long long int res = 0;
	for(int i = 0;i<n;i++){
		res += time/desk[i];
	}
	return res;
}

int main(){
	long long int M;
	int N;
	cin>>N>>M;
	for(int i = 0;i<N;i++) cin>>desk[i];

	long long int ini = 0,fin = 100000000000000, mid = 0,res = -1;
	while(ini <= fin){
		mid = (ini+fin)/2;
		if(timeOk(mid,N) < M) ini = mid+1;
		else{ fin = mid-1; res = mid;}
	}

	cout<<res<<endl;
}
