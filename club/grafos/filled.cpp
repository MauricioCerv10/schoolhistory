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
