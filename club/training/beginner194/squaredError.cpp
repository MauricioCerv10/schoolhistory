#include <bits/stdc++.h>
using namespace std;

int cnt[1000];
int A[1000005];

int main(){
	int n; cin>>n;
	for(int i = 1; i<=n; i++){
		int a; cin>>a;
		A[i] = a;
		cnt[A[i]+300] += 1;
	}
	long long res = 0;
	//for(int i = -200; i<=200; i++) if(cnt[i+200] > 0) cout<<"cnt = "<<cnt[i+200] <<" i = "<<i<<endl;
	for(int i = -200; i <= 200; i++){
		for(int j = i+1; j<=200; j++){
			long long cnti = cnt[i + 300];
			long long cntj = cnt[j + 300];
			res = res + cnti*cntj*(i - j)*(i - j);
		}
	}
	cout<< res << endl;
}
