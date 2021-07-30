#include <bits/stdc++.h>
using namespace std;

int dp[55][50005];

int main(){
	int n,ini,m;
	int vol[55];
	cin>>n;
	for(int i = 0; i<n;i++) cin>>vol[i];
	cin>>ini>>m;

	dp[0][ini] = 1;
	for(int i=0;i<=n;++i){
		for(int j = 0; j<=m;++j){
			if(dp[i][j] == 1){
				if(j+vol[i] <= m)
					dp[i+1][j+vol[i]] = 1;
				if(j-vol[i] >= 0)
					dp[i+1][j-vol[i]] = 1;
			}
		}

	}
	int max = -1;
	for(int i = 0; i<=m; i++){
		if(dp[n][i] == 1) max = i;
	}
	cout<<max<<"\n";
}
