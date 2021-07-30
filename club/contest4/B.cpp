#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	double p;
	cin>>s>>p;
	int conp = 0;
	int cono = 0;
	int size = s.length();
	for(int i = 0; i < size ; i++){ if(s[i] == '?') conp++; if(s[i] == '1') cono++;}
	double ans = ((double)cono + (double)(conp)*p);
	ans = ans / size;
	cout<<fixed<<setprecision(5)<<ans<<endl;
}
