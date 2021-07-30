#include <bits/stdc++.h>
using namespace std;

int main(){
	int q; cin>>q;
	while(q--){
		int tam ; cin>>tam;
		string num;cin>>num;
		if(num.size() == 2 && num[0] >= num[1]){cout<<"NO\n"; continue;}
		cout<<"YES\n";
		string p2 = "",p1 = "";
		p1 += num[0];
		for(int i = 1; i<num.size(); i++) p2 += num[i];
		cout<<2<<"\n";
		cout<<p1<<" "<<p2<<"\n";
	}
}
