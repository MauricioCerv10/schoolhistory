#define LIMITE_ARCHIVO 34

using namespace std;

struct mensaje{
	char messageType; //0= Solicitud, 1 = Respuesta
	char requestId; //Identificador del mensaje
	char tam[3];
	char nombreArchivo[5];
	char archivo[LIMITE_ARCHIVO+1];
	char estatus;
};