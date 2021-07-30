#include <iostream>
using namespace std;
long long int K,N,M,X,Y, fin;

int main(){
	do{
		cin>>K;
		cin>>N>>M;

		for(int i = 0; i<K; i++){
			cin>>X>>Y;
			if(X == N || Y == M ){
				cout<<"divisa";
			}else if(X<N && Y>M){
				cout<<"NO";
			}else if(X>N && Y>M){
				cout<<"NE";
			}else if(X>N && Y<M){
				cout<<"SE";
			}else{
				cout<<"SO";
			}
		}
		
	}while(K!=0);
	
}
