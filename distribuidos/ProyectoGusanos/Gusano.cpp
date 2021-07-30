#include "Gusano.h"
#include "MovimientoRS.h"
#include "MovimientoC.h"
#include "gfx.h"
#include <unistd.h>
#include <math.h>
#include <algorithm>
using namespace std;

Gusano::Gusano(int x0, int y0,int gtam,int tamx, int tamy):x(x0), y(y0), gtam(gtam), 
	tamx(tamx), tamy(tamy), movRS(tamx,tamy), movC(tamx,tamy){
	
	for(int i = 0; i<gtam; i++){
		points.push(make_pair(x,y));
		x++;
	}
	x--;
	con = 0;
	adelante = true;
	mov = rand()%3;
	setNewEcuacion();
	if(mov < 2) con = gtam;
}
queue< pair<int,int> > Gusano::setMov(){
	if(mov == 2){
		points.pop();
		pair<int,int> newp = movC.getNextCirclePoint(); movC.movNextPoint();
		
		x = newp.first;
		y = newp.second;
		points.push(newp);
 
		if(movC.getiC() == 0 && movC.getjC() == 0){
			mov = rand()%3;
			movC.clearCircle();
			if(mov < 2) con = gtam;
			setNewEcuacion();

		}
	}
	if(mov < 2){
		con--;
		points.pop();
		pair<int,int> newp = getNextLinePoint(mov);

		x = newp.first;
		y = newp.second;
		points.push(newp);
 
		if(con == 0){
			mov = rand()%3; 
			if(mov < 2) con = gtam;
			setNewEcuacion();
		}
	}
	return points;
}

pair<int,int> Gusano::getNextLinePoint(int mov){
	pair<int,int> newp;
	if(mov == 0){
		if(adelante) newp = movRS.recta(x+1);
		else newp = movRS.recta(x-1);
	}else if(mov == 1){
		if(adelante) newp = movRS.serpiente(x+1);
               	else newp = movRS.serpiente(x-1);

	}
	return newp;
}

void Gusano::setNewEcuacion(){
	if(mov < 2){
		int sign = rand()%2;
		movRS.setNewEcuacion(x,y);
		if(sign) adelante = false;
		else adelante = true;
	}else{
		movC.setNewEcuacion(x,y);
	}
}
