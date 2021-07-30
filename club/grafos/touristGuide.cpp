#include <bits/stdc++.h>
using namespace std;

#define MAXIN 105

vector<vector<int>> grap(MAXIN);
map<string,int> nodes;
string id[MAXIN];
vector<int> dfs_low(MAXIN);
vector<int> dfs_num(MAXIN);
vector<int> dfs_parent(MAXIN);
vector<bool> articulation_vertex(MAXIN);

int dfsRoot,rootChildren,dfsCount,v,e;

void articulation(int u){ 
	dfs_low[u] = dfs_num[u] = dfsCount++;
	for(int j = 0; j<grap[u].size(); j++){
		int v = grap[u][j];
		if(dfs_num[v] == -1){
			dfs_parent[v] = u;
			if(u == dfsRoot) rootChildren++;
			articulation(v);
			if(dfs_low[v] >= dfs_num[u]){
				articulation_vertex[u] = true;
			}
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
		}else if(v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u],dfs_num[v]);
		}
	}
}

int main(){
	int map = 1;
	int caso = 0;
	while(cin>>v,v){
		if(caso++) cout<<"\n";
		for(int i = 0; i<v; i++){
			grap[i].erase(grap[i].begin(),grap[i].end());
			dfs_num[i] = -1;dfs_parent[i] = 0;
			dfs_low[i] = 0;
			articulation_vertex[i] = false;
		}
		string node;
		dfsCount = 0;
		for(int i = 0; i<v; i++){
			cin>>node;
			nodes[node] = i;
			id[i] = node;
		}
		cin>>e;
		while(e--){
			string s1,s2;
			cin>>s1>>s2;
			grap[nodes[s1]].push_back(nodes[s2]);
			grap[nodes[s2]].push_back(nodes[s1]);
		}
		for(int i = 0; i<v; i++){
			if(dfs_num[i] == -1){
				rootChildren = 0; dfsRoot = i;
				articulation(i);
				articulation_vertex[dfsRoot] = (rootChildren > 1);
			}
		}
		/*cout<<endl<<endl;
		for(int i = 0; i<v; i++){
			for(int j = 0; j<grap[i].size(); j++){
				cout<<grap[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl<<endl;*/
		vector<string> ans;
		for(int i = 0; i<v; i++){
			if(articulation_vertex[i]) 
				ans.push_back(id[i]);
		}
		sort(ans.begin(),ans.end());
		cout<<"City map #"<<map<<": "<<ans.size()<<" camera(s) found\n";
		for(int i = 0; i<ans.size();i++){
			cout<<ans[i]<<endl;
		}
		map++;
		nodes.clear();
	}
}
