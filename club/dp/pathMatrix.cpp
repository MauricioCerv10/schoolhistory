#include <bits/stdc++.h>
using namespace std;

int path[25][25];
int dp[25][25];
int n;
int maxPath(int i, int j){
	//cout<<i<<" "<<j<<endl;
	if(j < 0 || j >= n) return -200000;
	if(i == n-1) return path[i][j];
	//cout<<dp[0][1]<<endl;
	if(dp[i][j] != -1){return dp[i][j];}
	dp[i][j] = max( maxPath(i+1,j), max( maxPath(i+1,j-1), maxPath(i+1,j+1)) ) + path[i][j];
	
	return dp[i][j];
}
int main(){
	int t; cin>>t;
	while(t--){
		cin>>n;
		for(int i = 0; i<n; i++) for(int j = 0; j<n; j++){ cin>>path[i][j]; dp[i][j] = -1;}
		int res = 0;
		for(int j = 0; j<n; j++) res = max(res,maxPath(0,j));
		cout<<res<<endl;
	}
}
