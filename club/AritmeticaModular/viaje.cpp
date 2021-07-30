#include <bits/stdc++.h>
using namespace std;

int main(){
	string nc, ng;
	cin>>nc>>ng;

	int sumc = 1, sumg = 1;
	for(int i = 0; i<nc.size();i++) sumc = (sumc*(nc.at(i)-'A'+1))%47;
	for(int i = 0; i<ng.size();i++) sumg = (sumg*(ng.at(i)-'A'+1))%47;
	
	if(sumc == sumg) cout<<"GO\n";
	else cout<<"STAY\n";
}
