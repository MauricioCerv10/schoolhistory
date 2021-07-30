#include <bits/stdc++.h>
using namespace std;
long long memo[2][100];
string s[100];
int n;
long long dp(int op, int i){
	if(i == n && op == 1) return 1;
	else if(i == n && op == 0) return 0;
	if(memo[op][i] != -1) return memo[op][i];
	long long res = 0;
	if(s[i] == "AND")
		if(op == 1) res = dp(1,i+1) + dp(0,i+1);
		else res =  dp(0,i+1) + dp(0,i+1);
	else
		if(op == 1) res = dp(1,i+1) + dp(1,i+1);
                else res = dp(1,i+1) + dp(0,i+1);
	memo[op][i] = res;
	return memo[op][i];
}

int main(){
	cin>>n;
	for(int i = 0; i<n; i++){
		cin>>s[i];
	}

	for(int i = 0; i<=n+5; i++){
		memo[0][i] = -1;
		memo[1][i] = -1;
	}

	long long tuples = dp(0,0) + dp(1,0);
	cout<<tuples<<"\n";
}
