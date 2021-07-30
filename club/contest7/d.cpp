#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int t; cin>>t;
	while(t--){
		int n,k;
		vector<int> lprice;
		cin>>n>>k;
		for(int i = 0 ; i<n ; i++){
			int p[3];
			for(int j = 0; j<3 ;j++) cin>>p[j];
			sort(p,p+3);
			lprice.push_back(p[0]);
			lprice.push_back(p[1]);
		}
		sort(lprice.begin(),lprice.end());
		ll ans = 0;
		for(int i = 0; i<k; i++) ans += lprice[i];
		cout<<ans<<"\n";
	}
}
