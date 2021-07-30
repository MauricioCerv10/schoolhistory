#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
  	string x,y;
	int m, n;
	int t;
	cin>>t;
	while(t--){
		cin>>m>>n>>x>>y; 
   
   

		int lsc[m+1][n+1];

        	/* Calcula las subsecuencias máximas en L[m+1][n+1] en la forma bottonup.*/
        	for (int i=0; i<=m; i++){ 
                	for (int j=0; j<=n; j++) { 
                        	if (i == 0 || j == 0) 
                                	lsc[i][j] = 0; 
   
                        	else if (x.at(i-1) == y.at(j-1)) 
                                	lsc[i][j] = lsc[i-1][j-1] + 1; 
   
                        	else
                                	lsc[i][j] = max(lsc[i-1][j], lsc[i][j-1]); 
                	} 
        	} 

   
  		cout<<lsc[m][n]<<endl;
	} 
  
  	return 0; 
} 
