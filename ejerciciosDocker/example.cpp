#include <iostream>
using namespace std;

int main(){
	int n = 10;
	int espacios = n;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<espacios; j++){
			cout<<" ";
		}
		for(int j = 0; j<=i; j++){
			cout<<"* ";
		}
		espacios--;
		cout<<endl;
	}
}
