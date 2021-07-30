#include <bits/stdc++.h>
using namespace std;

int main(){
	string s; cin>>s;
	bool unreadable = true;
	for(int i = 0; i<s.length(); i++){
		if(s[i] >= 97 && s[i] <= 122){
			unreadable = ((i+1) % 2) != 0;
		}else{
			unreadable = ((i+1) % 2) == 0;
		}
		if(!unreadable) break;
	}

	if(unreadable) cout<<"Yes\n";
	else cout<<"No\n";
}
