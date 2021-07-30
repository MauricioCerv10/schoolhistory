#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-4;

double gradARad(double grd){
        return (grd*M_PI)/180.0;
}

void solve(double tx, double ty, double dx,double dy){
	double resx = tx*cos(gradARad(180)) - ty*sin(gradARad(180)) + dx; 
        double resy = ty*cos(gradARad(180)) + tx*sin(gradARad(180)) + dy;

       	if(fabs(resx) < EPS) resx = 0;
       	if(fabs(resy) < EPS) resy = 0;

        cout<<fixed<<setprecision(3)<<resx<<" "<<fixed<<setprecision(3)<<resy<<endl;

}
int main(){
	double x1,x2,x3,x4,y1,y2,y3,y4;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4){
		if(x2 == x3 && y2 == y3){
			double dx = (x1+x4)/2;
			double dy = (y1+y4)/2;

			double tx = x2-dx;
			double ty = y2-dy;
		
			solve(tx,ty,dx,dy);
		}else if(x1 == x3 && y1 == y3){ 
 	               double dx = (x2+x4)/2;
        	        double dy = (y2+y4)/2;
	
	                double tx = x1-dx;
	                double ty = y1-dy;
	
			solve(tx,ty,dx,dy);
	        }else if(x4 == x3 && y4 == y3){ 
	                double dx = (x2+x1)/2;
	                double dy = (y2+y1)/2;
	
	                double tx = x4-dx;
	                double ty = y4-dy;
			
			solve(tx,ty,dx,dy);
	        }else if(x1 == x2 && y1 == y2){ 
	                double dx = (x3+x4)/2;
	                double dy = (y3+y4)/2;
	
	                double tx = x1-dx;
	                double ty = y1-dy;
	
	               	solve(tx,ty,dx,dy);
	        }else if(x4 == x2 && y4 == y2){ 
	                double dx = (x3+x1)/2;
	                double dy = (y3+y1)/2;
	
	                double tx = x4-dx;
	                double ty = y4-dy;
	
	                solve(tx,ty,dx,dy);
	        }else if(x1 == x4 && y1 == y4){ 
	                double dx = (x3+x2)/2;
        	        double dy = (y3+y2)/2;
	
	                double tx = x1-dx;
                	double ty = y1-dy;

                	solve(tx,ty,dx,dy);
        	}
	}

}
