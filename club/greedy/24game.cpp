#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin>>n;
	if(n < 4){ cout<<"NO"<<endl; return 0;}
	vector<string> st;
	cout<<"YES\n";
	while(n > 5){
		cout<<n<<" - "<<n-1<<" = "<<1<<endl;
		cout<<1<<" * "<<n-2<<" = "<<n-2<<"\n";
		n -= 2;
	}
	
	if(n == 4){
		cout<<4<<" * "<<3<<" = "<<12<<endl;
		cout<<12<<" * "<<2<<" = "<<24<<endl;
		cout<<24<<" * "<<1<<" = "<<24<<endl;
	}else{
		cout<<5<<" - "<<3<<" = "<<2<<endl;
		cout<<2<<" * "<<4<<" = "<<8<<endl;
		cout<<1<<" + "<<2<<" = "<<3<<endl;
		cout<<8<<" * "<<3<<" = "<<24<<endl;
	}
	return 0;
}
