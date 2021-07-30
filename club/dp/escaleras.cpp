#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll nume[10000005];
ll k,n;

ll formas(ll esca){
	if(esca == 0) return 1;
	if(esca <= 0) return 0;
	
	if(nume[esca] == 0 )
		for(int i = 1; i<=k; i++)
			nume[esca] += formas(esca-i);
	else return nume[esca];
	
	return nume[esca];
}

int main(){
	cin>>n>>k;
	ll ans = formas(n);
	cout<<ans<<endl;
}
