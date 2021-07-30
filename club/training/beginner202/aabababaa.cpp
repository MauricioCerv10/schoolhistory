#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,k; cin>>a>>b>>k;
	string s = ""; 
	for(int i = 0; i < a; i++) s += 'a';
	for(int i = 0; i < b; i++) s += 'b';
	string original = s;
	for(int i = 0; i<k-1; i++){
    		bool val = next_permutation(s.begin(),s.end());
		//cout<<s<<endl;
        	if(!val) s = original;
	}
	cout<<s<<endl;
    	return 0;
}
