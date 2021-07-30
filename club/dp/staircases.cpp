#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[505][505];


int main(){
	ll n;
	cin>>n;
	for(ll i = 1;i<=(n/2);i++){
		dp[n-i][i] = 1;
	}
	
	for(int i = 1; i<n; i++){
		for(int j = 1; j<n;j++){
			if(dp[j][i] >= 1){
				for(int c = i+1;c<=j;c++){
					if((j-c) > c || (j-c) == 0){
						dp[j-c][c] += dp[j][i];
					}
				}
			}
		}
	}

	ll ans = 0;
	for(int i = 0; i<n ;i++) ans += dp[0][i];
	cout<<ans<<endl;
}
