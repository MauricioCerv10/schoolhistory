#define TAM_MAX_DATA 64000

// Definicion del formato de mensaje
struct mensaje{
	int messageType; //0= Solicitud, 1 = Respuesta
	unsigned int requestId; //Identificador del mensaje
	int pesos;
	char EXTRA[TAM_MAX_DATA];
};