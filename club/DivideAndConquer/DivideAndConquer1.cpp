#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
Retorna el mayor de dos enteros
*/ 
ll max(ll a, ll b) { return (a > b)? a : b; } 
/*
Retorna el mayor  de tres enteros
*/ 
ll max(ll a, ll b, ll c) { return max(max(a, b), c); } 
  
/*
Retorna la suma de dos subrreglos contiguos, en caso de que la suma máxima 
se encuentre en ellos dos
*/
ll comSum(ll arr[], ll l, ll m, ll h){ 
    	ll sum = 0; 
    	ll left_sum = INT_MIN; 
    	for (int i = m; i >= l; i--) { 
        	sum = sum + arr[i]; 
 		if (sum > left_sum) left_sum = sum; 
    	} 

    	sum = 0; 
    	ll right_sum = INT_MIN; 
    	for (int i = m+1; i <= h; i++){ 
        	sum = sum + arr[i]; 
        	if (sum > right_sum) right_sum = sum; 
    	} 
    	return left_sum + right_sum; 
} 
  
/*
Retorna la suma máxima de un  subarreglo
*/ 
ll sumMax(ll arr[], ll l, ll h) {  
   	if (l == h) 
     		return arr[l]; 
   	ll m = (l + h)/2; 
  	return max(sumMax(arr, l, m), 
              	sumMax(arr, m+1, h), 
             	comSum(arr, l, m, h)); 
}

int main() { 
	int n;
	cin>>n;
   	ll arr[n];
	for(int i = 0; i<n; i++) cin>>arr[i]; 
   	ll max_sum = sumMax(arr, 0, n-1); 
   	cout<<max_sum<<"\n";
   	return 0; 
} 
