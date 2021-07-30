#include <bits/stdc++.h>
using namespace std;
int ocurr[105];
int nums[105];
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;		
		for(int i = 0; i<=100; i++) ocurr[i] = 0;
		for(int i = 0; i<n; i++){
			cin>>nums[i];
			ocurr[nums[i]] += 1;
		}
		int res = 0;
		for(int i = 0; i<=100; i++){
			if(ocurr[i] == 1){res = i; break;} 
		}

		for(int i = 0; i<n; i++){
			if(nums[i] == res){
				cout<<i+1<<endl;
				break;
			}
		}
	}
}
