#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

typedef vector<int> vi;
typedef long long ll;

#define MAXN 7000000
  
// stores smallest prime factor for every number 
int spf[MAXN]; 
  
// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (int j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
  
// A O(log n) function returning primefactorization 
// by dividing by smallest prime factor at every step 
int ret[20];
int primeFactors(int x) 
{ 
   // vector<int> ret; 
    int idx = 0;
    while (x != 1) 
    { 
	if(idx > 3)return 0;
	ret[idx++] = spf[x] ; 
  //      ret.push_back(spf[x]); 
        x = x / spf[x]; 
	
    }
    if(idx == 2 && ret[0] != ret[1]) return 1; 
    if(idx == 3 && ret[0] == ret[1] && ret[0] == ret[2])return 1;
	return 0;
} 


int n;
int main(){
	optimizar_io;
	sieve();
	cin >> n;
        int counter = 0,act= 6;
        while(1){
                if(primeFactors(act))counter++;
                if(counter == n){
                        cout << act << '\n';
                        break;
                }
                act++;
        }
	return 0;
}
