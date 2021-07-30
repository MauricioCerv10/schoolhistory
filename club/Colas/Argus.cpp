#include <bits/stdc++.h>
using namespace std;

int main(){
	string reg;
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> queries;
	while(true){
		cin>>reg;
		if(reg.compare("#") == 0) break;
		int qnum,period;
		cin>>qnum>>period;
		queries.push(pair<int,pair<int,int>>(period,pair<int,int>(qnum,period)));
	}
	int k;
	cin>>k;
	while(k--){
		pair<int,pair<int,int>> query = queries.top();
		cout<<query.second.first<<"\n";
		queries.pop();
		query.first += query.second.second;
		queries.push(query);
	}
}
