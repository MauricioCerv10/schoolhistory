#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		int n,k; string s;
		cin>>n>>k>>s;
		int minNum = 0;
		//cout<<"caso"<<endl;
		int fiIdx = 0;
		for(int i = s.find_first_of('*'); i<s.size(); i++){
			//cout<<"i fuera "<<i<<endl;
			if(s[i] == '*'){
				minNum++;
			//	cout<<"i = "<<i<<endl;
				s[i] = 'x';
				i += k-1;
			}else{
				int j = i;
				while(j >= 0){
					if(j<n && s[j] == '*'){
						minNum++;
						s[j] = 'x';
						i = j+k-1;
			//			cout<<"i en j = "<<j<<endl;
						break;
					}
					j--;
				}
			}
		}
		for(int i = s.size() - 1; i>=0 ; i--){
			if(s[i] == 'x'){ break; }
			if(s[i] == '*'){ minNum++; break; }
		}
		cout<<minNum<<endl;
	}
}
