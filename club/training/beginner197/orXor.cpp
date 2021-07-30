#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll A[21];
int dp[21][21];
ll getOrVal(int r, int l){
	ll orVal = A[r];
	for(int c = r+1; c <= l; c++){
		orVal = orVal | A[c];
	}
	return orVal;
}

ll minVal(int i, int j, vector<int> currNums){
	//cout<<i<<","<<j<<endl;
	if(j == n-1){ 
		ll nRes = getOrVal(i,j);
		for(int s = 0; s<currNums.size(); s++){
			nRes ^= currNums[s];
		}
		//cout<<"nRes = "<<nRes<<endl;
		return nRes; 
	}
	ll res = getOrVal(i,j);
	ll minNum = 20000000000;
	currNums.push_back(res);
	for(int k = j+1; k < n; k++){
		minNum = min(minNum, minVal(j+1,k,currNums));
	}
	
	return minNum;
}

int main(){
	cin>>n;
	for(int i = 0; i<n; i++) cin>>A[i];
	ll minRes = 20000000000;
	vector<int> currNums;
	for(int a = 0; a<n; a++){
		minRes = min(minRes,minVal(0,a,currNums));
	}
	cout<<minRes<<endl;
}
