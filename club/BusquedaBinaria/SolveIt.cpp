#include <bits/stdc++.h>
using namespace std;

double p,q,r,s,t,u;
const double ERROR = 1e-6;
#define EQ(a,b) (fabs((a) - (b)) < ERROR)

double solve(double x){
	return (double) p*exp(-x) + q*sin(x) +r*cos(x) + s*tan(x) + t*pow(x,2) + u;
}
int main(){
	while(cin>>p>>q>>r>>s>>t>>u){
		double ini = 0, fin = 1,res = -1, mid = 0;
		for(int i = 0;i<100;i++){
			mid = (ini+fin)/2;
			if(solve(mid) > 0){ ini = mid; }
			else { fin = mid; res = mid;}
		}

		
		if(!EQ(0,solve(res))) cout<<"No solution\n";
		else cout<<fixed<<setprecision(4)<<res<<"\n";
	}
}
