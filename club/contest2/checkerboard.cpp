#include <bits/stdc++.h>
using namespace std;  

typedef long long ll;

int main(){ 
        ll n,x1,y1,x2,y2;
        cin>>n>>x1>>y1>>x2>>y2;
        ll min = abs(x2 - x1) + abs(y2-y1); 
        if(n < min)cout<<0<<endl;
        else {	
		if(min == 0) min = 2;
		ll nums = n-min+1;
        	ll ans = 0;
        	if((n%2 == 0 && min%2 == 0) || (n%2 != 0 && min%2 != 0)) ans = nums/2 + 1; 
        	else ans = nums/2; 
        	cout<<ans<<endl; 
	}
}
