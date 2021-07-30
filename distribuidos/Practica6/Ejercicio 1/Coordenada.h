#ifndef COORDENADA_H_
#define COORDENADA_H_
class Coordenada
{
private:
        float x;
        float y;
public:
        Coordenada(float = 0, float = 0);
        float obtenerX();
        float obtenerY();
};
#endif
