#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int s[100005];

bool fun(int a,int b){
	return a > b;
}

int main(){
	int n ;
	int a, b;
	cin>>n>>a>>b;
	int fi;
	cin>>fi;
	ll sum = fi;
	for(int i = 0; i<n-1; i++){ 
		cin>>s[i];
		sum += s[i];
	}
	sort(s,s+n,fun);
	ll res = fi*a/sum;
	int con = 0;
	for(int i = 0;i<n; i++){
		if(res < b){
			sum -= s[i];
			con++;
		}else{
			break;
		}
		res = fi*a/sum;
	}
	cout<<con<<endl;
	
}
