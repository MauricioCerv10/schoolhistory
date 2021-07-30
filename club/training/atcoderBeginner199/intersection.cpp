#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	int maxAnum = INT_MIN;
	for(int i = 0; i<n; i++){
		int num; cin>>num;
		maxAnum = max(maxAnum,num);
	}
	int minBnum = INT_MAX;
	for(int i = 0; i<n; i++){
		int num; cin>>num;
		minBnum = min(minBnum,num);
	}

	int res = minBnum -  maxAnum + 1;
	
	res = res < 0 ? 0 : res;
	cout<<res<<endl;
}
