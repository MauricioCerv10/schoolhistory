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
