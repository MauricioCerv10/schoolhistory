#include <bits/stdc++.h>
using namespace std;

#define MAX 1000005

int num[MAX];

int main(){
	
	string dig;
	cin>>dig;
	
	int n = dig.size();
	//int bper = 0;
	for(int i = 0; i<n;i++){
		num[i] = dig.at(i) - '0';
		//bper += num[i]*pow(10,n-i-1);
	}
	
	if(next_permutation(num,num+n)){
		int aper = 0;
		for(int i = 0; i<n ; i++) aper += num[i]*pow(10,n-i-1);
		cout<<aper<<endl;
	}else cout<<0<<endl;
	
}
