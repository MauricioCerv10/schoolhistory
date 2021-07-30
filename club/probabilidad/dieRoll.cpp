#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	int maxnum = max(a,b);
	int numerador = 6 - maxnum + 1;
	if(numerador == 0) cout<<"1/6\n";
	if(numerador == 1) cout<<"1/6\n";
	if(numerador == 2) cout<<"1/3\n";
	if(numerador == 3) cout<<"1/2\n";
	if(numerador == 4) cout<<"2/3\n";
	if(numerador == 5) cout<<"5/6\n";
	if(numerador == 6) cout<<"1/1\n";

	
}
