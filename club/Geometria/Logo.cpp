#include <bits/stdc++.h>
using namespace std;

#define MAX 1005

double len[MAX];
string com[MAX];

double gradARad(double grd){
	return (grd*M_PI)/180.0;
}

double radAGad(double rad){
	return (rad*180)/M_PI;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i = 0; i<n;i++) cin>>com[i]>>len[i];
		double x,y,rotCW,rotCCW;
		x = y = rotCW = rotCCW  = 0;
		for(int i = 0; i<n;i++){
			if(com[i].compare("fd") == 0){
				if(rotCCW == 0) {x += len[i]; continue;}
				
				x += len[i]*cos(gradARad(rotCCW));
				y += len[i]*sin(gradARad(rotCCW));
			
			}else if(com[i].compare("bk") == 0){
				if(rotCCW == 0) {x -= len[i]; continue;}
                                
                                x += len[i]*cos(gradARad(rotCCW-180));
                                y += len[i]*sin(gradARad(rotCCW-180));

			}else if(com[i].compare("lt") == 0){
				rotCCW += len[i];
			}else if(com[i].compare("rt") == 0){
				rotCCW -= len[i];
			}
		}
		int res = round(sqrt(pow(x,2) + pow(y,2)));
		cout<<res<<endl;
	}
}
