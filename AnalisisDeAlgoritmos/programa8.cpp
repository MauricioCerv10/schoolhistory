#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int i = n;
	int con = 0;
	while(i>=0){
		for(int j = n;i<j;i-=2,j/=2){
			cout<<"Algoritmos :"<<++con<<"\n";
		}
	}
}
