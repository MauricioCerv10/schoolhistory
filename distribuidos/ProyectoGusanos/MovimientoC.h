#include <iostream>
#include <vector>
#ifndef MOVIMIENTOC_H_
#define MOVIMIENTOC_H_
using namespace std;
class MovimientoC{
private:
	vector< vector<pair<int,int> > > circlePts;
	int iC,jC;
	int tamx,tamy;
public:
	MovimientoC(int tamx, int tamy);
	void circular(int rad, int xc, int yc);
	void setNewEcuacion(int x, int y);
	void savePoints(int x1, int y1, int xc, int yc);
	void clearCircle();
	pair<int,int> getNextCirclePoint();
	void sortCirPts();
	void movNextPoint();
	int getiC();
	int getjC();
	pair<int,int> validateP(int x, int y);
};

#endif

