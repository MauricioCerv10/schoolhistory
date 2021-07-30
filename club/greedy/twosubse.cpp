#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[1000005];
int b[1000005];

bool ordena(int x, int y) {
	return (x > y);
}


int main(){
	ll t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll suma = 0, sumb = 0;
		for(int i = 0; i<n; i++) cin>>a[i]; 
		for(int i = 0; i<n; i++) cin>>b[i];
		ll sum = 0;
		int subse = 0;
		vector<int> neg;
		for(int i = 0; i<n; i++)
			if(a[i] >= b[i]) {
				sum += a[i]-b[i];
				subse++;
			}else
				neg.push_back(a[i] - b[i]);
		
		sort(neg.begin(),neg.end(),ordena);
		
		for (int i = 0; i < neg.size(); i++){
			sum += neg[i];
			if(sum >= 0) subse++;
			else break;
		}

		cout<<subse<<endl;
	}
}
