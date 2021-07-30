#include <bits/stdc++.h>
using namespace std;

#define MAX 10000010

int wor[MAX];
int pos[MAX];

int main(){
	int n;
	cin>>n;
	int pil[n];
	for(int i = 0;i<n;i++) {
		if(i == 0) cin>>pil[i];
		else{
			cin>>pil[i];
			pil[i] += pil[i-1]; 
		}
	
	}
	int con = 0;
	for(int i = 1;i<=pil[n-1];i++){
		if( i > pil[con]) con++;
		wor[i] = i;
		pos[i] = con;
	}
	int q;
	cin>>q;
	while(q--){
		int worm;
		cin>>worm;
		int ini= 1,fin = pil[n-1], res = -1,mid = 0;
		while(ini<=fin){
			mid = (ini+fin)/2;
			if(wor[mid] < worm) ini = mid+1;
			else { fin = mid-1; res = mid;}
		}
		cout<<pos[res]+1<<endl;
	}
}
