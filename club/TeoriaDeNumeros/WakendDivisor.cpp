#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef long long ll;

set<int> factors;

void primeFactors(int n, int a[]){
        // Print the number of 2s that divide n 
    	while (n%2 == 0) 
    	{ 
       		factors.insert(2); 
        	n = n/2; 
    	} 
  
    	// n must be odd at this point.  So we can skip  
    	// one element (Note i = i +2) 
    	for (int i = 3; i <= sqrt(n); i = i+2) 
    	{ 
        	// While i divides n, print i and divide n 
        	while (n%i == 0) 
        	{ 
            		factors.insert(i); 
            		n = n/i; 
        	} 
    	} 
  
    	// This condition is to handle the case when n  
    	// is a prime number greater than 2 
    	if (n > 2) 
        	factors.insert(n);
}

int main(){
	int n;
	cin>>n;
	vector<pair<int,int>> nums;
	for(int i = 0; i<n; i++){
		ll a, b;
		cin>>a>>b;
		pair<int,int> par;
		par.first = a;
		par.second = b;
		nums.push_back(par);
	}

	vector<int> ans;
	primeFactors(nums[0].first);
	primeFactors(nums[0].second);

	for(set<int>::iterator it=factors.begin(); it!=factors.end(); it++){
		bool is = true;
		for(int j = 0; j<n ; j++){
			if(nums[j].first%(*it) != 0 && nums[j].second%(*it) != 0) { is = false; break;}
		}
		if(is) { ans.push_back(*it); }
	}

	if(ans.size() == 0) cout<<"-1"<<endl;
	else cout<<ans[0]<<"\n";
}
