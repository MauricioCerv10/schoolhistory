#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e7;

int divs,distr,distl;

// Function to count divisors 
int divisores(int n) 
{ 
   	int con = 0;
	for(int i = 1; i*i<=n;i++){
		if(n%i == 0) con += 2;
		if(i*i == n) con--;
	}
	return con;
     
} 
  
int divisorLeft(int n){
	if(n == 1) return -1;
	for(int i = n-1;i>0;i--){
		distl++;
		if(divisores(i) == divs) return i;
	}
	return -1;
}

int divisorRight(int n){
	if(n == 1) return 2; 
        for(int i = n+1;i<maxn;i++){
		distr++;
                if(divisores(i) == divs) return i;
        }
        return -1;
}

int main(){
	int n;
	cin>>n;
	divs = divisores(n);
	int divr = divisorRight(n);
	int divl = divisorLeft(n);
	
	if(distl <= distr && divl != -1) cout<<divl<<"\n";
	else cout<<divr<<"\n";
	
}
