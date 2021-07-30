#include <bits/stdc++.h>
using namespace std;

int Ai[1005];
int Bi[1005];

int main(){
	int n; cin>>n;
	for(int i = 0; i<n; i++){
		cin>>Ai[i]>>Bi[i];
	}
	int totalTime = 1000000;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			int minVal = 0;
			if(i == j) minVal = Ai[i] + Bi[j];
			else minVal = max(Ai[i], Bi[j]);
			totalTime = min(totalTime,minVal);
		}
	}

	cout<<totalTime<<endl;
}
