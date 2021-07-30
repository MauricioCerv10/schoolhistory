#include <bits/stdc++.h>
using namespace std;

#define MAXIN 1005

vector<int> dfs_low(MAXIN);
vector<int> dfs_num(MAXIN);
vector<int> dfs_parent(MAXIN);
vector<vector<int>> grap(MAXIN);
int edge[MAXIN][MAXIN]; 
//vector<bool> articulation_vertex(MAXIN);
vector<pair<int,int>> ways;
//int dfsRoot;
//int rootChildren;
int dfsNumberCounter,n,m;
void bridges(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;	
	for(int j = 0; j<grap[u].size(); j++){
		int v = grap[u][j];
		if(v != dfs_parent[u] && edge[u][v] == 0){
			edge[u][v] = 1;
			edge[v][u] = 1;
                        pair<int,int> onew(u,v);
                        ways.push_back(onew);
			//cout<<u<<" "<<v<<"\n";
                }
		if(dfs_num[v] == -1){
			dfs_parent[v] = u;
			//if(u == dfsRoot) rootChildren++;;
                        //cout<<u<<" "<<v<<"\n";
                	
			bridges(v);

			/*
			//checking articulations points
			if(dfs_low[v] >= dfs_num[u])
				articulation_vertex[u] = true;
			*/

			//checking bridges
			if(dfs_low[v] > dfs_num[u]){
				pair<int,int> twow(v,u);
				ways.push_back(twow);
			}

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u],dfs_num[v]);
		}
	}
}

bool ordena(pair<int,int> x, pair<int,int> y){
	bool res;
	if(x.first < y.first) res = true;
	else if(x.first == y.first && x.second < y.second) res = true;
	else res = false;
	return res;
}

int main(){
	int caso = 1;
	while(cin>>n>>m,m || n){
		dfsNumberCounter = 0;
		for(int i = 0; i<=n; i++){ 
			dfs_num[i] = -1; dfs_parent[i] = 0;
			dfs_low[i] = 0;
			grap[i].erase(grap[i].begin(),grap[i].end());
			for(int j = 0; j<=n; j++) edge[i][j] =0;
		}
		ways.erase(ways.begin(),ways.end());
		
		int x,y;
		
		for(int i = 0; i<m; i++){
			cin>>x>>y;
			grap[x].push_back(y);
			grap[y].push_back(x);
		}
		cout<<caso<<"\n";
		cout<<"\n";
		//dfsRoot = 1; rootChildren = 0;
		bridges(1);
		sort(ways.begin(),ways.end(), ordena);
	
		for(int i = 0; i<ways.size(); i++)
			cout<<ways[i].first<<" "<<ways[i].second<<"\n";
		cout<<"#\n";
		caso++;

	}
}
