#include <bits/stdc++.h>
using namespace std;

void  algoritmoB(double n){
	double b = n, h = 0;

    	while ((b-h) > 0.000001) {
        	b = (h + b) / 2;
        	h = n / b;
    	}
    	cout<<fixed<<setprecision(4)<<b<<endl;
}

int main(){
	double n;
	cin>>n;
	algoritmoB(n);
}
