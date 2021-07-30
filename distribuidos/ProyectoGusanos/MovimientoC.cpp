#include "MovimientoC.h"
#include "gfx.h"
#include <unistd.h>
#include <math.h>
#include <algorithm>
using namespace std;

MovimientoC::MovimientoC(int tamx, int tamy):tamx(tamx), tamy(tamy){
	for(int i = 0; i<8; i++){ vector<pair<int,int>> vec; circlePts.push_back(vec);}
	iC = 0; jC = 0; 
}

void MovimientoC::circular(int rad, int xc, int yc){
	int x1 = 0 , y1 = rad;
        int decesionParameter = 3 - 2 * rad;
        savePoints(xc, yc, x1, y1);
        while (y1 >= x1){
        	x1++;
                if(decesionParameter > 0)
                {
                	y1--;
                	decesionParameter = decesionParameter + 4 * (x1 - y1) + 10;
                }
                else
                	decesionParameter = decesionParameter + 4 * x1 + 6;
                savePoints(xc, yc, x1, y1); 
        }
}

void MovimientoC::setNewEcuacion(int x, int y){
	int rad = (rand()%40) + 3;
	circular(rad,x+rad,y);
}

bool ordena(pair<int,int> a, pair<int,int> b){
	if(a.first < b.first) return true;
	else if(a.first == b.first && a.second < b.second) return true;
	else return false;
}
bool ordena2(pair<int,int> a, pair<int,int> b){
        if(a.first > b.first) return true;
        else if(a.first == b.first && a.second < b.second) return true;
        else return false;
}

void MovimientoC::sortCirPts(){
	for(int i = 1; i<4; i += 2){
		sort(circlePts[i].begin(),circlePts[i].end(),ordena);
	}
	for(int i = 5; i<8; i += 2){
                sort(circlePts[i].begin(),circlePts[i].end(),ordena2);
        }

}

pair<int,int> MovimientoC::validateP(int x, int y){
	
	if(x<0) x = tamx + x;
	else if(x > tamx) y = x%tamx;
	
	if(y<0) y = tamy + y;
	else if(y > tamy) y = y%tamy;
	
	return make_pair(x,y);
}

void MovimientoC::savePoints(int xc, int yc, int x1, int y1){
	circlePts[0].push_back( validateP( xc-y1 , yc-x1 ) );
	circlePts[1].push_back( validateP( xc-x1 , yc-y1 ) );
	circlePts[2].push_back( validateP( xc+x1 , yc-y1 ) );
	circlePts[3].push_back( validateP( xc+y1 , yc-x1 ) );
	circlePts[4].push_back( validateP( xc+y1 , yc+x1 ) );
	circlePts[5].push_back( validateP( xc+x1 , yc+y1 ) );
	circlePts[6].push_back( validateP( xc-x1 , yc+y1 ) );
	circlePts[7].push_back( validateP( xc-y1 , yc+x1 ) );
	sortCirPts();
}

void MovimientoC::clearCircle(){
	for(int i = 0; i<8;i++){
        	circlePts[i].erase(circlePts[i].begin(),circlePts[i].end());
        }
}
pair<int,int> MovimientoC::getNextCirclePoint(){
	return circlePts[iC][jC];
}
void MovimientoC::movNextPoint(){
	jC++;
	if(jC >= circlePts[0].size()){ jC = 0; iC++;} 
	if(iC >= 8) iC = 0;
}
int MovimientoC::getiC(){
	return iC;
}
int MovimientoC::getjC(){
	return jC;
}

