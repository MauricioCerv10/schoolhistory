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
	ll n,k;
	cin>>n>>k;
	ll res = 0;
	for(ll i = 1; i<=n; i++){
		res = (res + expBinaria(i,k,1000000007))%1000000007; 
	}
	cout<<res<<endl;
}
