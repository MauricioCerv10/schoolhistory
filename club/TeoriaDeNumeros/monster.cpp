#include <bits/stdc++.h>
using namespace std;


int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if((a%2 == 0 && b%2 == 0) && ( (c%2 != 0 && d%2 == 0) || (c%2 == 0 && d%2 != 0) ) ){
		cout<<-1<<endl;
		return 0;
	}else if((c%2 == 0 && d%2 == 0) && ( (a%2 != 0 && b%2 == 0) || (a%2 == 0 && b%2 != 0) ) ){
		cout<<-1<<endl;
		return 0;
	}
	int res = 0, fres = 0;
	bool find = false;
	for(int i = 0; i<=10000; i++){
		res = b + a*i;
		for(int j = 0; j<=10000; j++){
			if(res == (d + c*j)){
				find = true; 
				break;
			}
		}
		if(find) break;
	}
	cout<<res<<endl;
}
