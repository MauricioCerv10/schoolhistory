#include <bits/stdc++.h>
using namespace std;
char grid[15][15];

int numOfV(int x, int y){
	if(grid[x][y] != '#') return 0;
	int vertexs = 0;
	if(grid[x][y-1] != '#' && grid[x+1][y] != '#' && grid[x-1][y] != '#'){ vertexs += 2; /*cout<<"1"<<endl;*/}
	if(grid[x][y-1] != '#' && grid[x][y+1] != '#' && grid[x-1][y] != '#') { vertexs += 2;}// cout<<"2"<<endl;} 
	if(grid[x-1][y] != '#' && grid[x+1][y] != '#' && grid[x][y+1] != '#') { vertexs += 2;}// cout<<"3"<<endl;}
	if(grid[x][y-1] != '#' && grid[x][y+1] != '#' && grid[x+1][y] != '#') { vertexs += 2;}// cout<<"4"<<endl;}

	if(grid[x+1][y] == '#' && grid[x][y+1] == '#' && grid[x+1][y+1] != '#'){ vertexs++;}// cout<<"5"<<endl;}
	if(grid[x-1][y] == '#' && grid[x][y+1] == '#' && grid[x-1][y+1] != '#'){ vertexs++;}// cout<<"6"<<endl;}

	if(grid[x][y-1] == '#' && grid[x+1][y] == '#' && grid[x+1][y-1] != '#'){ vertexs++;}// cout<<"7"<<endl;}
	
	if(grid[x-1][y] == '#' && grid[x][y-1] == '#' && grid[x-1][y-1] != '#'){ vertexs++;}// cout<<"8"<<endl;}
	//if(grid[x+1][y] == '#' && grid[x][y-1] == '#' && grid[x+1][y-1] != '#'){ vertexs++; cout<<"9"<<endl;}

	if(grid[x+1][y] == '#' && grid[x][y+1] == '#' && grid[x-1][y] != '#' && grid[x][y-1] != '#'){ vertexs++;}//  cout<<"9"<<endl;}
	if(grid[x+1][y] == '#' && grid[x][y-1] == '#' && grid[x-1][y] != '#' && grid[x][y+1] != '#'){ vertexs++;}//  cout<<"10"<<endl;}
	if(grid[x][y-1] == '#' && grid[x-1][y] == '#' && grid[x+1][y] != '#' && grid[x][y+1] != '#'){ vertexs++;}//  cout<<"11"<<endl;}
	if(grid[x-1][y] == '#' && grid[x][y+1] == '#' && grid[x+1][y] != '#' && grid[x][y-1] != '#'){ vertexs++;}//  cout<<"12"<<endl;}

	return vertexs;
}

int main(){
	int n,w; cin>>n>>w;
	int vertexs = 0;
	int catCounter = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<w; j++){
			cin>>grid[i][j];
			if(grid[i][j] == '#') catCounter++;
		}
	}

	for(int i = 1; i<n-1; i++){
		for(int j = 1; j<w-1; j++){
			int noV = numOfV(i,j);
			//cout<<"i = "<<i<< " j = "<<j<<" v = "<< noV << endl;
			vertexs += noV;
		}
	}
	if(catCounter == 1) cout<<"4\n";
	else cout<<vertexs<<"\n";
}
