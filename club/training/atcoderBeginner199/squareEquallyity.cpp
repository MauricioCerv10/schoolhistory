#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	string ans = ( (a*a + b*b) < c*c) ? "Yes\n" : "No\n";
	cout<<ans;
}
