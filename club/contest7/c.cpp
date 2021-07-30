#include <bits/stdc++.h>
using namespace std;
int acum[100005];
int main(){
	string s; cin>>s;
	int n = s.length();
	if(n%2 != 0){ cout<<"NO\n"; return 0;}
	int nA = 0,nB = 0;
	for(int i = 0; i<n; i++){
		if(s[i] == 'A' && i == 0){ acum[i] += 1; nA++;}
		else if(s[i] == 'A'){	 acum[i] += acum[i-1] + 1; nA++;}
		else{ acum[i] = acum[i-1]; nB++;}	
	}
	bool can = false;
	int x1,x2;
	for(int i = 0; i<n; i++){
		int a,b,resA,resB,resAA,resBB;
		a = i; b = (i+n/2)%n;
		if(a > b){
			 resA = acum[a] - acum[b];
                        resB = a-b - resA;
			resAA = nA - resA;
                        resBB = nB - resB;
			if(resA == resAA && resBB == resB){ 
                        	can = true; 
                        	x1 = b+2; 
				x2 = a+2; 
				if(x1 > n) x1 = x1 - n; 
                                else if(x2 > n) x2 = x2 -n; 
				break;
                	}
		}else{
			resA = acum[b] - acum[a];
			resB = b-a - resA;
			resAA = nA - resA;
			resBB = nB - resB;
			if(resA == resAA && resBB == resB){ 
                        	can = true; 
                        	x1 = a+2; 
				x2 = b+2;
				if(x1 > n) x1 = x1 - n;
				else if(x2 > n) x2 = x2-n; 
                        	break; 
              		} 

		}
		

	}
	if(x2 < x1 ){ int tmp = x1; x1 = x2; x2 = tmp; }
	if(can){ cout<<"YES\n"; cout<<x1<<" "<<x2<<"\n";}
	else cout<<"NO\n";
}

