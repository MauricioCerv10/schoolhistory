#include <iostream>
using namespace std;
int caso;

int main(){
	int t;
	cin>>t;
	while(t--){
		if(caso++) cout<<"\n";
		int n;
		cin>>n;
		int con = 0;
		for(int i = 10;i<n*5;i*=2) cout<<"Algortimos :"<<++con<<"\n";
	}
}
