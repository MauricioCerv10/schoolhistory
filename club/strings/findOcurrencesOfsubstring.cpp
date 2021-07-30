#include <bits/stdc++.h>
using namespace std;
vector<int> ocurrences;
int n;
string a; 
string b;
void getOcurrs(int fiIdx){
	if(fiIdx >= n){
		return;
	}
	ocurrences.push_back(fiIdx);
	int idx = a.find(b,fiIdx);
	getOcurrs(idx);
}
int main(){
	a = "Hola alejandra janez";
	b = "jan";
	n = a.size();
	for(int i = 0; i<ocurrences.size(); i++){
		cout<<ocurrences[i]<<endl;
	}
}
