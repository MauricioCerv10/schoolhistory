#include <bits/stdc++.h>
using namespace std;
char grid[405][405];
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				cin>>grid[i][j];
				if(grid[i][j] == '*'){
					if(x1 == -1){
						x1 = j;
						y1 = i;
					}else{
						x2 = j;
						y2 = i;
					}
				}
			}
		}

		if(x1 == x2){
	//		cout<<"mal"<<endl;
			if(x1 + 1 < n){
				grid[y1][x1+1] = '*';
				grid[y2][x2+1] = '*';
			}else{
				grid[y1][x1-1] = '*';
				grid[y2][x2-1] = '*';
			}
		}else if(y1 == y2){
			if(y1 + 1 < n){ 
                                grid[y1 + 1][x1] = '*';
                                grid[y2 + 1][x2] = '*';
                        }else{ 
                                grid[y1 - 1][x1] = '*';
                                grid[y2 - 1][x2] = '*';
                        }
		}else{
			grid[y1][x2] = '*';
			grid[y2][x1] = '*'; 
		}
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				cout<<grid[i][j];
			}
			cout<<"\n";
		}
	//	cout<<"------------------------------------------------------------\n";
	}

}
