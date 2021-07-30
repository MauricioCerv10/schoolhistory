#include <bits/stdc++.h>
using namespace std;

pair<int,int> abDish[105];
pair<int,int> persons[20];
int memo[105];
int k,m;
int dp(int dish, int index, vector<int> diNumber){
	diNumber[dish] += 1;
	if(index == k-1){
		int conCompleted = 0;
		for(int i = 0; i<m; i++){
			if(diNumber[abDish[i].first] > 0 && diNumber[abDish[i].second] > 0)
				conCompleted++;
		}
		return conCompleted;
	}
	return max( dp( persons[index+1].first, index+1, diNumber) , dp(persons[index+1].second, index+1, diNumber) ); 
}

int main(){
	int n;
	cin>>n>>m;
	vector<int> diNumber;
	for(int i = 0; i<=n; i++){
		diNumber.push_back(0);
	}
	for(int i = 0; i<m; i++){
		int a,b;
		cin>>a>>b;
		pair<int,int> tuple = make_pair(a,b);
		abDish[i] = tuple;
	}
	cin>>k;
	for(int i = 0; i<k; i++){
		int a,b;
                cin>>a>>b;
                pair<int,int> tuple = make_pair(a,b);
                persons[i] = tuple;
	}

	int conditions = max(dp(persons[0].first,0,diNumber), dp(persons[0].second,0,diNumber));
	cout<<conditions<<"\n";
}
