#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
int ssize;
bitset<10000010> bs;
vi primes;

void sieve(int maxt){
	ssize = maxt;
	bs[0] = bs[1] = 0;
	for(int i = 2; i<=ssize; i++){
		if(bs[i]){
			for(int j = i*i; j <= ssize; j += i) bs[j] = 0;
			primes.push_back(i);
		}
	}
}
void clear(){
	primes.erase(primes.begin(), primes.end());
	bs.set();
}
int main(){
	int n;
	while(cin>>n,n){
		clear();
		sieve(n);
		vector<int> res;
		for(int i = 0; i<primes.size();i++){
			int total = 0,p = primes[i];
			int cos = n/p;
			while(cos != 0){
				total += cos;
				p = p*primes[i];
				cos = n/p;
			}
			res.push_back(total);
		}
		int count = 0;
		printf("%3d! =",n);
		for(int i = 0; i < res.size();i++){
			count++;
			if(count > 15)	count -= 15, printf("\n      ");
			printf("%3d",res[i]);
		}
		printf("\n");

	}
}
