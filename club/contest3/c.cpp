#include <bits/stdc++.h>
using namespace std;
int cup[10005];
int main(){
	int n;
	cin>>n;
	int sum = 0;
	for(int i = 0; i<n; i++){ cin>>cup[i]; sum+=cup[i];}
	int mili = -1, a = -1, b = -1;
	if(n == 1){
		cout<<"Exemplary pages.\n";
		return 0;
	}
	if(sum % n != 0){
		cout<<"Unrecoverable configuration.\n";
		return 0;
	}
	int prom = sum / n;
	bool out = false;
	for(int i = 0; i<n ; i++){
		if(cup[i] != prom){
			for(int j = i+1; j<n;j++){
				if(cup[i] < cup[j] && cup[j] != prom){
					a = i+1;
					b = j+1;
					mili = cup[j] - prom;
					cup[j] -= mili;
					cup[i] += mili;
					out = true;
					break; 
				}else if(cup[i] > cup[j] && cup[j] != prom){
					a = j+1;
                                	b = i+1;
                                	mili = cup[i] - prom;
                                	cup[j] += mili; 
                                	cup[i] -= mili;
					out = true;
					break;
				} 
			}
		}
		if(out) break;
	}
	bool unreach = false;
	for(int i = 0; i<n ; i++){
		for(int j = i+1; j<n ; j++)
			if(cup[i] != cup[j]){ unreach = true; break;}
		if(unreach) break;
	}
	if(unreach) cout<<"Unrecoverable configuration.\n";
	else if( mili == -1 ) cout<<"Exemplary pages.\n";
	else cout<<mili<<" ml. from cup #"<<a<<" to cup #"<<b<<".\n";
}
