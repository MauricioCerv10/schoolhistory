#include <bits/stdc++.h>
using namespace std;

int n;

long long solve(long long fi, long long se){
	return  fi + ((se*(se+1))/2);
}

long long isFun(long long fi){
	long long ini = 1,fin = n,res = -1, mid = 0;
	while(ini<=fin){
		mid = (ini+fin)/2;
		if(solve(fi,mid) < n) ini = mid+1;
		else {fin = mid-1; res = mid;}
	}
	return solve(fi,res);
}

int main(){
	cin>>n;
	long long fi = 0;
	bool isn = true;
	for(long long i = 1; fi<=n;i++){
		fi = (i*(i+1))/2;
		if(isFun(fi) == n){cout<<"YES\n"; isn = false; break;}
	}
	if(isn) cout<<"NO\n";
}
