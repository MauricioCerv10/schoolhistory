#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> primes;
vector<ll> factors;
bitset<10000010> bs;
ll ssize;
ll n,m;

void sieve(ll maxt){
	ssize = maxt;
	bs[0] = bs[1] = 0;
	for(int i = 2; i<=maxt; i++){
		if(bs[i]){
			for(int j = i*i; j<=maxt; j += i){
				bs[j] = 0;
			}
			primes.push_back(i);
		}
	}
}
void getFacts(){
	for(int i = 0; i<primes.size(); i++){
		ll total = 0, p = primes[i];
		ll cos = n/p;
		while(cos != 0){
			total += cos;
			p *= primes[i];
			cos = n/p;
		}
		factors.push_back(total);
	}
}
void clear(){
	primes.erase(primes.begin(), primes.end());
	factors.erase(factors.begin(),factors.end());
	bs.set();
}
int main(){
	while(cin>>n>>m){
		clear();
		sieve(5500);
		getFacts();
		ll cpm = m;
		for(int i = 0; i<factors.size(); i++){
			ll con = factors[i];
			while(con--){
				if( cpm%primes[i] != 0) break;
				cpm /= primes[i];
			}
			if(cpm == 1){ break;}
			if(primes[i] > cpm) break;
		}
		if( m < n || cpm == 1) cout<<m<<" divides "<<n<<"!\n";
		else cout<<m<<" does not divide "<<n<<"!\n";
	}
}
