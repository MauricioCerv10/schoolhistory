#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int x = 0, i = 0;
	priority_queue<int> nums;
	while((1<<i) <= n){
		x = 1<<i;
		if((n&x) == x) nums.push(x);
		i++;
	}
	if(nums.size() > k){ cout<<"NO\n"; return 0;}
	while(nums.top() != 1){
		if(nums.size() == k) break;
		int last = nums.top();
		nums.pop();
		int mid = last/2;
		nums.push(mid);
		nums.push(mid);
	}
	if(nums.size() == k){
		cout<<"YES\n";
		while(!nums.empty()){
			if(nums.size() == 1 ) cout<<nums.top()<<"\n";
			else cout<<nums.top()<<" ";
			nums.pop();
		}
	}else cout<<"NO\n";
}
