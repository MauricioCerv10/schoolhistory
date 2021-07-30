#include <bits/stdc++.h>
using namespace std;

bool func(int x, int y){
	return x>y;
}

int mes[12];
int main(){
	int k;cin>>k;
	for(int i = 0; i<12;i++) cin>>mes[i];
	sort(mes,mes+12,func);
	int count = 0;
	for(int i = 0; i<12; i++){
		if(k <= 0) break;
		k -= mes[i];
		count++;
	}
	if(k > 0) cout<<-1<<endl;
	else cout<<count<<endl;
}
