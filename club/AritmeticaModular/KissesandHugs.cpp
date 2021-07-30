#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll expBinaria(ll a,ll b,ll m){
        ll res = 1;
        while(b){
                if(b&1) res = (a*res)%m;
                b >>= 1;
                a = ((a%m)*(a%m))%m;
        }
        return res;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll ans = (expBinaria(2,(n+1)/2,1000000007)+expBinaria(2,(n+1)-(n+1)/2,1000000007)-2)%1000000007;
		cout<<ans<<endl;
	}
}
