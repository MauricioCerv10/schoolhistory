#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin>>n,n){
		priority_queue<int,vector<int>,greater<int>> sort;
		while(n--){
			int num;
			cin>>num;
			sort.push(num);
		}

		int sum;
		int cost = 0;
		while(sort.size() >= 2){
			sum = sort.top();
			sort.pop();
			sum += sort.top();
			sort.pop();
			cost += sum;
			sort.push(sum); 
		} 
		cout<<cost<<"\n";
	}
}
