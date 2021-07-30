#include <bits/stdc++.h>
using namespace std;

int n, s;
int dp[120][10000];
int wi[105];
int vi[105];

int memo(int id, int rW){
	if(id == n || rW == 0) return 0;
	if(rW - wi[id] < 0) return memo(id+1,rW);
	if( dp[id][rW] != -1){return dp[id][rW];}
	else{
		dp[id][rW] = max( vi[id] + memo(id+1,rW-wi[id] ), max( vi[id] + memo(id,rW-wi[id]),memo(id+1,rW) ) );
	}
	return dp[id][rW];
}

int main(){
	cin.tie(0);
        ios_base::sync_with_stdio(0);
	cin>>n>>s;
	for(int i = 0; i<n;i++) cin>>vi[i]>>wi[i];
	for(int i = 0; i<=n+10;i++) for(int j = 0; j<=s+10; j++) dp[i][j] = -1;
	int ans = memo(0,s);
	cout<<ans<<"\n";
}
