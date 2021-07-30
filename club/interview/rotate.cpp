#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &A){
	bool izq = false, der = true, aba = false, arr = false;
	int n = A.size();
	int ini = 0;
	for(int i = n; i > 0 ; i -= 2){
		cout<<i<<endl;
		der = true;
		int r = ini, c = ini;
		int ant = A[1][0];
		if(i*i == 1) break;
		for(int j = 0; j<i*4 - 4; j++){
			int tmp = A[r][c];
			A[r][c] = ant;
			ant = tmp;
			if(r == ini && c == ini + i-1){ der = false; aba = true;}
			if(r == ini + i - 1 && c == ini + i-1){ aba = false; izq = true;}
			if(r == ini + i - 1 && c == ini ){ izq = false; arr = true; }
			if(der) c++;
			if(aba) r++;
			if(izq) c--;
			if(arr) r--;
		}
		ini++;
	}
}
int main(){
	vector<vector<int>> v(4);
	int num = 0;
	for(int i = 0; i<4; i++){
		vector<int> vec;
		for(int j = 0; j < 4; j++){
			vec.push_back(num); num++;
		}
		v[i] = vec; 
	}
	for(int i = 0; i<4; i++){
		
		for(int j = 0; j < 4; j++){
			cout<<v[i][j]<<"\t";
		}
		cout<<"\n\n";
	}
	
	rotate(v);
	
	cout<<"\n\n\n\n";
	for(int i = 0; i<4; i++){
		for(int j = 0; j < 4; j++){
			cout<<v[i][j]<<"\t";
		}
		cout<<"\n\n";
	}
	
	
}
