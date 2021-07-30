#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[100005];
ll cant[100005];
int n;

ll memo(ll i){
	//cout<<i<<" "<<sum<<endl;
	if(i == 0) return 0;
	if(i == 1) return cant[i];
	if(dp[i] != 0) return dp[i];
	dp[i] = max( memo(i-1) , cant[i]*i + memo(i-2) );
	return dp[i];
}

int main(){
	cin>>n;
	ll m = 0;
	for(int i = 0; i<n; i++){
		ll num; 
		cin>>num;
		cant[num]++;
		m = max(num,m);
	}
	dp[0] = 0;
	dp[1] = cant[1];
	for(int i = 2; i <= m; i++){
		dp[i] = max(dp[i-1],cant[i]*i + dp[i-2]);
	}
	cout<<dp[m]<<endl;
}
