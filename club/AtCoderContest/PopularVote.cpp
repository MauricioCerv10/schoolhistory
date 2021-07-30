#include <bits/stdc++.h>
using namespace std;
int votes[105];
int main(){
	int n,m;
	cin>>n>>m;
	int total=0;
	for(int i = 0; i<n; i++){ 
		cin>>votes[i];
		total += votes[i];
	}
	int count=0;
	int coef=ceil((float)total/(4*m));
	
	for(int i = 0; i<n; i++){
		if(votes[i] >= coef) count++;
		if(count == m) break;
	}
	if(count == m) cout<<"Yes\n";
	else cout<<"No\n";
}
