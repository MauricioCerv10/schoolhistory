#include <iostream>
using namespace std;
int period, rates,month[100];
double downP, carV, percent[100]; 

int main(){
	while(true){
		cin>>period>>downP>>carV>>rates;
		if(period<0){
			break;
		}
		int i = 0;
		while(i < rates){
			cin>>month[i]>>percent[i];
			i++;
		}
		i=0;
		double montlyPayment=carV/period;
		double pay = carV;
		carV = carV + downP;
		int con = 0;
		while(i<= period){
			if(i == 0){
				carV = carV-carV*percent[con];

			}else{
				carV = carV-carV*percent[con];
				pay = pay - montlyPayment;
			}
			if(carV>=pay){
				if(i == 1){
					cout<<i<<" month\n";
				}else{
					cout<<i<<" months\n";
				}
				break;
			}
			if((con+1) < rates && (i+1) == month[con+1]){
                                con++;  
                        }
                        
			i++;
		}
	}
}
