#include <bits/stdc++.h>
using namespace std;

int a[1005];

int main(){
	
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		a[0] = 0;
		for(int i = 1; i<=n; i++)cin>>a[i];
		for(int i = 1; i<=n; i++){
			if(a[i] != -1){
				for(int j = i; j>= 1; j--){
					if(a[j] == -1){	
						a[j] = a[j+1] - 1;
						if(a[j] < 0 ) a[j] = m-1;
					}
				}
			}
		}
		for(int i = 1; i<=n; i++){
			if(a[i] == -1) a[i] = (a[i-1]+1)%m;
		}
		for(int i = 1;i<=n; i++){
			if(i == n) cout<<a[i];
			else cout<<a[i]<<" ";
		}
		cout<<"\n";
	}	
}
