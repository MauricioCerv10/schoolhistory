#include <bits/stdc++.h>
using namespace std;

int main(){
	string s; cin>>s;
	for(int i = s.size()-1;i>=0;i--){
		char c = s[i] == '6' ? '9' : s[i] == '9' ? '6' : s[i];
		cout<<c;
	}
	cout<<endl;
}
