#include <bits/stdc++.h>
using namespace std;
int ocurr[100005];
int b[100005];
int c[100005];

int main(){
	int n; cin>>n;
	for(int i = 0; i<n; i++){
		int x; cin>>x;
		ocurr[x] += 1;
	}
	for(int i = 0; i<n; i++) cin>>b[i];
	long long res = 0;
	for(int i = 0; i<n; i++){
		int x; cin>>x;
		res += ocurr[b[x-1]];
	}
	cout<<res<<endl;
}
