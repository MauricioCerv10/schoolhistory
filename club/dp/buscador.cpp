#include <bits/stdc++.h>
using namespace std;

string ps[105];
string p;
int n,s,m;
int lcs[105][105];

int dp(int &idx){
	for(int i = 0; i<=s; i++){
		for(int j = 0; j<=m; j++){
			if(i == 0 || j == 0) lcs[i][j] = 0;
			else if( p[i-1] == ps[idx][j-1]) lcs[i][j] = 1+lcs[i-1][j-1];
			else lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
		}
	}
	return lcs[s][m];
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>p;
	cin>>n;
	for(int i = 0; i<n; i++) cin>>ps[i];
	int max = -45645;
	s = p.length();
	int idMax = 0;
	for(int i = 0; i < n; i++){
		m = ps[i].length();
		int ans = dp(i);
		if(ans == max && ps[idMax].length() > m) idMax = i;
		if(ans > max){ max = ans; idMax = i;}
		for(int j = 0; j <= s; j++) for(int c = 0; c <= m; c++) lcs[j][c] = 0;
	}
	cout<<ps[idMax]<<endl;
}
