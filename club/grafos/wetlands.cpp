#include <bits/stdc++.h>
using namespace std;

char grap[105][105];
int n,m;
int dr[] = {-1,-1, 0, 1, 1, 1, 0, -1};
int dc[] = {0 , 1, 1, 1, 0,-1, -1, -1};
int caso; 

int floodfill(int r, int c, char c1, char c2){
	if(r < 1 || r > n || c < 1 || c > m) return 0;
	if( grap[r][c] != c1) return 0;
	int ans = 1;
	grap[r][c] = c2;
	for(int i = 0; i<8; i++){
		ans += floodfill(r + dr[i],c + dc[i],c1,c2);
	}
	return ans;
}

int main(){
	int t; cin>>t;
	cin.clear();
	cin.ignore();
	bool primero = true;
	while(t--){
		if(caso++) cout<<"\n";
		string line;
		n = 0;
		if(primero){ getline(cin,line); primero = false;}
		while(getline(cin,line)){
			if(line == "") break;
			if(line[0] == 'W' || line[0] == 'L'){
				m = line.length();
				for(int i = 0; i<line.length();i++){
					grap[n+1][i+1] = line[i];
				}
				n++;
			}else{
				
				int x = line[0] - '0';
				int y;
				if(line[1] != ' '){
					x = x*10 + line[1] - '0';
					y = line[3] - '0';
					if(line.length() == 5) y = y*10 + line[4] - '0';
				}else{
					y = line[2] - '0';
					if(line.length() == 4) y = y*10 + line[3] - '0';
				}
				int ans = floodfill(x,y,'W','.');
				cout<<ans<<"\n";
				for(int i = 1; i<=n; i++)
					for(int j = 1; j<=m; j++)
						if(grap[i][j] == '.') grap[i][j] = 'W';
			}
		}
	}
}
