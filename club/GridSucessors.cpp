#include <bits/stdc++.h>
using namespace std;

#define TAM 3
int moveX[] = {0,1,-1,0};
int moveY[] = {1,0,0,-1};

bool posible(int moveX,int moveY){
	if(moveX >= 0 && moveX < TAM && moveY >= 0 && moveY<TAM){return true;}
	return false;
} 
int transform(int grid[TAM][TAM]){
	for(int i = 0;i<TAM;i++){
		for(int j = 0; j<TAM;j++){
			int val = 0;
			for(int k = 0; k<4;k++){
				if(posible(moveX[k]+i,moveY[k]+j) == true){
					val = (val+grid[moveX[k]+i][moveY[k]+j])%2;
				}
			}
			grid[i][j] = val;
		}
	}
}
int main(){
	int n;
	cin>>n;
	cin.clear();
	cin.ignore();
	for(int c = 0; c<n;c++){
		string space;
		getline(cin,space);
		int grid[TAM][TAM];
		for(int i = 0;i<TAM;i++){
			string line;
			getline(cin,line);
			for(int j = 0; j<TAM;j++){
				grid[i][j] = line.at(j)-'0';
			}
		}
		int con = 1;
		for(int r = 0; r<100000;r++){
			int newGrid[TAM][TAM];
			for(int i = 0;i<TAM;i++){
                		for(int j = 0; j<TAM;j++){
                        		int val = 0;
                        		for(int k = 0; k<4;k++){
                                		if(posible(moveX[k]+i,moveY[k]+j) == true){
                                        		val = (val+grid[moveX[k]+i][moveY[k]+j])%2;
                                		}
                        		}
                        		newGrid[i][j] = val;
                		}
        		}
			bool finita = false;
			for(int i = 0;i<TAM;i++){
				for(int j =0;j<TAM;j++){
					if(grid[i][j] != newGrid[i][j]){
						finita = true;
					} 
				}
			}
			if(finita == false){
				con = con-2;
				cout<<con<<endl;
				break;
			}
			for(int i = 0;i<TAM;i++){
                                for(int j =0;j<TAM;j++){
                                        grid[i][j] = newGrid[i][j];
                                }
                        }

			con++;
		}
	}
	
	
}
