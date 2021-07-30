#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int x[100005];

int main(){
	int n,a;
	cin>>n>>a;
	for(int i = 0; i<n ; i++) cin>>x[i];
	if(n == 1){ cout<<abs(x[0]-a)<<"\n"; return 0;}

	sort(x, x+n);
	
	ll sum = 0;
	if(a  > x[n-1]){ 
		sum += abs((a-x[n-1]) + (x[n-1] - x[1]));
		cout<<sum<<"\n";
		return 0;
	}
	else if (a < x[0]){ 
		sum += abs((x[0]-a) + (x[n-2] - x[0]));
		cout<<sum<<"\n"; 
		return 0;
	}
	int ans;
	if(x[n-1]-x[1] > x[n-2] - x[0]){
		ans = min(abs(x[n-2] - a) + abs(x[n-2] - x[0]), abs(a-x[0]) + abs(x[n-1] - x[0]))

	}else{
		
	}
	cout<<sum<<"\n";
}

