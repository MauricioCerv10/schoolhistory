#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve (ll upperbound){
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= _sieve_size; i++){
		if(bs[i]){
			for(int j = i*i; j<= _sieve_size; j += i) bs[j] = 0;
			primes.push_back(i);
		}
	}
}
bool isPrime(ll n){
	return bs[n];
}
int main(){
	int n; cin>>n;
	//sieve(n);
	int first = n-4, second = 4; 
	/*while(1){
		if(!isPrime(first) && !isPrime(second)) break;
		first--; second++;
	}*/
	if(n%2 == 0){
		first = 4;
		second = n-4;
	}else{
		first = 9;
		second = n-9;
	}
	cout<<first<<" "<<second<<endl;
}
