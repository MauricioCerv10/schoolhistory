#include <bits/stdc++.h>
using namespace std;

int main(){
	string slot;
	cin>>slot;
	if(slot[0] == slot[1] && slot[1] == slot[2]){
		cout<<"Won"<<endl;
	}else{
		cout<<"Lost"<<endl;
	}
}
