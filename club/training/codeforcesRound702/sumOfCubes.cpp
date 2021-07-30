#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sumCubes(ll a, ll b){
	return a*a*a + b*b*b;
}

bool searchForNum(ll x, ll result, ll fin){
	ll ini = 1, mid = -1, ans = -1;
	while(ini <= fin){
		ll mid = (ini + fin)/2;
		if(sumCubes(x,mid) <= result){ ini = mid + 1; ans = mid;}
		else fin = mid - 1; 
	}
//	cout<<"ans = "<<ans<<endl;
//	cout<<"x   = "<<x<<endl;
	return (ans != -1) && sumCubes(x,ans) == result;
}

int main(){
	int t; cin>>t;
	while(t--){
		ll n; cin>>n;
		bool ansExist = false;
		for(int i = 1; i*i*i <= n; i++){
			if(searchForNum(i,n,n-i*i*i)){ cout<<"YES\n"; ansExist = true; break;}
		}
		if(!ansExist) cout<<"NO\n";
	}
}
