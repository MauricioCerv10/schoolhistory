#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	cin.clear();
	cin.ignore();
	for(int i = 0; i<n;i++){
		stack<char> pila;
		string line;
		getline(cin,line);
		pila.push('c');
		bool bandera = true;
		for(int j = 0; j<line.length();j++){
			char b = line.at(j);
			char top = pila.top();
	
			if(b == '{' || b == '[' || b == '('){
				pila.push(b);
			}else if((top == 'c' && b == '}') || (top == 'c' && b == ']') || (top == 'c' && b == ')')){
				bandera = false;
				break;
			}else if(b == '}' && top == '{'){
				pila.pop();
			}else if(b == ']' && top == '['){
				pila.pop();
			}else if(b == ')'  && top == '('){
				pila.pop();
			}
		}
		char top = pila.top();
		if(top == 'c' && bandera){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
}
