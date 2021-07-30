#include <bits/stdc++.h>
using namespace std;

int lis[1005];
int lds[1005];
int nums[1005];

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i = 0; i<n; i++){ lis[i] = 0; lds[i] = 0;}
		for(int i = 0; i<n; i++) cin>>nums[i];
		//LIS

		lis[0] = 1;
		for(int i = 1; i<n; i++){
			lis[i] = 1;
			for(int j = 0; j<i ; j++)
				if(nums[j] < nums[i] && (lis[j] + 1) > lis[i])
					lis[i] = lis[j] + 1;
		}
		//LDS
		lds[n-1] = 1;
		for(int i = n-2; i>=0; i--){
			lds[i] = 1;
			for(int j = n-1; j>i;j--)
				if(nums[j] < nums[i] && lds[j] + 1 > lds[i])
					lds[i] = lds[j] + 1;
		}
		int max = 1;
		for(int i = 0; i < n;i++){
			for(int j = i+1; j<n; j++){
				if(lis[i] + lds[j] > max && nums[i] > nums[j]) max = lis[i] + lds[j];
			}
		}
		cout<<max<<endl;
	}
}
