#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000

long long cat[1005];

int catnums(int n){
	cat[0] = cat[1] = 1;
	for(int i = 2; i<=n ; i++){
		cat[i] = 0;
		for(int j = 0; j<i; j++)
			cat[i] = (cat[i] + (cat[j] * cat[i-j-1])%MOD)%MOD;
	}
	return cat[n];
}

int main(){
	int n;
	cin>>n;
	int res = catnums(n);
	cout<<res<<endl;
}
