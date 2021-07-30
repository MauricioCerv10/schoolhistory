#include <bits/stdc++.h>

using namespace std;

int h[100005];

void printVal(int x){
	cout<<" "<<x;
}

void printAndDeque(queue<int> &q){
	while(!q.empty()){
		int a = q.front(); q.pop();
		printVal(a);
	}
}

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		for(int i = 0; i<n; i++){
			cin>>h[i];
		}

		sort(h,h+n);
		
		pair<int,int> firstVal = make_pair(-1,-1), lastVal = make_pair(-1,-1);
		int minDiff = INT_MAX;
		
		for(int i = 0; i<n-1; i++){
			if(h[i+1]-h[i] < minDiff){
				firstVal.first = h[i];
				firstVal.second = i;
				lastVal.first = h[i+1];
				lastVal.second = i+1;
				minDiff = h[i+1] - h[i];
			}
		}

		int idx = 0;
		cout<<firstVal.first;
		int prevVal = firstVal.first;
		queue<int> rep;
		vector<int> repVals;
		for(int i = 0; i<n; i++){
			if(i == firstVal.second || i == lastVal.second) continue;
			if(prevVal == h[i]){
				repVals.push_back(h[i]);
			}else if(h[i] < firstVal.first){
				repVals.push_back(h[i]);
			}else{
				prevVal = h[i];
				printVal(h[i]);
			}
		}
		
		prevVal = -1;
		for(int i = 0; i<repVals.size(); i++){
			if(!rep.empty() && repVals[i] != rep.front()){
				printVal(repVals[i]);
				printVal(rep.front());
				rep.pop();
			}else if(prevVal == repVals[i]){
                        	rep.push(repVals[i]);
                        }else{
                                printVal(repVals[i]);
                                if(!rep.empty()){
                                        printVal(rep.front());
                                        rep.pop();
                                }
                        }
                        prevVal = repVals[i];
		}
		printAndDeque(rep);
		cout<<" "<<lastVal.first<<"\n";

	}
}
