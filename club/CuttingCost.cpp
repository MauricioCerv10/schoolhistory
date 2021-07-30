#include <iostream>
using namespace std;
int in;
int a,b,c,i;

int main(){
	cin>>in;
	while(i<in){
		cin>>a>>b>>c;
		if((a>b && a<c) || (a<b && a>c)){
			cout<<"Case "<<i+1<<": "<<a<<"\n";
		}else if((b>a && b<c)||(b<a && b>c)){
			cout<<"Case "<<i+1<<": "<<b<<"\n";
		}else {
			cout<<"Case "<<i+1<<": "<<c<<"\n";
		}
		i++;
	}
}
