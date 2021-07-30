// Definicion del formato de mensaje
struct mensaje{
	char messageType; //0= Solicitud, 1 = Respuesta
	int requestId; //Identificador del mensaje
	int argumentos[2];
};
