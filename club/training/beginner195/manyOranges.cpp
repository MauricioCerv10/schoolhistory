#include <bits/stdc++.h>
using namespace std;
int a,b,w;
int main(){
	cin>>a>>b>>w;
	int m = 1000000000;
	int M = -1;
	for(int i = 1; i<=1000000; i++){
		if(a*i <= w*1000 && w*1000 <= b*i){
			m = min(m,i);
			M = max(-1,i);
		}
	}
	if(M == -1) cout<<"UNSATISFIABLE\n";
	else cout<<m<<" "<<M<<"\n";
}
