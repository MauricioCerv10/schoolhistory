#include <iostream>
#include "Respuesta.h"
#include "PaqueteDatagrama.h"

using namespace std;

int flipBit(int bit);

Respuesta::Respuesta(int pl){
	socketLocal = new SocketDatagrama(pl);
	requestIdPrev = -1;
}

struct mensaje* Respuesta::getRequest(void){
	PaqueteDatagrama paqueteRecibo(sizeof(struct mensaje));
	cout << "requestIdPrev: " << requestIdPrev << endl;
	socketLocal->recibe(paqueteRecibo);
	if(requestIdPrev == ((struct mensaje*)(paqueteRecibo.obtieneDatos()))->requestId){
		Recibido.requestId = -1;
		return &Recibido;
	}
	else{
		memcpy((char*)&Recibido, paqueteRecibo.obtieneDatos(), sizeof(struct mensaje));
		dirIP = socketLocal->getClientIP();
		port = (int)(socketLocal->getClientPort());
		requestIdPrev = Recibido.requestId;
		return &Recibido;
	}
}

void Respuesta::sendReply(char *respuesta){
	PaqueteDatagrama paqueteEnvio(respuesta, sizeof(struct mensaje), dirIP, htons(port));
	((struct mensaje*)(paqueteEnvio.obtieneDatos()))->messageType = flipBit(Recibido.messageType);
	((struct mensaje*)(paqueteEnvio.obtieneDatos()))->requestId = Recibido.requestId;
	socketLocal->envia(paqueteEnvio);
	return;
}

Respuesta::~Respuesta(){delete socketLocal;}

char* Respuesta::getIP(){return dirIP;}
int Respuesta::getPort(){return port;}

int flipBit(int bit){
	if(bit == 0) return 1;
	else return 0;
}