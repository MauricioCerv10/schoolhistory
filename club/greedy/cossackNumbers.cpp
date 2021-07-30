#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	double  resp = 0.0;
	double resn = 0.0;
	while(n--){
		double num;
		cin>>num;	
		//cout<<num<<endl;

		if(num > 0.00000){
			int inum = floor(num);
			double dec = 1.00000 - (num - (double)inum);
			//cout<<dec<<endl;
			int ans;
			if(resp + dec < 1.00000){ 
				resp += dec;
				ans = ceil(num);
			}else{
				resp -= num - (double)inum;
				ans = floor(num);
			}
			cout<<ans<<endl;
		}else{
			int inum = ceil(num);
			//cout<<inum<<" "<<num<<endl;
                        double dec = 1.00000 - abs(num - (double)inum);
                        //cout<<dec<<endl;
			int ans;
                        if(resn + dec < 1.00000){ 
                                resn += dec;
                                ans = floor(num);
                        }else{
                                resn -= abs(num - (double)inum);
                                ans = ceil(num);
                        }
                        cout<<ans<<endl;
		}
		
	}
}
