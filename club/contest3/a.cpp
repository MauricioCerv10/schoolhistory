#include <bits/stdc++.h>
using namespace std;
const long long m = 3000000000000000000;
long long expBinaria(long long a,long long b){
        long long  res = 1;
        while(b){
                if(b&1) res = (a*res)%m;
                b >>= 1;
                a = ((a%m)*(a%m))%m;
        }
        return res;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int a,b,d;
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b>>d;
		long long d2 = expBinaria(d,2);
		double ans = (double)d2/2;
		cout<<fixed<<setprecision(10)<<ans<<"\n";
	}
}
