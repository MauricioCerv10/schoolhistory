#include <bits/stdc++.h>
using namespace std;

int route[20010];

int main(){
	int t,n;
	cin>>t;
	for(int c = 0;c<t;c++){
		cin>>n;
		for(int i = 0; i<n-1;i++) cin>>route[i];
		int sum = 0,ans = 0;
		int ini = 0,fin=0,j = 1, k = 1;
		for(int i = 0; i<n-1;i++){
			sum +=route[i];
			//cout<<j<<" "<<k<<endl;
			//ans = max(ans,sum);
			if(sum < 0 ){
				sum = 0; 
				j = i+2;
				k = i+2; 
			}else {
				k++;
			}
			if(sum>ans){
				ini = j;
				fin = k;
				ans = sum;
			}else if(sum == ans && (k-j) > (fin-ini)){
				ini = j;
				fin = k;
			}
		}
		if( ans>0 ) cout<<"The nicest part of route "<<c+1<<" is between stops "<<ini<<" and "<<fin<<"\n";
		else cout<<"Route "<<c+1<<" has no nice parts\n";
	}
}
