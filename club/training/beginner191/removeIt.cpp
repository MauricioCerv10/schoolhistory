#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,x; cin>>n>>x;
	for(int i = 0; i<n; i++){
		int ele; cin>>ele;
		if(x != ele){
			if(i == n-1) cout<<ele;
			else cout<<ele<<" ";
		}
	}
	cout<<"\n";
}
