#include <bits/stdc++.h>
using namespace std;

#define MAX 100010

bool func(int f, int l){ return (f<l); } 
int caso;
int sb[MAX],sg[MAX];
int main(){
	int n;
	cin>>n;

	while(n--){
		if(caso++) cout<<"\n";
		int B,SB,SG;
		cin>>B>>SG>>SB;
		
		for(int i = 0;i<SG;i++) cin>>sg[i]; 
		for(int i = 0;i<SB;i++) cin>>sb[i];  
		
		if(SB>1) sort(sb,sb+SB,func);
		if(SG>1) sort(sg,sg+SG,func);
		
		int tamsb, tamsg;
		tamsb = SB-1;
		tamsg = SG-1;
		int inisb,inisg;
		inisb = inisg = 0;

		while(true){
			int avasb = SB-1;
			int avasg = SG-1;
			
			for(int i = 1;i<=B;i++){
				if(sb[avasb] == 0 || sg[avasg] == 0) break;
				if(sb[avasb] < sg[avasg] ) {
					sg[avasg] -= sb[avasb];
					sb[avasb] = 0; 
					tamsb--;
				}
				else if(sb[avasb] > sg[avasg]) {
					sb[avasb] -= sg[avasg]; 
					sg[avasg] = 0;
					tamsg--;
				}
				else {
					sb[avasb] = 0;
					sg[avasg] = 0;
					tamsb--; tamsg--;
				}
				avasb--;
				avasg--;
			}

			if(tamsb == -1 && tamsg == -1){ cout<<"green and blue died\n"; break; }
			else if(tamsb == -1) { 
				cout<<"green wins\n"; 
				if(tamsg>0) sort(sg,sg+SG,func);
                                for(int i = SG-1;i>=0;i--) {
					if(sg[i] != 0) cout<<sg[i]<<"\n";
					else break;
				}
				break; 
			}
			else if(tamsg == -1) { 
				cout<<"blue wins\n";
				if(tamsb>0) sort(sb,sb+SB,func);
				for(int i = SB-1;i>=0;i--) 
					if(sb[i] != 0) cout<<sb[i]<<"\n";
					else break;
				break; 
			}

			if(SB > 1) sort(sb+inisb,sb+SB,func);
                	if(SG > 1) sort(sg+inisg,sg+SG,func);
			inisg = SG-tamsg+1;
			inisb = SB-tamsb+1;  
		}
	}
}
