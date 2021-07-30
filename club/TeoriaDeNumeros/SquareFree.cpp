#include <bits/stdc++.h>
using namespace std;


#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

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
bool isPrime(ll n){
        if(n <= _sieve_size) return bs[n];
        for(int i = 0; i < (int)primes.size(); i++)
                if(n%primes[i] == 0) return false;
        return true;
} //only work for N <= (last prime in vi "primes")^2

vi primeFactors(ll n){
        vi factors;
        ll pf_idx = 0, pf = primes[pf_idx];
        int ans = 0;
        while(pf*pf <= n){
                while(n%pf == 0){ n /= pf; ans++; factors.push_back(pf);}
                pf = primes[++pf_idx];
        }
        if(n != 1){
                factors.push_back(n);
                ans++;
        }
        //return ans Number of prime factors of n
        return factors;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		
		if(si) cout<<"NO"<<endl;
		else cout<<"SI"<<endl;
	}
}

