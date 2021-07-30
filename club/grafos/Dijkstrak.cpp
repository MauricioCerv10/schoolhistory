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
