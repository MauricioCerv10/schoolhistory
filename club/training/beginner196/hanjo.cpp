#include <bits/stdc++.h>
using namespace std;

int grid[16][16];
int h,w;

long long ans;
bool isCompleted(){
	for(int i = 0; i<h; i++){
		for(int j = 0; j<w; j++){
			if( grid[i][j] == -1 ) return false;
		}
	}
	return true;
}
void dfs(int a, int b){
	if(a == 0 && b == 0){
		if(isCompleted()) ans++;
	}
	//cout<<"a " << a << " b " << b << endl;
	int i = 0, j = 0;
	bool findPos = false;
	for(int c = 0; c<h ; c++){
		for(int k = 0; k<w ; k++){
			if(grid[c][k] == -1){
				i = c;
				j = k;
				findPos = true;
				break;
			}
		}
		if(findPos) break;
	}
	//cout<<"i "<< i << " j "<< j << endl;
	if(!findPos) return;
	
	if( a>0 && j+1 < w && grid[i][j+1] == -1){
		grid[i][j] = 1;
		grid[i][j+1] = 1;
		dfs(a-1,b);
		grid[i][j] = -1;
		grid[i][j+1] = -1;
	}if( i+1 < h && a > 0 && grid[i+1][j] == -1){
		grid[i][j] = 1;
		grid[i+1][j] = 1;
		dfs(a-1,b);
		grid[i][j] = -1;
		grid[i+1][j] = -1;
	}if(b > 0 ){
		grid[i][j] = 1;
		dfs(a,b-1);
		grid[i][j] = -1;
	}
}

int main(){
	int a,b; cin>>h>>w>>a>>b;
	ans = 0;
	memset(grid, -1, sizeof(grid));
	dfs(a,b);
	cout<<ans<<endl;
}
