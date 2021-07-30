#include <bits/stdc++.h>
using namespace std;

long long int getNumber(string num){
	long long int res = 0;
	for(int i = 0; i<num.size(); i++){
		res = (long long int)(res * 10) + (long long int)(num[i] - '0');
	}
	return res;
}

int main(){
	string number; cin>>number;
	string intNum = "";
	for(int i = 0; i<number.size(); i++){
		if(number[i] == '.'){ break; }
		intNum += number[i];
	}
	if(intNum.size() == 0) cout<<"0\n";
	else cout<<intNum<<"\n";
	//long long int ans = getNumber(intNum);
	//cout<<ans<<"\n";
}
