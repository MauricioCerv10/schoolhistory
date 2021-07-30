#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll expBinaria(ll a,ll b,ll m){
        ll res = 1;
        //a = a%m;
        while(b){
                if(b&1) res = (a*res)%m;
                b >>= 1;
                a = ((a%m)*(a%m))%m;
        }
        return res;
}
bool isPrime(ll n) 
{ 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (ll i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 

int main(){
	ll p,a;
	while(cin>>p>>a,(p || a)){
		ll ans = expBinaria(a,p,p);
		if((ans != a) || isPrime(p)) cout<<"no\n";
		else cout<<"yes\n";
	}
}
