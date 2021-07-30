#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)

#define MAX 100000+10
int n,pla[MAX];

double ok(double pos){
	double res = 0;
	forn(i,0,n)res += (double)(1/(pla[i]-pos));
	return res;
}
int main(){
	cin >> n;
	forn(i,0,n)cin >> pla[i];
	sort(pla,pla+n);
	cout << n-1 << "\n";
	forn(i,0,n-1){
		double ini = pla[i],fin = pla[i+1];
		double mit;
		forn(j,0,50){
			mit = (double)((ini+fin)/2.0);
			if(ok(mit) < 0)ini = mit;
			else fin = mit;
		}
		if(i)cout << " ";
		cout << fixed << setprecision(3) << mit;
	}
	cout << "\n";
}
