#include <bits/stdc++.h>
using namespace std;

#define MAX 100010

long long stall[MAX];
long long N,C;

long long disOk(long long dis){
	long long tdis=0,cows=1;
	for(int i = 0;i<N-1;i++){
		tdis += stall[i+1]-stall[i];
		if(tdis >= dis){ cows++; tdis=0;}
		//else if(dis<tdis){cows++; tdis=0;}
	}
	return cows;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>N>>C;
		for(int i = 0;i<N;i++) cin>>stall[i];
		sort(stall,stall+N);
		long long ini=0,fin=1000000000,res = -1,mid = fin;
		while(ini<fin){
			if(disOk(mid) >= C ){ ini=mid+1; res=mid;}
			else {fin=mid;}
			mid = (ini+fin)/2;

		}
		cout<<res<<endl;
	}
}
