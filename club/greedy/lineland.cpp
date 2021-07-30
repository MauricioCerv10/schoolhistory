#include <bits/stdc++.h>
using namespace std;

int x[100005];

int main(){
	int n;cin>>n;
	for(int i = 0; i<n; i++) cin>>x[i];
	int mind = 2000000000, maxd = -2000000000;
	for(int i = 0; i<n; i++){
		int min1 = 2000000000, min2 = 2000000000;
		if(i+1 < n) min1 = abs(x[i] - x[i+1]);
		if(i-1 >= 0) min2 = abs(x[i-1] - x[i]);
		mind = min(min1,min2);
		int max1 = -1000000005, max2 = 1000000005;
		maxd = max(abs(x[i] - x[n-1]), abs(x[0] - x[i]));
		cout<<mind<<" "<<maxd<<endl; 
	}
	
}
