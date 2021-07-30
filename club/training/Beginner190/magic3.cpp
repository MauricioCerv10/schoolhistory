#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,s,d;
	cin>>n>>s>>d;
	bool makeDamage = false;
	for(int i = 0; i<n; i++){
		int x,y;
		cin>>x>>y;
		if(x < s && y>d) makeDamage = true;
	}

	if(makeDamage) cout<<"Yes\n";
	else cout<<"No\n";
}
