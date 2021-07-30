#define LIMITE_ARCHIVO 34

using namespace std;

struct mensaje{
	int messageType; //0= Solicitud, 1 = Respuesta
	int requestId; //Identificador del mensaje
	//int tam;
	//char nombreArchivo[5];
	int estatus;
	char archivo[33];
};
