#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main(){
	int s, b, l, r;
	
    	vector<int> left(110000), right(110000);
    	while (cin>>s>>b, (s || b)) {
        	for (int i = 0; i <= s; i++) {
            		left[i] = i - 1;
            		right[i] = i + 1;
		}
 
        
       		 while (b--) {
            		cin>>l>>r;
           		if (left[l] < 1){ 
				cout<<"*";
            		}
			else{ 
				cout<<left[l];
			}
            		if (right[r] > s){ 
				cout<<" *\n";
			}
            		else{ 
				cout<<" "<<right[r]<<"\n";
			}
            
            		left[right[r]] = left[l];
            		right[left[l]] = right[r];
        	}
       		 cout"-\n";
	}
}
