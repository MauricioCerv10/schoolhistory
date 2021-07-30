#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,k, res;
	cin>>n>>k;
	if(n < k){
		res = min( abs(n-k), n);
	}else{
		res = min(n%k,abs((n%k) - k));
	}
	cout<<res<<endl;
}
