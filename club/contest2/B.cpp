#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

int main(){
	optimizar_io
	vector<map<ll,ll>> likes;
	set<ll> dlikes;
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		int t, s;
		ll num;
		cin>>t>>s;
		map<ll,ll> nmap;
		if(t == 1) likes.push_back(nmap);
		for(int j = 0; j < s ; j++){
			cin>>num;
			if( t == 1 ) likes.back().insert(pair<ll,ll>(num,num));
			else dlikes.insert(num);
		}
	}
	if(likes.size() == 0){
		ll ans = 1000000000000000000 - dlikes.size() ;
		cout<<ans<<endl;
	}else{
		bool is_in = false;
		int con = likes[0].size();
		for(auto i = likes[0].begin(); i != likes[0].end();i++){
			ll tmp = i->first;
			int apps = 0;
			is_in= dlikes.find(tmp) != dlikes.end();
			if(is_in){ con--; continue; }
			for(int j = 1; j<likes.size();j++){
				is_in = likes[j].find(tmp) != likes[j].end();
				if(is_in) apps++; 
			}
			if(apps != likes.size()-1) con--;
		}
		cout<<con<<endl;
	}
}
