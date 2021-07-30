#include <bits/stdc++.h>
using namespace std;

int money[10010];

int main(){
	int n;
	while(cin>>n,n){
		for(int i = 0; i<n;i++) cin>>money[i];
		int sum = 0,ans = 0;
		int ini = 0,fin=0,j = 1, k = 1;
		for(int i = 0; i<n;i++){
			sum +=money[i];
			ans = max(sum,ans);
			if(sum < 0){
				sum = 0;
			}
		}
		if( ans>0 ) cout<<"The maximum winning streak is "<<ans<<".\n";
		else cout<<"Losing streak.\n";
	}
}

