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

int main(){
	ll n;cin>>n;
	sieve(n);
	for(int i = 0; i<primes.size(); i++) cout<<primes[i]<<endl;
}
