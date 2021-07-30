#include <bits/stdc++.h>
using namespace std;
 
#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define clr(v, d)		memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
typedef long long ll;
 
const double EPS = (1e-7);
 
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}
 
int t, n;
vector<double> running, cycling;
 
// Compute time difference between others and me...we want r that maximize f
double f(double r)
{
	double minOthers = 0;
 
	lp(i, n)
	{
		double time = r / running[i] + (t-r) / cycling[i];
 
		if (i != n-1)
		{
			if(i == 0 || dcmp(minOthers, time) > 0)
				minOthers = time;
		}
		else
			return minOthers - time;
	}
	return -1;
}
 
// Find r that maximize last contestant time difference from others
double ternary() {
	double leftR = 0, rightR = t;	// running km range
 
	while(rightR-leftR > EPS) {
		double g = leftR+(rightR-leftR)/3, h = leftR+2*(rightR-leftR)/3;
 
		if( f(g) > f(h) )
			rightR = h;
		else
			leftR = g;
	}
 
	return (leftR+rightR)/2;
}
 
int main() {
 
	while(cin>>t>>n)
	{
		running = vector<double>(n);
		cycling = vector<double>(n);
 
		lp(i, n)
			cin>>running[i]>>cycling[i];
 
		double ans = ternary();
		double time = f(ans)*3600;
 		 cout<<fixed<<setprecision(6)<<ans<<endl;

		if(dcmp(time, 0) > 0)
			printf("The cheater can win by %.0lf seconds with r = %.2lfkm and k = %.2lfkm.\n", time, ans, t-ans);
		else
			printf("The cheater cannot win.\n");
	}
 
	return 0;
}
