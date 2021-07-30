#include <bits/stdc++.h>
using namespace std;


typedef long double Double;
typedef long long Long;

const Double INF = 1ll << 60;
const Double ERROR = 1e-9;
const Double M_2PI = 2.0 * M_PI;

#define EQ(a, b) (fabs((a) - (b)) < ERROR)

struct Punto{
	Double x,y;
	Punto() : x(),y() {}
	Punto(Double X, Double Y) : x(X), y(Y) {}
	bool operator<(const Punto& q) const {
	    	if (!EQ(x, q.x)) return x < q.x;
	   	 return EQ(y, q.y)? false: y < q.y;
	  }
	bool operator==(const Punto& q) const {
	    	return EQ(x, q.x) && EQ(y, q.y);
	  }

	  //Sumar los vectores actual y q.
	  Punto operator +(const Punto& p)const { return Punto(x+p.x, y+p.y); }
	  //Restar los vectores (o trasladarlos), tomando p como el origen.
	  Punto operator -(const Punto& p)const { return Punto(x-p.x, y-p.y); }
	  //Obtener el vector opuesto.
	  Punto operator -() const { return Punto(-x, -y); }
	  //Obtener el vector por un escalar.
	  Punto operator*( Double c ) const { return Punto( x*c, y*c ); }
	  //Obtener el vector dividido por un escalar.
	  Punto operator/( Double c ) const { return Punto( x/c, y/c ); }
	  //Magnitud del vector.
	  //Double Abs() const { return hypot(x, y); }
	  //Magnitud elevada al cuadrado del vector.
	  //Double Norm() const{ return x*x + y*y; }
	  //Distancia entre el punto actual y q.
	  //Double Dist( const Punto& q ) const { return (*this - q ).Abs(); }
	  //Distancia elevada al cuadrado entre el punto actual y q.
	  //Double Dist2(const Punto& q ) const { return ( *this - q).Norm(); }
	  //Producto punto entre el punto actual y q.
	  //Double Dot( const Punto& q ) const { return x*q.x + y*q.y; }
  	//Producto cruz entre el punto actual y q.
  	Double Cruz( const Punto& q ) const { return x*q.y - y*q.x; }

};
struct Linea {
  	Punto p, q;
  	Double a, b, c;
	Linea() : p(), q(), a(), b(), c() {}
	Linea(Long A, Long B, Long C) : p(), q(), a(A), b(B), c(C) {
		if (EQ(a, 0)) {
	      		c /= -b; b = -1;
	      		p = Punto(0, c);
      			q = Punto(1, c);
    		} else if (EQ(b, 0)) {
      			c /= -a; a = -1;
      			p = Punto(c, 0);
      			q = Punto(c, 1);
    		} else {
      			p = Punto(-c/a, 0);
      			q = Punto(-(b+c)/a, 0);
    		} if (q < p) swap(p, q);
  	}

  	Linea(const Punto& P, const Punto& Q)
    	: p(P), q(Q), a(), b(), c() {
    		// Asegura p como punto menor.
    		if (q < p) swap(p, q);
    		a = q.y - p.y;
    		b = p.x - q.x;
    		if (!a) c = p.y, b = -1;
    		else if (!b) c = p.x, a = -1;
    		else c = -a*p.x - b*p.y;
  	}
};

// Saber si dos lineas l y m son paralelas.
bool LineasParalelas(const Linea& l, const Linea& m) {
  	return EQ( 0, ( l.q - l.p ).Cruz( m.q - m.p ) );
}

// Saber si dos lineas l y m son iguales.
bool LineasIguales(const Linea& l, const Linea& m) {
  	return LineasParalelas(l, m)
    	&& EQ( 0, ( l.p - l.q ).Cruz( l.p - m.q ) )
    	&& EQ( 0, ( m.q - m.p ).Cruz( m.q - l.p ) );
}

// Saber si dos rectas r y s se intersectan.
// No intersectan = 0, Interseccion en un punto = 1,
// Interseccion paralela en infinitos puntos = -1.

int InterseccionRectas(const Linea& r, const Linea& s) {
  	if (LineasIguales(r, s)) return -1;
  	return LineasParalelas(r, s)? 0: 1;
}

// Obtener punto de interseccion entre lineas l y m.
Punto PuntoInterseccion(const Linea& l, const Linea& m) {
  	Punto a = l.p, b = l.q, c = m.p, d = m.q;
  	b = b-a; d = c-d; c =c-a;
  	assert( !LineasParalelas( l, m ) );
  	return a + b*(c.Cruz( d )/b.Cruz( d ));
}


int main(){
	int t;
	cin>>t;
	cout<<"INTERSECTING LINES OUTPUT\n";
	while(t--){
		Double x1,y1,x2,y2,x3,y3,x4,y4;
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

		Linea l1 = Linea(Punto(x1,y1),Punto(x2,y2));
		Linea l2 = Linea(Punto(x3,y3),Punto(x4,y4));

		int opc = InterseccionRectas(l1,l2);
		if(opc == 0) cout<<"NONE\n";
		else if(opc == -1) cout<<"LINE\n";
		else{
			Punto inte = PuntoInterseccion(l1,l2);
			cout<<"POINT "<<fixed<<setprecision(2)<<inte.x<<" "<<fixed<<setprecision(2)<<inte.y<<"\n";
		}
	}
	cout<<"END OF OUTPUT\n";
}
