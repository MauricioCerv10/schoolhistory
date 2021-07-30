#include <bits/stdc++.h>
using namespace std;
int n,k;
pair<int,int> numbersArranged(int a){
	int ini = 1000000000;
	int number = a;
	while(ini > a){
		ini = ini/10;
	}
	vector<int> digits;
	while(ini > 0){
		int d = a/ini;
		digits.push_back(d);
		a -= (d*ini);
		ini = ini/10;
	}
	//for(int i = 0; i<digits.size(); i++) cout<<digits[i]<<" ";
	//cout<<endl;
	sort(digits.begin(),digits.end());
	//for(int i = 0; i<digits.size(); i++) cout<<digits[i]<<" ";
	//cout<<endl;
	int desD = 0;
	int ascD = 0;
	int tenP = 10;
	for(int i = 0; i<digits.size(); i++){
		int nNum = ascD * tenP;
		ascD =  nNum + digits[i]; 
	}
	tenP = 10;
	for(int i = digits.size()-1; i >= 0 ; i--){
		desD = (desD * tenP) + digits[i];  
	}

	//cout<<"des : "<<desD<<" asc : "<<ascD<<endl;
	return make_pair(ascD,desD); 
}

int fk(int ai){
	int res = ai;
	for(int i = 1; i<=k; i++){
		pair<int,int> numbersArr = numbersArranged(res);
		int asc = numbersArr.first;
		int des = numbersArr.second;
		res = des - asc;
	}
	return res;
}


int main(){
	cin>>n>>k;
	cout<<fk(n)<<endl;
}
