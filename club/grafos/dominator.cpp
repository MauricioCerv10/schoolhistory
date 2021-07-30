#include <bits/stdc++.h>
using namespace std;

int adj[105][105];
int vis[105];
int domi[105][105];
int n;


void dfs(int u, int block){
	vis[u] = 1;
	if(block == 0)
		 for(int i = 0; i < n; i++){
                        if(vis[i] != 1 && adj[u][i] == 1){ domi[block][i] = 1;domi[i][i] = 1; dfs(i,block);}
                }
	else if(block != u)
		for(int i = 0; i < n; i++){
			if(vis[i] != 1 && adj[u][i] == 1){ dfs(i,block);}
		}
}

int main(){
	int t;
	cin>>t;
	int caso = 1;
	while(t--){
		cin>>n;
		for(int i = 0; i<n; i++) 
			for(int j = 0; j<n ; j++){ cin>>adj[i][j]; domi[i][j] = 0;}
		
		bool conec = false;
		for(int i = 0; i<n; i++) if(adj[0][i] == 1){ conec = true; break;}
		domi[0][0] = 1;
		if(conec)
			for(int i = 0; i<n ; i++){
				dfs(0,i);
				for(int j = 0; j<n; j++){
					if(domi[0][j] == 1 && vis[j] == 0) domi[i][j] = 1;
				}
				for(int j = 0; j<n; j++) vis[j] = 0;
			}
		cout<<"Case "<<caso<<":\n";
		for(int i = 0; i<n ; i++){
			for(int j = 0; j<2*n+1;j++) 
				if(j == 0) cout<<"+"; 
				else if(j == 2*n) cout<<"+";
				else cout<<"-";
			cout<<"\n";
			for(int j = 0; j<n ; j++){ 
				cout<<"|"; 
				if(domi[i][j] == 1 ) cout<<"Y";
				else cout<<"N";
			}
			cout<<"|\n";
		}
		for(int j = 0; j<2*n+1;j++) 
                        if(j == 0) cout<<"+"; 
                        else if(j == 2*n) cout<<"+\n";
                        else cout<<"-";
		caso++;
	}
}
