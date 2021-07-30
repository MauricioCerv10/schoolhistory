#include <bits/stdc++.h>

using namespace std;

int main(){
	string res = "";
	string line;
       	while(getline(cin,line)) {
		res += " " + line;
		cout<<res<<endl;
		bool out = false;
		for(int i = 0; i<line.size(); i++){
			if(line[i] == '.'){
				int dotCount = 0; 
				for(int j = i+1; j<line.size(); j++){
					if(line[j] != '.') break;
					dotCount++;
					if(dotCount == 6){
						out = true;
						break;
					}
				}
			}
			if(out) break;
		}

		if(out) break;
	}
}
