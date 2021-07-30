#include <bits/stdc++.h>
using namespace std;

string magic;
int dp[4][5005];
int n;

int maxMagic(int i, int edo){
	if(i >= n) return 0;
	
	if(dp[edo][i] != -1) return dp[edo][i];
	
	int newedo = edo;
	dp[edo][i] = max(dp[edo][i],maxMagic(i+1,edo));
	if(edo == 0){
		if(magic[i] == 'a') newedo = 1;
		else newedo = 2;
	}
	else if(edo == 1 && magic[i] == 'b') newedo = 2;
	else if(edo == 2 && magic[i] == 'a') newedo = 3;
	else if(edo == 3 && magic[i] == 'b') return dp[edo][i];

	dp[edo][i] = max(dp[edo][i],1 + maxMagic(i+1,newedo));

	return dp[edo][i];
}

int main(){
	cin>>magic;
	n = magic.size();
	for(int i = 0; i<4; i++) for(int j = 0; j<n+1; j++) dp[i][j] = -1;
	int res = maxMagic(0,0);
	cout<<res<<"\n";
}
