#include <bits/stdc++.h>
using namespace std;
int A[10005];
int main(){
	int n;
	cin>>n;
	for(int i = 0; i<n; i++){
		cin>>A[i];
	}
	long long maxSum = -1;
	for(int i = 0; i<n; i++){
		int minOr = A[i];
		long long total = A[i];
		for(int j = i-1; j>=0; j--){
			if(A[j] >= minOr) total += minOr;
			else break;
			
		}
		for(int j = i+1; j<n; j++){
			if(A[j] >= minOr) total += minOr;
			else break;
		}
		maxSum = max(maxSum, total);
	}
	cout<<maxSum<<"\n";
}
