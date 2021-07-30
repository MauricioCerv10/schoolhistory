#include <bits/stdc++.h>
using namespace std;

int a,b,c;
int dp[4005];

int memo(int n){
	if(n == 0) return 0;
	if(n < 0)  return -80000000;
	if(dp[n] != 0) return dp[n];
	else{
		dp[n] = 1+max(memo(n-a),max(memo(n-b),memo(n-c)));
	}
	return dp[n];
}

int main(){
	int n;
	cin>>n>>a>>b>>c;
	int ans = memo(n);
	cout<<ans<<endl;
}
