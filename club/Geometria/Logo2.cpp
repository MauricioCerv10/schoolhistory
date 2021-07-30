#include <bits/stdc++.h>
using namespace std;

#define MAX 1005

const double EPS = (1e-9);
double len[MAX];
string com[MAX];
int idx,n;

double gradARad(double grd){
	return (grd*M_PI)/180.0;
}

double radAGad(double rad){
	return (rad*180)/M_PI;
}

int solve(double pos){
	double x,y,rotCCW;
	x = y = rotCCW  = 0;
	for(int i = 0; i<n;i++){
		if(com[i].compare("fd") == 0){
			if(i == idx){
				if(rotCCW == 0) {x += pos; continue;}

                                x += pos*cos(gradARad(rotCCW));
                                y += pos*sin(gradARad(rotCCW));

			}else{
				if(rotCCW == 0) {x += len[i]; continue;}
			
				x += len[i]*cos(gradARad(rotCCW));
				y += len[i]*sin(gradARad(rotCCW));
			}
		}else if(com[i].compare("bk") == 0){
			if(i == idx){
				if(rotCCW == 0) {x -= pos; continue;}
                                
                                x += pos*cos(gradARad(rotCCW-180));
                                y += pos*sin(gradARad(rotCCW-180));

			}else{
				if(rotCCW == 0) {x -= len[i]; continue;}
                               
				x += len[i]*cos(gradARad(rotCCW-180));
                        	y += len[i]*sin(gradARad(rotCCW-180));
			}
		}else if(com[i].compare("lt") == 0){
			if(i == idx) rotCCW += pos; 
			else rotCCW += len[i];
			
		}else if(com[i].compare("rt") == 0){
			if(i == idx) rotCCW -= pos;
			else rotCCW -= len[i];
		}
	}
	int res = round(sqrt(pow(x,2) + pow(y,2)));
	return res;
}

int search(int opc){
	double l,r; 
	if(opc == 1){ l = 0; r = 359; }
	else {l = 1; r = 1000000;}

        while((r-l) > EPS){
        	double m1 = l+(r-l)/3;
               	double m2 = r-(r-l)/3;
               	if(solve(m1) >= solve(m2)) l = m1;
                else r = m2;
        }

    	int ans = (l+r)/2;
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		string comm;
		int res;

		for(int i = 0; i<n;i++){ 
			string tmp;
			cin>>com[i]>>tmp;
			if(tmp.compare("?") == 0) {
				len[i] = -1; 
				idx = i;
				comm = com[i];
			}
			else {
				string::size_type sz;
				len[i] = stod(tmp,&sz);
			}
		}

		if(comm.compare("fd") == 0 || comm.compare("bk") == 0 )  res = search(0);
		else res = search(1);

		cout<<res<<endl;
	}
}

