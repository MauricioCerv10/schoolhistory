#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 10010

double  sto[MAX];
int N,K;
int caso;

int cut(double len){
	int res = 0;
	for(int i = 0;i<N;i++){ 
		res += sto[i]/len;
	}
	
	return res;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>N>>K;
		if(caso++) cout<<"\n";
		for(int i = 0; i<N;i++) {
			cin>>sto[i]; 
		}
		double ini = 0.00, fin = 1000000.00, res = -1.00, mid = 0.00;
		for(int i = 0; i<100;i++){
			mid = (ini+fin)/2;
			if(cut(mid) < K){ fin = mid;}
			else {ini = mid; res = mid;}
		}
	
		if(res < 0.01) cout<<"0.00"<<endl;
		else{ 
			auto std = std::to_string(res);
                	int pos = std.find('.');
               		cout << std.substr(0,pos+1) << std.substr(pos+1,2) << endl; 

		}
	}
}
