#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll,ll> sump[50005];
ll w[50005];
ll s[50005]; 

bool ordena(pair<ll,ll> x, pair<ll,ll> y){
	return x.second > y.second;
}

int main(){
	int n;
	cin>>n;
	ll sumw = 0;
	for(int i = 0; i<n; i++){
		cin>>w[i]>>s[i];
		sump[i].first = i;
		sump[i].second = w[i]+s[i];
		sumw += w[i];
	}
	sort(sump,sump+n,ordena);
	ll max = -99999999999;
	for(int i = 0; i<n ; i++){
		sumw -= w[sump[i].first];
		ll ans = sumw - s[sump[i].first];
		if( ans > max) max = ans;
	}
	//if(n == 1) max = -s[0];
	cout<<max<<endl;
}
