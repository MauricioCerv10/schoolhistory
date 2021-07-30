#include "Coordenada.h"
#include <iostream>
using namespace std;

Coordenada::Coordenada(float xx, float yy) : x(xx), y(yy)
{ }

float Coordenada::obtenerX()
{
        return x;
}

float Coordenada::obtenerY()
{
        return y;
}


