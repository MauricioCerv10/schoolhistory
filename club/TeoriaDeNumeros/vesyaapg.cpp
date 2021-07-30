#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 


int main(){
	int n;
	cin>>n;
	vector<int> res;
	for(int i = 2; i<=n; i++){
		if(isPrime(i)){
			for(int j = i; j<=n; j = j*i) res.push_back(j);
		}
	}
	cout<<res.size()<<endl;
	for(int i = 0; i<res.size(); i++)
		if(i != res.size()-1) cout<<res[i]<<" ";
		else cout<<res[i]<<endl;

}
