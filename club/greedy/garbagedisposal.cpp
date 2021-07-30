#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[200005];

int main(){
	int n, k;
	cin>>n>>k;
	
	for(int i = 0; i<n; i++) cin>>a[i];

	ll bolsas = 0;
	ll uy = 0;
	for(int i = 0; i<n; i++){
		int nby = uy/k;
		uy -= nby * k;
		if( uy > 0 && uy + a[i] > k){ a[i] =  (uy + a[i]) - k;  bolsas++;}
		else if(uy > 0 && uy + a[i] <= k){ a[i] = 0; uy = 0; bolsas++; }
		int nbt = a[i]/k;
		a[i] -= nbt * k;
		uy = a[i];
		bolsas += nby + nbt;
	}
	bolsas += ceil((float)uy/k);
	cout<<bolsas<<endl;
}
