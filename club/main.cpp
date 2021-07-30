#include <iostream>

using namespace std;

int N, p, a[18+5];

int main(){
	cin >> N >>p;
	long long int pot = 1;
	for (int i = 0; i<N; i++){
		a[i] = pot%p;
		pot*=10;
	}
	
	for(int i=N-1;i>0;i--){
		cout << a[i] << " ";
	}

	cout<<a[0]<<"\n";

}
