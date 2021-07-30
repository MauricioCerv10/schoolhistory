#include <bits/stdc++.h>
using namespace std;

#define MAXIN 10005

vector<vector<int>> grap(MAXIN);

vector<int> num(MAXIN);
vector<int> low(MAXIN);
vector<int> S(MAXIN);
vector<int> vis(MAXIN);
map<string,int> nodes;

int dfsC,numSCC;

void sCC(int u){
	low[u] = num[u] = dfsC++;
	S.push_back(u);
	vis[u] = 1;
	for(int j = 0; j<grap[u].size();j++){ 
		int v = grap[u][j];
		if(num[v] == -1)
			sCC(v);
		
		if(vis[v])
			low[u] = min(low[u],low[v]); 
	}

	if(low[u] == num[u]){
		++numSCC;
		while(1){
			int v = S.back(); S.pop_back(); vis[v] = 0;
			//cout<<" "<<v;
			if(u == v) break;
		}
		//cout<<"\n";
	}
}

void restart(int n){
	numSCC = 0;
	for(int i = 0; i<=n;i++){ 
		num[i] = -1; low[i] = 0; vis[i] = 0;
		grap[i].erase(grap[i].begin(),grap[i].end());
	}
}

int main(){
	int p,t;
	while(cin>>p>>t,p||t){
		restart(p);
		string us,un,vs,vn;
		for(int i = 0; i<p; i++){
			cin>>us>>un;
			us += un;
			nodes[us] = i;
		}
		while(t--){
			cin>>us>>un;
			us += un;
			cin>>vs>>vn;
			vs += vn;
			grap[nodes[us]].push_back(nodes[vs]);
		}

		/*cout<<"\n";
		for(int i = 0; i<p; i++){
			cout<<i<<" ";
			for(int j = 0; j<grap[i].size(); j++){
				cout<<grap[i][j]<<" ";
			}
			 cout<<"\n";
		}*/
		dfsC = 0;
		for(int i = 0; i<p;i++){
			if(num[i] == -1){ sCC(i);}
		}
		cout<<numSCC<<endl;
	}
}
