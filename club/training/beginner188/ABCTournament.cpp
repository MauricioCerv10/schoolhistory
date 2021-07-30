#include <bits/stdc++.h>
using namespace std;
int A[100000];

bool compare(pair<int,int> a, pair<int,int> b){
	return a.second < b.second;
}

int main(){
	int n;
	cin>>n;	
	int maxIndex = pow(2,n);
	int maxRate = 0;
	int indexMaxRate = -1;
	for(int i = 0;i<maxIndex;i++){
		cin>>A[i];
		if(A[i] > maxRate){
			maxRate = A[i];
			indexMaxRate = i;
		}
	}
	int mid = maxIndex/2;
	int ini = -1, fin = -1;
	if(indexMaxRate <= (mid - 1)){
		ini = mid;
		fin = maxIndex;
	}else{
		ini = 0;
		fin = mid;
	}
	
	pair<int,int> secondsMid[maxIndex/2];
	int seIndex = 0;
	for(int i = ini; i<fin; i++){ 
		secondsMid[seIndex++] = make_pair(i,A[i]);
	}
	sort(secondsMid, secondsMid+(maxIndex/2),compare);
	
	/*for(int i = 0; i<(maxIndex/2); i++){ 
		cout<<secondsMid[i].second<<endl;
	}*/
	cout<<secondsMid[maxIndex/2 - 1].first+1<<endl;
	
}
