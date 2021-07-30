#include <bits/stdc++.h>
using namespace std;
int main(){
	long int sz,p;
	while(cin>>sz>>p,(sz || p)){
		int ini = 1, fin = sz;
		int c = 0;
		while(ini<fin){
			int mid = (ini+fin)>>1;
			if(pow(2*mid-1,2) < p){
				ini = mid+1;
			}else{
				fin = mid;
			}
		}
		unsigned long long int con = pow(2*ini-1,2);
		unsigned long long int n = 2*ini-1;
		unsigned long long int fila = (sz/2)+ini;
		unsigned long long int col = fila;
		unsigned long long int val = con;
		for(int i = 0; i < (4*n-4);i++){
			if(p == con){
				break;
			}
			if(con <= val && con > val-n ){
				if(con == val-n+1){
					col--;
				}else{
					fila--;
				}
				
			}else if(con <= val-n && con >= val-n*2+2){
				if(con == val-n*2+2){
					fila++;
				}else{
					col--;
				}
			}else if(con < val-n*2+2 && con >= val-n*3+3){
				if(con == val-n*3+3){
					col++;
				}else{
					fila++;
				}
			}else{
				col++;
			}
			con--;
		}
		cout<<"Line = "<<fila<<", column = "<<col<<".\n";
	}
}
