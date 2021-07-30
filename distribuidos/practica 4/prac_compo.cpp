#include "Rectangulo.h"
#include "Coordenada.h"
#include "Ortaedro.h"
#include <iostream>
using namespace std;

int main()
{
        Ortaedro ort(   0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0
	);

        cout << "Calculando el área de un rectángulo dadas sus vertices:\n";
        ort.imprimeVertices();
        cout << "El área del ortaedro es = " << ort.areaO() << endl;
        cout << "El volumen del ortaedro es = " << ort.volumen() << endl;
        return 0;
}


