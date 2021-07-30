#include <iostream>
using namespace std;

int N, B, H, W, p, a, i,cheapest,j;
bool cupo;

int main(){
	int c=0;
	while(c<2){
		cin>>N>>B>>H>>W;
		i = 0;
		cheapest = 0;
		while(i < H){
			cin>>p;
			j = 0;
			cupo = false ;
			//cout<<p<<"\n"; 
			while(j < W){
				cin>>a;
				if(N<=a){
					cupo = true;
					break;
				}
				cout<<j<<"\n";
				j++;
				
			}
			int cost = p*N;
			if(cheapest == 0 && cupo == true && cost<=B){
				cheapest = p;
			}
			else if (cupo == true &&  cost>cheapest && cost<=B){
				cheapest = p;
				
			}
			i++;
		cout<<i<<"\n";

		}
		if(cheapest == 0){
			//cout<<"stay home\n";
		}else{
			//cout<<cheapest<<"\n";
		}
	c++;
	}
}
