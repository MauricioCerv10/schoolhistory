#include <bits/stdc++.h>
using namespace std;

int main(){
	int v,t,s,d; cin>>v>>t>>s>>d;
	int x1 = t * v;
	int x2 = s * v;
	if(d >= x1 && d <= x2 ){
		cout<<"No\n";
	}else{
		cout<<"Yes\n";
	}
}
