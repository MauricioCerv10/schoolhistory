#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[2][100005];
ll h[2][100005];
int n;
ll maxHei(ll i, ll j){
	if(j >= n) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	dp[i][j] = max( maxHei(i,j+1) , h[i][j] + maxHei( (i+1)%2, j+1));
	return dp[i][j];
}

int main(){
	 cin>>n;
	for(int i = 0; i<2; i++){
		for(int j = 0; j<n; j++){
			cin>>h[i][j]; dp[i][j] = -1;
		}
	}
	ll res = max(maxHei(0,0),maxHei(1,0));
	cout<<res<<endl;
}
