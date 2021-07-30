#include <bits/stdc++.h>
using namespace std;
int caso;
int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int cases;
	cin>>cases;
	cin.clear();
	cin.ignore();
	string space;
	getline(cin,space);
	while(cases--){
		if(caso++) cout<<"\n";
		string word;
		map<string,int> trees;
		int total = 0;

		while(getline(cin,word)){
			if(word.compare("") == 0) break;
			trees[word]++;
			total++;
		}
		
		for(map<string,int>::iterator it = trees.begin();it != trees.end();it++){
			float per = it->second*100.0/total;
			cout<<it->first<<" "<<fixed<<setprecision(4)<<per<<"\n"; 
		}
		
	}
}

