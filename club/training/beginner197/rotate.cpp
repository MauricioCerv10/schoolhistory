#include <bits/stdc++.h>
using namespace std;

int main(){
	string wrd; cin>>wrd;
	string nwrd = "abc";
	nwrd[0] = wrd[1];
	nwrd[1] = wrd[2];
	nwrd[2] = wrd[0];

	cout<<nwrd<<endl;
}
