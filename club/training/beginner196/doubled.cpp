#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n; cin>>n;
	for(long long i = 1; ;i++){
		if( stoll( to_string(i) + to_string(i) ) > n){
			cout<< i - 1<<endl;
			return 0;
		}
	}
	
	
}
