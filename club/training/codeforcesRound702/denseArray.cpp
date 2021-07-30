#include <bits/stdc++.h>
using namespace std;
int a[55];
bool areDense(int x, int y){
	int minVal = min(x,y);
        int maxVal = max(x,y);
        int resVal = ceil((double)maxVal/minVal);
	return resVal <= 2;
}
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		for(int i = 0; i<n; i++){
			cin>>a[i];
		}
		int res = 0;
		for(int i = 1; i<n; i++){
			int iniMinVal = min(a[i],a[i-1]);
			int iniMaxVal = max(a[i],a[i-1]);
			if(!areDense(a[i],a[i-1])){
				//cout<<"no dense "<<iniMinVal<<" "<<iniMaxVal<<endl;
				while(!areDense(iniMinVal,iniMaxVal) && iniMinVal < iniMaxVal){
				//	cout<<iniMinVal<<" "<<iniMaxVal<<endl;
					iniMinVal *= 2;
					res++;
				}
			}
		}
		cout<<res<<endl;
	}
}
