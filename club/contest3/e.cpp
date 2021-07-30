#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int x[100005];

int main(){
	int n,a;
	cin>>n>>a;
	for(int i = 0; i<n ; i++) cin>>x[i];
	if(n == 1){ cout<<abs(x[0]-a)<<"\n"; return 0;}

	sort(x, x+n);
	
	ll sum = 0;
	if(a  > x[n-1]){ 
		sum += abs((a-x[n-1]) + (x[n-1] - x[1]));
		cout<<sum<<"\n";
		return 0;
	}
	else if (a < x[0]){ 
		sum += abs((x[0]-a) + (x[n-2] - x[0]));
		cout<<sum<<"\n"; 
		return 0;
	}
	int ir,il;
	int p = -1;
	for(int i = 0; i<n-1; i++){
		if(x[i] == a){ p = i; ir = p+1; il = p-1; break;}
		if(x[i] < a && x[i+1] > a ){
			ir = i+1;
			il = i;
			if(a - x[il] == x[ir] - a){
				if(x[n-1]-x[1] > x[n-2]-x[0]){
					if(a-x[0] < x[n-2]-a){ p = il; sum += a-x[il]; il--;}
					else{ p = ir;sum += x[ir]-a; ir++; }
				}else{
					if(a-x[1] > x[n-1]-a){ p = ir; sum += x[ir]-a; ir++; }
					else{ p = il; sum += a-x[il]; il--; }
				}
			}
			else if(a - x[il] < x[ir] - a){ p = il; sum += a-x[il]; il--;}
			else{ p = ir;sum += x[ir]-a; ir++;}
			break;
		}
	}
	cout<<il<<" "<<p<<" "<<ir<<" "<<sum<<"\n";
	for(int i = 0; i<n-1; i++){
		if(ir > n-1){sum += x[n-1] - x[1]; break;}
		if(il < 0){sum += x[n-2] - x[0]; break; }
		if(p == 0 && ir < n-1){sum += x[ir] - x[1]; break;}
		if(p == n-1 && il > 0){ sum += x[p] - x[il]; break;}
		if(p == n-2 && il == 0){ sum += min(x[n-1] - x[p], x[p] - x[il]); break;}
		if(p == 1 && ir == n-1){ sum += min(x[ir] - x[p], x[p] - x[0]); break;}
		if(x[p] - x[il] ==  x[ir] - x[p]){
			if(x[n-1]-x[1] > x[n-2]-x[0]){
                        	if(x[p]-x[0] < x[n-2]-x[p]){ sum += x[p] - x[il]; p = il; il--; }
                        	else{ sum += x[ir] - x[p]; p = ir; ir++; }
                        }else{
                        	if(x[p]-x[1] > x[n-1]-x[p]){sum += x[ir] - x[p]; p = ir; ir++;}
                        	else{  sum += x[p] - x[il]; p = il; il--; }
                        }

		}
		else if(x[p] - x[il] < x[ir] - x[p]){
			sum += x[p] - x[il];
			p = il;
			il--;
		}else{
			sum += x[ir] - x[p];
			p = ir;
			ir++;
		}
	}
	cout<<sum<<"\n";
}
