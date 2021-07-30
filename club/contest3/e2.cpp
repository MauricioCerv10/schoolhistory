
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int x[100005];

int main(){
	ll n,a;
	cin>>n>>a;
	for(int i = 0; i<n ; i++) cin>>x[i];
	if(n == 1){ cout<<0<<"\n"; return 0;}

	sort(x, x+n);
	
	ll sum = 0;
	ll sum2 = 0, ans = 0;
	if(a  > x[n-1]){ 
		sum += abs(abs(a-x[n-1]) + abs(x[n-1] - x[1]));
		cout<<sum<<"\n";
		return 0;
	}
	else if (a < x[0]){ 
		sum += abs(abs(x[0]-a) + abs(x[n-2] - x[0]));
		cout<<sum<<"\n"; 
		return 0;
	}
	sum = min(abs(x[n-2] - a) + abs(x[n-2] - x[0]), abs(a-x[0]) + abs(x[n-2] - x[0]));
	sum2 = min(abs(x[n-1] - a) + abs(x[n-1] - x[1]), abs(a-x[1]) + abs(x[n-1] - x[1]));
	ans = min(sum,sum2);
	cout<<ans<<"\n";
}

