#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[55][255];
int n,s;
int coins[55];

ll memo(int id, int rA){
	if(rA == 0) return 1;
	if(rA < 0) return 0;
	if(id == s) return 0;
	ll res = 0;
	if( dp[id][rA] != 0) return dp[id][rA];
	else dp[id][rA] += memo(id,rA-coins[id])+memo(id+1,rA);
	return dp[id][rA];
}
int main(){
	cin>>n>>s;
	for(int i = 0; i<s ; i++ ) cin>>coins[i];
	ll ans = memo(0,n);
	cout<<ans<<endl;
}


