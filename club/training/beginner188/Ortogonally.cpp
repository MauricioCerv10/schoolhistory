#include <bits/stdc++.h>
using namespace std;

int A[100005];
int B[100005];

int main(){
	int n;
	cin>>n;
	for(int i = 0; i<n; i++) cin>>A[i];
	for(int i = 0; i<n; i++) cin>>B[i];

	long long res = 0;

	for(int i = 0; i<n; i++){
		res += A[i] * B[i];
	}

	if(res == 0) cout<<"Yes\n";
	else cout<<"No\n";
}
