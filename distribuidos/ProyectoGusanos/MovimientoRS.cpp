#include "MovimientoRS.h"
#include "gfx.h"
#include <unistd.h>
#include <math.h>
#include <algorithm>
using namespace std;

MovimientoRS::MovimientoRS(int tamx, int tamy): tamx(tamx),tamy(tamy){
}

pair<int,int> MovimientoRS::recta(int sigmov){
	int x,y;
	if(sigmov < 0) x = tamx;
	else if(sigmov > tamx) x  = x%tamx;
	else x = sigmov;
	
	y = m*x + b;
	
	if(y <= 0) y = tamy - abs(y);
	else y %= tamy;
	
	return make_pair(x,y);
}

pair<int,int> MovimientoRS::serpiente(int sigmov){
	int x,y;
	if(sigmov < 0) x = tamx;
        else if(sigmov > tamx) x  = x%tamx;
        else x = sigmov;

        y = (m*x + b) + 2*sin(x);

        if(y <= 0) y = tamy - abs(y);
        else y %= tamy;

	return make_pair(x,y);
}
void MovimientoRS::setNewEcuacion(int x, int y){
	m = rand()%3;
        b = -(m*x) + y;
}

