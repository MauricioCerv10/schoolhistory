#include <iostream>
using namespace std;

int dp[1005];
int nums[1005];

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		for(int i = 0; i<n; i++){dp[i] = 0; cin>>nums[i];}
		int maxlis = -4564;
		dp[0] = 1;
		for(int i = 0; i<n; i++){
			int maxnum = 0;
			for(int j = i-1; j>=0; j--)
				if(nums[j] < nums[i]) maxnum = max(dp[j],maxnum);
			dp[i] = 1 + maxnum;
			maxlis = max(dp[i],maxlis);
		}
		cout<<maxlis<<"\n";
	}
}
