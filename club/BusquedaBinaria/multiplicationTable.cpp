#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll getNums(ll target, ll n, ll m){
	ll lessNums = 0;
	for(ll i = 1; i <= n; i++){
		if(i > target) break;
		ll ini = 1, fin = m, mid = 0,res = 0;
		while(ini <= fin){
			mid = (ini + fin)/2;
			if(mid * i <= target){
				res = mid;
				ini = mid + 1;
			}else fin = mid - 1;
		}
		//cout<<res<<endl;
		lessNums += res;
	}
	return lessNums;
}

bool isPrime(ll x, ll target){
	if(x == 1) return false;
	if(target == 1) return false;
	for(ll i = 2; i<=x; i++) if(target%i == 0) return false;
	return true;
}

int main(){
	ll n,m,k; cin>>n>>m>>k;
	//cout<<getNums(10,7,7)<<endl;
	ll ini = 1, fin = n*m, mid = 0, res = 0;
	ll countLess = 0;
	while( ini <= fin ){
		mid = (ini + fin)/2;
		//cout<<mid<<endl;
		ll lesThan = getNums(mid,n,m);
		if(lesThan <= k){
			if(!isPrime( max(n,m),mid) ){ res = mid; countLess = lesThan;}
			//cout<<"Res assign = "<<res<<endl;
			ini = mid + 1;
		}else{
			fin = mid - 1;
		}
	}
	if(countLess < k){
		res = isPrime(max(n,m),res+1) ? (res+2) : (res+1);
	}
	cout<<res<<"\n";
}
