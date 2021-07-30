#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll getNumberByRows(ll x, ll y, ll m){
	return ((y-1) * m) + x;
}

int main(){
	int t; cin>>t;
	while(t--){
		ll n, m, x; cin>>n>>m>>x;
		ll x1, y1;
		if(x%n == 0){
			x1 = x/n;
			y1 = n;
		}else{
			x1 = x/n + 1;
			y1 = x - ( n * (x/n) );
		}
		ll res = getNumberByRows(x1,y1,m);
		cout<<res<<"\n";
	}
}
