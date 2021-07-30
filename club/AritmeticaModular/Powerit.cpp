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
		ll x,y,n;
		cin>>x>>y>>n;
		//cout<<expBinaria(x,y,n)<<"\n";
		cout<<y<<endl;
	}
}


