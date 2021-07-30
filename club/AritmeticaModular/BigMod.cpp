#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int expBinaria(int a,int b,int m){
        int res = 1;
        //a = a%m;
        while(b){
                if(b&1) res = (a*res)%m;
                b >>= 1;
                a = ((a%m)*(a%m))%m;
        }
        return res;
}


int main(){
	int b,p,m;
	while(cin>>b>>p>>m){
		int res = expBinaria(b,p,m);
		cout<<res<<endl;
	}
	return 0;
}
