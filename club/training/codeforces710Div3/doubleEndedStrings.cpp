#include <bits/stdc++.h>
using namespace std;

string a,b;
int lcsub(){
	int n = a.size();
	int m = b.size();
	int lcs[n+1][m+1];
	int res = 0;
	for(int i = 0; i<=n; i++){
		for(int j = 0;j<=m; j++){
			if(i == 0 || j == 0){
				lcs[i][j] = 0;
			} else if( a[i-1] == b[j-1] ){ 
				lcs[i][j] = lcs[i-1][j-1] + 1;
				res = max(res, lcs[i][j]);
			} else {
				lcs[i][j] = 0;
			}

		}
	}
	return res;
}

int main(){
	int t; cin>>t;
	while(t--){
		cin>>a>>b;
		int maxSubs = lcsub();
		int minMovs = a.size() + b.size() - 2 * maxSubs;
		cout<<minMovs<<endl;
	}
}
