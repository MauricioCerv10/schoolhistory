#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
pair<int,int> points[200005];
ll xCoef[200005][3];
ll yCoef[200005][3];
 
pair<ll, ll> evaluate(int x, int y, int opIdx){
	pair<ll, ll> res;
	res.first  = x * xCoef[opIdx][0] + y * xCoef[opIdx][1] + xCoef[opIdx][2];
	res.second = x * yCoef[opIdx][0] + y * yCoef[opIdx][1] + yCoef[opIdx][2];
	return res;
}
int main(){
	int n; cin>>n;
	for(int i = 1; i<=n; i++){
		cin>>points[i].first>>points[i].second;
	}
	int m; cin>>m;
	xCoef[0][0] = 1; xCoef[0][1] = 0; xCoef[0][2] = 0;
	yCoef[0][0] = 0; yCoef[0][1] = 1; yCoef[0][2] = 0;
	for(int i = 1; i<=m; i++){
		int nOp,p; cin>>nOp;
		if(nOp == 1){
			xCoef[i][0] = yCoef[i-1][0];
			xCoef[i][1] = yCoef[i-1][1];
			xCoef[i][2] = yCoef[i-1][2];

			yCoef[i][0] = (-1) * xCoef[i-1][0];
			yCoef[i][1] = (-1) * xCoef[i-1][1];
			yCoef[i][2] = (-1) * xCoef[i-1][2];
		}else if(nOp == 2){
			xCoef[i][0] = (-1) * yCoef[i-1][0];
			xCoef[i][1] = (-1) * yCoef[i-1][1];
			xCoef[i][2] = (-1) * yCoef[i-1][2];

			yCoef[i][0] = xCoef[i-1][0];
			yCoef[i][1] = xCoef[i-1][1];
			yCoef[i][2] = xCoef[i-1][2];
		}else if(nOp == 3){
			cin>>p;
			xCoef[i][0] = (-1) * xCoef[i-1][0];
			xCoef[i][1] = (-1) * xCoef[i-1][1];
			xCoef[i][2] = (2 * p) - xCoef[i-1][2];

			yCoef[i][0] = yCoef[i-1][0];
			yCoef[i][1] = yCoef[i-1][1];
			yCoef[i][2] = yCoef[i-1][2];
		}else if(nOp == 4){
			cin>>p;
			xCoef[i][0] = xCoef[i-1][0];
			xCoef[i][1] = xCoef[i-1][1];
			xCoef[i][2] = xCoef[i-1][2];

			yCoef[i][0] = (-1) * yCoef[i-1][0];
			yCoef[i][1] = (-1) * yCoef[i-1][1];
			yCoef[i][2] = (2 * p) - yCoef[i-1][2];
		}
	}
	//for(int i = 0; i<=m; i++) cout<<xCoef[i][0]<<" "<<xCoef[i][1]<<" "<<xCoef[i][2]<<"\t\t"<<yCoef[i][0]<<" "<<yCoef[i][1]<<" "<<yCoef[i][2]<<endl;
	int q; cin>>q;
	for(int i = 0; i<q; i++){
		int op,piece; cin>>op>>piece;
		pair<int, int> point = points[piece];
		pair<ll, ll> fPoint = evaluate(point.first, point.second, op);
		cout<<fPoint.first<<" "<<fPoint.second<<"\n";
	}
}
