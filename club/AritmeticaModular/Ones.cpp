#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		int i = 1, value = 1%n;
		while(value){
			i++;
			value = ((value*10) + 1)%n;
		}

		cout<<i<<endl;
	}
}
