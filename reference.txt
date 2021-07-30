#include <bits/stdc++.h>
using namespace std;

vector< pair< int, pair<int,int> > > EList;

class UnionFind{
	private: vector<int> p;
	private: vector<int> rank;

	public: UnionFind(int N){
		rank.assign(N,0);
		p.assign(N,0);
		for(int i = 0; i<N; i++){
			p[i] = i;
		}
	}

	int findSet(int i){
		return (p[i] == i) ? i: (p[i] = findSet(p[i]));
	}

	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j){
		if(!isSame(i,j)){
			int x = findSet(i), y = findSet(j);
			if( rank[x] > rank[y] ) p[y] = x;
			else{
				p[x] = y;
				if( rank[x] == rank[y]) rank[y]++;
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	for(int k = 1; k<=t; k++){
		int n,m,a;
		cin>>n>>m>>a;
		int x,y,c;
		for(int i = 0; i<m;i++){
			cin>>x>>y>>c;
			pair<int,int> e(x,y);
			EList.push_back(make_pair(c,e));
		}
		sort(EList.begin(), EList.end());
		int mst_cost = 0;
		UnionFind UF(n);
		for(int i = 0; i<m; i++){
			pair<int, pair<int,int> > front = EList[i];
			if(!UF.isSameSet(front.second.first, front.second)){
				mst_cost += front.first;
				UF.unionSet(front.second.first,front.second.second);
			}
		}
	}
	cout<<"Costo "<<mst_cost<<endl;
}



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



#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define V 100000
int s = 0;

vector< vector< pair<int,int> > > AdjList;

int main(){
	vector<int> dist(V,INF);
	priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; 
	pq.push(pair<int,int>(0,s));
	
	while(!pq.empty() ){
		pair<int,int> front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if( d > dist[u] ) continue;
		for(int j = 0; j < (int)AdjList[u].size(); j++){
			pair<int,int> v = AdjList[u][j];
			if(dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;
				pq.push(pair<int,int>(dist[v.first],v.first));
			}
		}
	}
}

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






#include <bits/stdc++.h>
using namespace std;

int x,y;
char grap[55][55];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0 , 1, 0,-1};

bool ordena(pair<char,int> x, pair<char,int> y){
	return x.second > y.second || (x.second == y.second && x.first < y.first );
}

int floodfill(int r, int c, char c1,char c2){
	if(r < 0 || r >= x || c < 0 || c >= y) return 0;
	if(grap[r][c] != c1) return 0;
	int ans = 1;
	grap[r][c] = c2;
	for(int i = 0; i<4; i++){
		ans += floodfill(r + dr[i],c + dc[i],c1,c2);
	}
	return ans;
}

int main(){
	int p = 1;
	while(cin>>x>>y, x || y){
		vector<pair<char,int>> ans;
		for(int i = 0; i < x; i++) 
			for(int j = 0; j < y; j++) cin>>grap[i][j];

		for(int i = 0; i < x; i++)
			for(int j = 0; j<y; j++)
				if(grap[i][j] != '.'){
					pair<char,int> cc;
					cc.first = grap[i][j];
					int res = floodfill(i,j,grap[i][j],'.');
					cc.second = res;
					ans.push_back(cc);
				} 
		sort(ans.begin(), ans.end(), ordena);
		cout<<"Problem "<<p<<":\n";
		for(int i = 0; i<ans.size(); i++){
			cout<<ans[i].first<<" "<<ans[i].second<<"\n";
		}
		p++;
	}
}





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

#include <bits/stdc++.h>
using namespace std;

vector< pair< int, pair<int,int> > > EList;

class UnionFind{
	private: vector<int> p;
	private: vector<int> rank;

	public: UnionFind(int N){
		rank.assign(N,0);
		p.assign(N,0);
		for(int i = 0; i<N; i++) 
			 p[i] = i;
	}

	int findSet(int i){
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j){
		if(!isSameSet(i,j)){
			int x = findSet(i), y = findSet(j);
			if( rank[x] > rank[y] ) p[y] = x;
			else{
				p[x] = y;
				if(rank[x] == rank[y]) rank[y]++;
			}
		}
	}
};



int main(){
	int V,E,w,u,v;
	cin>>V>>E;
	for(int i = 0;  i<E; i++){
		cin>>u>>v>>w;
		pair<int,int> e(u,v);
		EList.push_back(make_pair(w,e));
	}
	sort(EList.begin(), EList.end());

	int mst_cost = 0;
	UnionFind UF(V);
	for(int i = 0; i<E; i++){
		pair<int, pair<int,int>> front = EList[i];
		if(!UF.isSameSet(front.second.first, front.second.second)){
			mst_cost += front.first;
			UF.unionSet(front.second.first, front.second.second);
		}
	}
	cout<<"Costo "<<mst_cost<<endl;
}



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








