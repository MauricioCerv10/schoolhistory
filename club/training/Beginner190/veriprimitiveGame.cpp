#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if((c == 0 && a>b) || (c == 1 && a >= b)){
		cout<<"Takahashi\n";
	}else{
		cout<<"Aoki\n";
	}
}
