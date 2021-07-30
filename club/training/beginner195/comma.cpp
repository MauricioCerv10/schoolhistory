#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n; cin>>n;
	long long vals[] = {999,999999,999999999,999999999999,999999999999999,999999999999999999};
	if(n <= 999) cout<<0<<endl;
	else{
		long long res = 0;
		for(int i = 1; i<6; i++){
			if(n <= vals[i]){
				res += (n - vals[i-1]) * i;
				break;
			}
			res += (vals[i] - vals[i-1]) * i;
		}
		cout<<res<<endl;
	}
}
