#include "Rectangulo.h"
#include "Coordenada.h"
#include "Ortaedro.h"
#include <iostream>
using namespace std;

int main()
{
        Ortaedro ort(   3, 2, 3, 0, 2, 0, // rectangulo superior
			3, 0, 3, 0, 0, 0,// rectangulo inferior
			0, 2, 3, 0, 0, 0,//lado uno
			3, 2, 3, 0, 0, 3,// lado dos
			3, 2, 3, 3, 0, 0,// lado tres
			3, 2, 0, 0, 0, 0// lado cuatro
	);

        cout << "Calculando el área de un rectángulo dadas sus vertices:\n";
        ort.imprimeVertices();
        cout << "El área del ortaedro es = " << ort.areaO() << endl;
        cout << "El volumen del ortaedro es = " << ort.volumen() << endl;
        return 0;
}


