#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
typedef long double Double;

const Double INF = 11ll << 60;
const Double ERROR = 1e-9;
const Double M_2PI = 2.0 * M_PI;

#define EQ(a,b) (fabs((a) - (b)) < ERROR)

struct Punto{
	Double x,y;
	Punto() : x(),y(){}
	Punto(Double X, Double Y) : x(X), y(Y) {}

	bool operator<(const Punto& q) const{
		if(!EQ(x,q.x)) return x < q.x;
		return EQ(y,q.y)? false: y < q.y;
	}
	
	bool operator==(const Punto& q) const{
		return EQ(x,q.x) && EQ(y,q.y);
	} 

	//sumar los vectores actual y q.
        Punto operator +(const Punto& p) const { return Punto(x+p.x, y+p.y); }
        //Restar los vectores (o trasladarlos), tomando como p el prigen
        Punto operator -(const Punto& p) const { return Punto(x-p.x, y-p.y); }
        //Obtener el vector opuesto
        Punto operator -() const { return Punto(-x,-y); }
        //Obtener el vector por un esalar
        Punto operator*( Double c ) const { return Punto(x*c, y*c); }
        //Obtener el vector dividido por un escalar
        Punto operator/(Double c) const { return Punto( x/c, y/c); }
	//MAgnitud del vector
	Double Abs() const{ return hypot(x,y); }
        //Producto cruz entre el punto actual y q.
        Double Cruz(const Punto& q) const { return x*q.y - y*q.x; }
	//Distancia entre el punto actual y q
	Double Dist( const Punto& q) const{ return (*this - q).Abs(); }

};

int ManoDerecha(const Punto& o, const Punto& p, const Punto& q){
        Double ccw = (p-o).Cruz(q-o);
        return EQ(ccw,0)? 0: (ccw < 0)? -1: 1;
}


typedef vector<Punto> Poligono;

//calcula el perimetro de un poligono
Double Perimetro(const Poligono& P){
	Double perimetro = 0;
	for(int i = 1; i<P.size();++i){
		perimetro += P[i].Dist(P[i-1]);
	}
	return perimetro;
}
//cerco convexo de un conjunto de puntos
template<class It> Poligono CercoConvexo(It lo, It hi){
        int k = 0;
        if( hi - lo <= 1) return Poligono(lo,hi);
        Poligono H(2 * (int)(hi-lo));
        sort(lo,hi);

        for(It it = lo; it != hi; ++it){
                while( k>=2 && ManoDerecha(H[k-2], H[k-1], *it) < 1) k--;
                H[k++] = *it;
        }
        int t = k+1;
        for(It it = hi - 2; it != lo-1; --it) {
                while( k >= t && ManoDerecha(H[k-2],H[k-1],*it) < 1 ) k--;
                H[k++] = *it;
        }
        H.resize(k);
        return H;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		Double l,n;
		Poligono p;
		cin>>l>>n;
		for(int i = 0; i<n;i++){
			Double x,y;
			cin>>x>>y;
			p.push_back(Punto(x,y));
		} 
		sort(p.begin(),p.end());

		Poligono pc = CercoConvexo(p.begin(),p.end());
		Double per = Perimetro(pc);
		Double res = (per > l) ? per:l;
		cout<<fixed<<setprecision(5)<<res<<"\n";
	}
}
