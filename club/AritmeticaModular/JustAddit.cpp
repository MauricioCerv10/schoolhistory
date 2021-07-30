#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e7+7;

ll k;

ll expBinaria(ll a,ll b,ll m){
        ll res = 1;
        while(b){
                if(b&1) res = (a*res)%m;
                b >>= 1;
                a = ((a%m)*(a%m))%m;
        }
        return res;
}

ll zSUM(ll n){
	ll ans = ((2*expBinaria(n-1,n-1,MOD))%MOD + expBinaria(n,n,MOD) + (2*expBinaria(n-1,k,MOD))%MOD + expBinaria(n,k,MOD))%MOD;
	return ans;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	ll n;
	while(cin>>n>>k,(n || k)){
		ll ans = zSUM(n);
		cout<<ans<<"\n";
	}
}
