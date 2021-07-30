#include <iostream>
#include <string>
using namespace std;
int n, p,r,nOfrments,c,nrfp;
float price, compliance, bestC, bestP; 
string name, rment;
int caso ;
string best;
int main(){
	
	nrfp = 1;
	while(cin >> n>>p,(n||p)){
		cin.clear();
		cin.ignore();
		
		if(caso++)cout<<"\n";
		string rments[n];
                for(int i = 0;i<n;i++){
                        getline(cin, rments[i]);
			
               	}

		c = 0;
		while(c<p){
			nOfrments = 0;
			getline(cin,name);
			cin>>price>>r;
			cin.clear();
			cin.ignore();
			compliance = (float)r/p;
			for(int i = 0;i<r;i++){
				getline(cin,rment);
				/*for(int j = 0; j<n;j++){
					if(rment.compare(rments[j]) == 0){
						nOfrments++;
					}
				}*/
			}if(c == 0){
				best = name;
				bestC = compliance;
				bestP = price;
			}
			else if(compliance>bestC){
				best = name;
				bestC = compliance;
				bestP = price;
			}else if(compliance == bestC && price<bestP){	
				best = name;
				bestC = compliance;
				bestP = price;
			}
			c++;
		}
		cout<<"RFP #"<<nrfp<<"\n"<<best<<"\n";
		nrfp++;
	}
}
