#include <iostream>

using namespace std;

float H,U,D,F, heigthC,day;
int main(){
        while(true){
                cin>>H>>U>>D>>F;
                if(H == 0){
                        break;
                }
                F = U*(F *.01);
                day = 1;
                heigthC = 0;
                while(true){
			if(U > 0){
                                heigthC += U;

                        }
                        if(heigthC > H){
                                break;
                        }

                        heigthC -= D;
                        if(heigthC < 0){
                                break;
                        }
 			U -= F;

                        day++; 
                }
                if(heigthC >= H){
                        cout<<"success on day "<<day<<"\n";
                }else{
                        cout<<"failure on day "<<day<<"\n";
                }
        }
}
