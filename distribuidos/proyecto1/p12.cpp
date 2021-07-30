#include <bits/stdc++.h>
using namespace std;

void caidaL(double t){
        double res = (9.81 * pow(t,2))/2;
        cout<<res<<endl;
}


int main(){
	double t;
	cin>>t;
	caidaL(t);
}
