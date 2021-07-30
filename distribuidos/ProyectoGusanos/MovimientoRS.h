#include <iostream>
#include <vector>
#ifndef MOVIMIENTORS_H_
#define MOVIMIENTORS_H_
using namespace std;

class MovimientoRS{
private:
	int m,b;
        int tamx,tamy;
public:
        MovimientoRS(int tamx, int tamy);
        pair<int,int> recta(int sigmov);
        pair<int,int> serpiente(int sigmov);
	void setNewEcuacion(int x, int y);
};
#endif

