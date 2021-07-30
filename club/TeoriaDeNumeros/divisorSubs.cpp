#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

bitset<10000010> bs;
vi primes;
ll _sieve_size;

void sieve(ll upperbound){
	_sieve_size = upperbound+1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= _sieve_size; i++){
		if(bs[i]){
			for(ll j = i*i; j<= _sieve_size; j += i){
				bs[j] = 0;
			}
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
	ll n;cin>>n;
	sieve(1000000);
	ll ans = 0;
	if(n>1000000 && isPrime(n)){
		cout<<1<<endl;
		return 0;
	}
	for(int i = 0; i<primes.size(); i++){
		if((n%primes[i]) == 0){
			 n -= primes[i];
			ans++;
			break;
		}
	}
	ans += n/2;
	cout<<ans<<endl;

	return 0;
}
