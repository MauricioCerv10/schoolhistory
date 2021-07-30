#include <bits/stdc++.h>
using namespace std;

void calcuTiempo(int t){
        int hrs = t/3600;
	t -= hrs*3600;
	int mins = t/60;
	int segs = (t-mins*60);
        cout<<hrs<<" horas "<<mins<<" minutos "<<segs<<" segundos\n";
}


int main(){
	int t;
	cin>>t;
	calcuTiempo(t);
}
