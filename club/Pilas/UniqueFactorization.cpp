#include <bits/stdc++.h>
using namespace std;
int main(){
	while(cin>>N,N){
		int tmp = N;
		int max = 0;
		para = false;
		vector<int> nums;
		for(int i = 2;i<N;i++){
 			while( tmp%i == 0){
				tmp = tmp/i;
				max++;
				nums.push_back(i);
			}
		}
		max = pow(2,max-1)-1;
		cout<<max<<"\n";
	}
}
