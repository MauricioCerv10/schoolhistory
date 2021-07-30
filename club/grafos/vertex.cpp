#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;

int vis[105];
vvi adjL(105);

void dfs(int u, int ini){
	vis[u] = 1;
	if(ini == 0){ ini = 1; vis[u] = 0;}
	for(int i = 0; i<adjL[u].size();i++)
		if(vis[adjL[u][i]] == 0) dfs(adjL[u][i],ini);
}

int main(){
	int n;
	while(cin>>n,n){
		int start;
		while(cin>>start,start){
			int node;
			while(cin>>node,node) adjL[start].push_back(node);
		}
		int q; cin>>q;
		for(int i = 0; i<q; i++){
			int qi; cin>>qi; vector<int> ans;
			dfs(qi,0);
			for(int j = 1; j<=n; j++){ if(vis[j] == 0) ans.push_back(j);}
			cout<<ans.size();
			for(int j = 0; j<ans.size(); j++) cout<<" "<<ans[j];
			cout<<"\n";
			for(int j = 1; j<=n; j++) vis[j] = 0;
		}
		for(int j = 1; j<=n; j++) adjL[j].erase(adjL[j].begin(),adjL[j].end());
	}
}
