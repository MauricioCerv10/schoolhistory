#include <bits/stdc++.h>
using namespace std;
string s1;
string s2;
int posibi,appr;
int target;
void calcu(int i,int sum){
	/*if(i == s2.size()-1 ){
		if(s2[i] == '+' || s2[i] == '-') posibi++;
		else posibi += 2;
	}*/

	if(i == s2.size()){
		posibi++;
		if(sum == target) appr++;
		return; 
	}

	if(s2[i] == '+'){ calcu(i+1,sum+1); }
	else if(s2[i] == '-') calcu(i+1,sum-1);
	else{
		calcu(i+1,sum+1);
		calcu(i+1,sum-1);
	}

}

int main(){
	cin>>s1>>s2;
	for(int i = 0; i<s1.size(); i++) 
		if(s1[i] == '+') target++;
		else target--;
	calcu(0,0);
	double res = ((double)appr)/((double)posibi);
	cout<<fixed<<setprecision(10)<<res<<endl;
}
