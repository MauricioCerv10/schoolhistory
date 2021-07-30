#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int minVal = INT_MAX, maxVal = INT_MIN, idMin, idMax, a;
		for(int i = 0; i<n; i++){
			cin>>a;
			if(a < minVal){
				idMin = i;
				minVal = a;
			}
	
			if(a > maxVal){
				idMax = i;
				maxVal = a;
			}
		}
	
		int leftMost = min(idMin,idMax);
		int rightMost = max(idMax, idMin);
	
		int res = min((leftMost + 1) + (n - rightMost), min(n - leftMost, rightMost + 1));
		cout<<res<<endl;
	}
}
