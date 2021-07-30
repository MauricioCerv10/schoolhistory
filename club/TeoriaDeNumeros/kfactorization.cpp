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
	int n,k; cin>>n>>k;
	sieve(n);
	vi factors = primeFactors(n);
	if(k > factors.size()){ cout<<"-1"<<endl; return 0;}
	int i;
	for(i = 0; i<k-1; i++){
		cout<<factors[i]<<" ";
	}
	int res = 1;
	for(int j = i; j<factors.size(); j++){
		res *= factors[j];
	}
	cout<<res<<endl;
	return 0;
}
