#include <bits/stdc++.h>
using namespace std;

int main(){
	string s; cin>>s;
	string t; cin>>t;
	int n = s.length();
	int m = t.length();
	int ans = 0;
	for(int i = 0; i<=n-m; i++){
		string fs = "";
		char zero = 0,one = 0;
		for(int j = 0; j<m; j++){
			if(t[j] == '0'){
				if(zero == 0){
					zero = s[j+i];
					fs += s[j+i];
				}else{
					fs += zero;
				}
			}else{
				if(one == 0){
					one = s[j+i];
					fs += s[j+i];
				}else{
					fs += one;
				}
			}
		}
		
		bool match = true;
		for(int j = 0; j<m ; j++){
			if(fs[j] != s[j+i]) match = false;
		}

		if(match){ ans++; continue;}
		
		fs = "";
                zero = 0;one = 0;
                for(int j = m-1; j>=0; j--){
                        if(t[j] == '0'){
                                if(zero == 0){
                                     zero = s[(m-1)-j+i];
                                     fs += s[(m-1)-j+i];
                                }else{
                                     fs += zero; 
                                }
                        }else{ 
                                if(one == 0){ 
                                        one = s[(m-1)-j+i];
                                        fs += s[(m-1)-j+i];
                                }else{ 
                                        fs += one;
                                }
                        }
                }

                match = true;
                for(int j = 0; j<m ; j++)
                        if(fs[j] != s[j+i]) match = false;
		if(match) ans++;

	}
	cout<<ans<<"\n";
}
