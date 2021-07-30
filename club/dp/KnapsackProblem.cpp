#include<iostream> 
using namespace std;

  
int main() {
	int S,n;
	cin>>n>>S;
    	int val[n]; 
   	int ws[n];

	for(int i = 0; i<n;i++) cin>>val[i]>>ws[i];
	 
        int mv[n+1][S+1]; 
  
        // Construye la tabla de la forma Botton up 
        for (int i = 0; i <= n; i++){ 
                for (int j = 0; j <= S; j++) { 
                        if (i==0 || j==0) 
                                mv[i][j] = 0; 
                        else if (ws[i-1] <= j) 
                                mv[i][j] = max(val[i-1] + mv[i-1][j-ws[i-1]],  mv[i-1][j]); 
                        else
                                mv[i][j] = mv[i-1][j]; 
                } 
        } 

	
    	cout<<mv[n][S]<<"\n"; 
    	return 0; 
} 


