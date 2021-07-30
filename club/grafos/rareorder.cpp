#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grap(30);
int vis[30];
vector<string> wds;
vector<int> ts;

void topsort(int u){
	vis[u] = 1;
	for(int i = 0; i<grap[u].size(); i++){
		if(vis[grap[u][i]] == 0)
			topsort(grap[u][i]);
	}
	ts.push_back(u);
}

int main(){
	bool prim = true;
	while(1){
		string line;
		cin>>line;
		if(line[0] == '#') break;
		wds.push_back(line);
		if(prim){ prim = false; continue;} 
		//cout<<wds[wds.size()-2][0]<<" "<<line[0]<<endl;
		if(wds[wds.size()-2][0] != line[0]) grap[wds[wds.size()-2][0] - 'A'].push_back(line[0] - 'A');
	}

	for(int i = 1; i < wds.size(); i++){
		if(wds[i][0] == wds[i-1][0]){
			int j = 1;
			while(j < wds[i].size() && j < wds[i-1].size() ){
				if(wds[i][j] != wds[i-1][j]){
					grap[wds[i-1][j] - 'A'].push_back(wds[i][j] - 'A');
					break;
				}
				j++;
			}
		}
	}

	topsort(wds[0][0] - 'A');

	for(int i = ts.size()-1; i >= 0; i--){
		char c = (char)(ts[i] + 'A');
		cout<<c;
	}
	cout<<"\n";

	/*
	for(int i = 0; i < grap.size(); i++){
		if(grap[i].size() != 0) cout<<i<<" ";
		for(int j = 0; j < grap[i].size() ; j++){
			cout<<grap[i][j]<<" ";
		}
		if(grap[i].size() != 0) cout<<"\n";
	}*/

	
}
