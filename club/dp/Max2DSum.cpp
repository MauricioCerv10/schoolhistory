#include <bits/stdc++.h>
using namespace std;

int nums[110][110];
int n;

int main(){
	while(cin>>n){
		for(int i = 0; i<n;i++)
			for(int j = 0; j<n;j++){
				cin>>nums[i][j];
				if(i>0) nums[i][j] += nums[i-1][j];
				if(j>0) nums[i][j] += nums[i][j-1];
				if(i>0 && j>0) nums[i][j] -= nums[i-1][j-1]; 
			}
		int maxSub = -127*100*100;
		int sub;
		for(int i = 0; i<n;i++) for(int j = 0; j<n;j++)
		for(int k = i; k<n;k++) for(int l = j; l<n;l++){
			sub = nums[k][l];
			if(i > 0) sub -= nums[i-1][l];
			if(j > 0) sub -= nums[k][j-1];
			if(i > 0 && j>0) sub += nums[i-1][j-1];
			maxSub = max(sub,maxSub);
		}
		cout<<maxSub<<endl;
	}
}

