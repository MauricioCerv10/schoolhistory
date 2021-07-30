#include <bits/stdc++.h>
    using namespace std;
     
    typedef long long ll;
    ll a[200005];
     
    int main(){
    	ll n,ops; cin>>n>>ops;
    	for(ll i = 0; i<n; i++) cin>>a[i];
    	ll ini = n/2;
    	ll dif = 0;
    	sort(a,a+n);
    	ll med = a[ini];
    	for(ll i = ini; i<n-1; i++){
    		dif = (a[i+1] - med) * (i-ini+1);
    		if( ops >= dif ){
    			med = a[i+1];
    			ops -= dif;
    		}else{
    			ll res = ops/(i-ini+1);
    			med += res;
    			ops = 0; 
    			break;
    		}
    	}
    	ll res = ops / (n-ini);
    	cout<<med+res<<"\n";
    }
