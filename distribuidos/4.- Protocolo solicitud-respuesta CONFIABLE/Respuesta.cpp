#include <iostream>
#include "Respuesta.h"
#include "PaqueteDatagrama.h"

using namespace std;

Respuesta::Respuesta(int pl){
	socketLocal = new SocketDatagrama(pl);
	requestIdPrev = 0;
}

struct mensaje* Respuesta::getRequest(void){
	PaqueteDatagrama paqueteRecibo(sizeof(struct mensaje));
	cout<<"RidPrev: "<<requestIdPrev<<endl;
	socketLocal->recibe(paqueteRecibo);
	if(requestIdPrev == ((struct mensaje*)(paqueteRecibo.obtieneDatos()))->requestId && ((struct mensaje*)(paqueteRecibo.obtieneDatos()))->requestId != 0){
		Recibido.pesos = 0;
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
	socketLocal->envia(paqueteEnvio);
	//cout << "Respuesta enviada." << endl;
	return;
}

Respuesta::~Respuesta(){delete socketLocal;}

char* Respuesta::getIP(){return dirIP;}
int Respuesta::getPort(){return port;}
