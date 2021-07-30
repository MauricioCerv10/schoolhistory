#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int x; cin>>x;
	int i = 0;
	int k = 0;
	int gus = 0;
	while(k <= x){
		k = 1<<i;
		//cout<<k<<endl;
		int j = k&x;
		if((k&x) != 0) gus++;
		i++;
	}
	cout<<gus<<"\n";
}
