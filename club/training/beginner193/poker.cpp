#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int cards[10];
ll totalVal(vector<int> nums){
	ll res = 0;
	for(int i = 1; i <= 9; i++){
		int apps = 0;
		for(int j = 0; j<nums.size(); j++) if(nums[j] == i) apps++;
		res += i * pow(10,apps);
	}
	
	return res;
}
int main(){
	int k;
	string s,t;
	cin>>k>>s>>t;
	vector<int> numsTaka;
	vector<int> numsAoki;
	for(int i = 0; i<4; i++){
		int num = s[i] - '0';
		//cout<<"num = "<< num << endl;
		numsTaka.push_back(num);
		cards[num] += 1; 
	}

	for(int i = 0; i<4; i++){
		int num = t[i] - '0';
                //cout<<"num = "<< num << endl;
                numsAoki.push_back(num);
                cards[num] += 1; 
	}
	ll wins = 0;
	for(int i = 1; i <= 9; i++){
		if(cards[i] == k) continue;
		numsTaka.push_back(i);
		ll taka = totalVal(numsTaka);
		numsTaka.pop_back();
		for(int j = 1; j<=9; j++){
			if(cards[j] == k) continue;
			numsAoki.push_back(j);
			ll aoki =  totalVal(numsAoki);
			numsAoki.pop_back();
			ll posis = 0;
			if(taka > aoki){
				//cout<< i << " " << j << endl; 
				if(i != j)
					posis = (ll)(k - cards[i]) * (ll)(k - cards[j]);
				else 
					posis = (ll)(k - cards[i]) * (ll)(k - cards[i] - 1);

				//cout << posis << endl;

			}
			wins += posis;
		}
	}
	//cout<<wins<<endl;
	ll fiCardpos = 9*k - 8;
	ll seCardpos = 9*k - 9;
	//cout<< fiCardpos << endl;
	//cout<< seCardpos << endl;
	ll posibi =  fiCardpos * seCardpos;
	//cout<< posibi << endl;
	
	double res = (double)wins/posibi;
	cout<<res<<endl;
}
