#include <bits/stdc++.h>
using namespace std;
int h, w, x, y;
string s[105];

int findHor(){
	int res = 0;
	for(int j = y-2; j>= 0; j--){
		if(s[x-1][j] == '#') break;
		else res++;
	}

	for(int j = y; j < s[x-1].size() ; j++){
		if(s[x-1][j] == '#') break;
		else res++;
	}

	return res;
}

int findVer(){
	int res = 0; 
	for(int i = x-2; i>=0; i--){
		if(s[i][y-1] == '#') break;
		else res++;
	}

	for(int i = x; i < h; i++){
		if(s[i][y-1] == '#') break;
		else res++;
	}

	return res;
}
int main(){
	cin>>h>>w>>x>>y;
	for(int i = 0; i<h; i++){
		cin>>s[i];
	}
	int nSqs = 1;
	nSqs += (findHor() + findVer());
	
	cout<<nSqs<<"\n";
}
