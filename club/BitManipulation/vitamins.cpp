#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int val[1005];
string vit[1005];
int n;
ll dp[1005][10];
int tonBits(int mask, string vitm){
	for(int i = 0; i<vitm.size();i++){
		if(vitm[i] == 'A'){
			mask = (mask|4);
		}else if(vitm[i] == 'B'){ 
			mask = (mask|2);
                }else{
			mask = (mask|1);
		}

	}
	return mask;
}
ll minVal(int i, int mask){
	if(mask == 7) return 0;
	if(i == n) return 100000000000;
	
	if(dp[i][mask] != -1) return dp[i][mask];
	dp[i][mask] = min( minVal(i+1,mask), val[i] + minVal( i+1, tonBits(mask,vit[i]) ));
	
	return dp[i][mask];
}

int main(){
	cin>>n;
	for(int i = 0; i<n; i++) cin>>val[i]>>vit[i];
	for(int i = 0; i<n+5; i++){
		for(int j = 0; j<10; j++){
			dp[i][j] = -1;
		}
	}
	ll res = minVal(0,0);
	if(res >= 100000000000) cout<<-1<<endl;
	else cout<<res<<endl;
}
