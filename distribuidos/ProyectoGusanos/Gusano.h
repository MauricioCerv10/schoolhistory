#include <iostream>
#include <queue>
#include "MovimientoRS.h"
#include "MovimientoC.h"
#ifndef GUSANO_H_
#define GUSANO_H_
using namespace std;
class Gusano{
private:
	queue< pair<int,int> > points;
	int x,y;
	int gtam,con,mov;
	int tamx,tamy;
	bool adelante;
	MovimientoRS movRS;
	MovimientoC movC;
public:
	Gusano(int x0, int y0,int gtam, int tamx, int tamy);
	queue< pair<int,int> > setMov();
	pair<int,int> getNextLinePoint(int mov);
	void setNewEcuacion();
};

#endif
