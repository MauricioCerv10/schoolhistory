#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grap(205);
vector<int> color(205);
bool isBipartite(){
	queue<int> q; q.push(0);
	color[0] = 0;
	bool isBipartite = true;
	while(!q.empty() && isBipartite){
		int u = q.front(); q.pop();
		for(int j = 0; j<grap[u].size(); j++){
			int v = grap[u][j];
			if(color[v] == -1){
				color[v] = 1 - color[u];
				q.push(v);
			}else if(color[v] == color[u]){
				isBipartite = false;
				break;
			}
		}
	}
	return isBipartite;
}

int main(){
	int n,l,s,d;
	while(cin>>n,n){
		for(int i = 0; i<n; i++) color[i] = -1;
		cin>>l;
		while(l--){
			cin>>s>>d;
			grap[s].push_back(d);
			grap[d].push_back(s);
		}
		if(isBipartite()) cout<<"BICOLORABLE.\n";
		else cout<<"NOT BICOLORABLE.\n";
		for(int i = 0; i<n; i++){
			grap[i].erase(grap[i].begin(),grap[i].end());
		}
	}
}
