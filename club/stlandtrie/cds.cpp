#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
 
lli N,M;

int main(){
	while(cin>>N>>M,(N||M)){
		int con = 0;
		map<lli,int> cub;
		while(N--){
			lli cd;
			cin>>cd;
			cub[cd] = 1;
		}
		while(M--){
                        lli cd;
                        cin>>cd;
                        cub[cd]++;
                        if(cub[cd] == 2) con++;
                }
		cout<<con<<endl;
	}
}
