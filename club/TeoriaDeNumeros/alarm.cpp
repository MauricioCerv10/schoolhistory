#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll p[300010];
ll x[300010];

ll gcd(ll a,ll b){ return b == 0 ? a : gcd(b,a%b);}


int main(){
	int n,m;cin>>n>>m;
	ll y; cin>>y;
	ll res = 0;
	ll xi;
	for(int i = 1;i<n;i++){
		cin>>xi;
		x[i] = (xi - y);
	}
	for(int i = 0; i<m; i++) cin>>p[i];
	ll g = x[1];
	for(int i = 2; i<n; i++){
		g = __gcd(g,x[i]);
	}
	for(int i = 0; i<m; i++){
		if(g%p[i] == 0){
			cout<<"YES\n"<<y<<" "<<i+1<<"\n";
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}
