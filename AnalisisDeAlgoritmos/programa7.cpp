#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int con = 0;
	for(int j = n;j>1;j/=2){
		if(j<(n/2)){
			for(int i = 0; i<n;i+=2){
				cout<<"Algoritmos :"<<con++<<endl;
				
			}
		}
	}
}
