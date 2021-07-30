#include "gfx.h"
#include <unistd.h>
#include "Gusano.h"
using namespace std;

int main(){
	cout<<"Introduzca el numero de gusanos\n";
	int n; cin>>n;
	gfx_open(800, 600, "Ejemplo Micro Animacion GFX");
	gfx_color(0,200,100);
	vector<Gusano> gusanos;
	for(int i = 0;i<n;i++){
		int x = rand()%800;
		int y = rand()%600;
		Gusano gus(x,y,50,800,600);
		gusanos.push_back(gus);
	}
	while(1){
		gfx_clear();
		for(int i = 0; i<n;i++){
			queue< pair<int,int> > q = gusanos[i].setMov();
			for(int j = 0; j<q.size();j++){
				pair<int,int> point = q.front();
				q.pop();
				gfx_line(point.first,point.second,point.first,point.second);
			}
		}
		gfx_flush();
		usleep(20666);
	}
	return 0;
}  //24 por segundo}return 0
