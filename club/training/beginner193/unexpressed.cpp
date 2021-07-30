#include <bits/stdc++.h>
using namespace std;
long long unuseful[10000000];

int findNumbersOfn(int n, long long maxNumRe){
	int ini = 0, fin = 1000000, mid = 0, res = -1;
	while(ini <= fin){
		mid = (ini + fin)/2;
		if(pow(n,mid) > maxNumRe){
			res = mid;
			//cout<<res<<endl;
			fin = mid - 1;
		}
		else{
			ini = mid + 1;
		} 
	} 
	//cout<<"res = "<<res<<endl;
	if(res != -1){
		return res-2;
	} else{
		return 0;
 	}
}

int main(){
	long long n; cin>>n;
	int maxNum = sqrt(n);
	int represent = 0;
	for(int i = 2; i<=maxNum; i++){
		if(unuseful[i] == 1) continue;
		long long j = i;
		while(i*j <= maxNum){
			unuseful[i*j] = 1;
			j *= i;
		}
		represent += findNumbersOfn(i,n);
	}

	cout<<n - represent<<endl;
}
