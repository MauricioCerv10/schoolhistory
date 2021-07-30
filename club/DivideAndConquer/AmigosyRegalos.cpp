#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll c1,c2,x,y;
/*
Función de comprobación que verifica que el numero tenga los suficientes numeros 
de c1 y c2 para regalar, que no sean divisibles entre x y y, respectivamente
*/
bool isRes(ll res){
	ll nc1 = 0, nc2 = 0, c1c2 = 0;
	/*calcula el numero de numeros que dividen los primos
		a su respectivo conjunto
	*/
	ll xap = res/x;
	ll yap = res/y;

	//calcula la intersección de c1 y c2 por medio del principio de exclusión
	c1c2 = res - (xap + yap - res/(x*y)); 
	
	nc1 = res - c1c2 - xap;
	nc2 = res - c1c2 - yap;

	if(nc1<c1) c1c2 -=  c1-nc1;
	if(nc2 < c2 ) c1c2 -= (c2-nc2);
	
	if(c1c2 >= 0) return true;
	return false;
	
} 
/*
Busqueda binaria que se encarga de encontrar el conjunto más pequeño que cumpla ,
haciendo uso de isRes()
*/
ll binaria(){
	ll ini = c1+c2,fin = 1ll<<50,mid = 0,res = -1;
	while(ini<=fin){
		mid = (ini+fin)/2;
		if(isRes(mid)) {fin = mid-1; res = mid;}
		else {ini = mid+1;}
	}
	return res;
}

int main(){
	
	cin>>c1>>c2>>x>>y;
	ll res = binaria();
	cout<<res<<"\n";
	
}
