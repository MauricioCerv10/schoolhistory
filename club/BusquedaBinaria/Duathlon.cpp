#include <bits/stdc++.h>
using namespace std;

#define MAX 25

double run[MAX];
double cic[MAX];
double dist,n;
const double EPS = (1e-9);

int dcmp(double x, double y) { return fabs(x-y) <= EPS ? 0: x<y ? -1:1;}

double times(double x){
	double minOthers = 0;
	for(int i = 0; i<n;i++){
		double time = x/run[i] + (dist-x)/cic[i];
		if(i != n-1) {
			if(i==0 || dcmp(minOthers,time) > 0)
				minOthers = time;
		}else{
			return minOthers-time;
		}
	}
	return -1;
}

int main(){
	while(cin>>dist>>n){
		for(int i = 0; i<n; i++){ cin>>run[i]; cin>>cic[i];}
		+l	
		double l = 0, r = dist;
		while((r-l) > EPS){
			double m1 = l+(r-l)/3;
			double m2 = r-(r-l)/3;
			if(times(m1) <= times(m2)) l = m1;
			else r = m2;
		}

		double ans = (l+r)/2;
		double res = times(ans)*3600;

		if(dcmp(res,0) > 0) cout<<"The cheater can win by "<<fixed<<setprecision(0)<<res<<" seconds with r = "<<fixed<<setprecision(2)<<ans<<"km and k = "<<fixed<<setprecision(2)<<dist-ans<<"km.\n";
		else cout<<"The cheater cannot win.\n";
	}


}
