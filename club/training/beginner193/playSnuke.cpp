#include <bits/stdc++.h>
using namespace std; 

int main(){
	int n; cin>>n;
	int minPrize = 2000000000; 
	for(int i = 0; i<n; i++){
		int a,p,x; cin>>a>>p>>x;
		if(x > a) minPrize = min(minPrize,p);
	}
	if(minPrize != 2000000000) cout<<minPrize<<endl;
	else cout<<"-1\n";
}
