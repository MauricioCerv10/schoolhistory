#include <bits/stdc++.h>
using namespace std;

int main(){
	int x,y;
	cin>>x>>y;
	int maxScore = max(x,y);
	int minScore = min(x,y);

	if(minScore + 3 > maxScore) cout<<"Yes\n";
	else cout<<"No\n";
}
