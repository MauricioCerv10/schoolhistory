#include <bits/stdc++.h>
using namespace std;

int main(){
	int cases;
	cin>>cases;
	while(cases--){
		int n;
		cin>>n;
		set<int> pack;
		int maxS = 0;
		while(n--){
			int num;
			cin>>num;
			if( pack.find(num) == pack.end() ) pack.insert(num);
			else if( maxS<pack.size() ){
				maxS = pack.size();
				pack.clear();
				pack.insert(num);
			}else{ 
				pack.clear();
				pack.insert(num);
			}
		}
		if( maxS<pack.size() ) maxS = pack.size();
		
		cout<<maxS<<endl;
	}
}
