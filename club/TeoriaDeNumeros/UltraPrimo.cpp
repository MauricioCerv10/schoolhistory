#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound){
        _sieve_size = upperbound+1;
        bs.set();
        bs[0] = bs[1] = 0;
        for(ll i = 2; i <= _sieve_size; i++){
                if(bs[i]){
                        for(ll j = i*i; j <= _sieve_size; j += i) bs[j] = 0;
                        primes.push_back(i);
                }
        }
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
	ll t;
	cin>>t;
	while(t--){
		string cad;
		cin>>cad;
		ll res = 0;
		for(ll i = 0; i<cad.size();i++){
			ll num = cad.at(i) - '0';	
			res += num;
			
		}
		if(isPrime(res) || res == 1) cout<<"UltraPrimo\n";
		else cout<<"No UltraPrimo\n";
	}
}
