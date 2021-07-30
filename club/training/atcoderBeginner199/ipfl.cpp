#include <bits/stdc++.h>
using namespace std;

int getRealA(int revs, int a, int n){
	if(revs%2 != 0){
		if(a <= n){
			return a+n;
		}else{
			return a-n;
		}
	}
	return a;
}

int main(){
	int n; cin>>n;
	string s; cin>>s;

	int q; cin>>q;
	int revs = 0;
	while(q--){
		int t,a,b; cin>>t>>a>>b;
		if(t == 1){
			int realA = getRealA(revs, a, n);
			int realB = getRealA(revs, b, n);
			char tmp = s[realA-1];
			s[realA-1] = s[realB-1];
			s[realB-1] = tmp;
		}else{
			revs++;
		}
		//cout<<s<<endl;
	}

	if(revs%2 != 0){
		string str1 = s.substr(0,n);
		string str2 = s.substr(n,n);
		s = str2 + str1;
	}
	cout<<s<<endl;
}
