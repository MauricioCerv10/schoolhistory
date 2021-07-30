#include <iostream>
#include "Respuesta.h"
#include "PaqueteDatagrama.h"

using namespace std;

Respuesta::Respuesta(int pl){
	socketLocal = new SocketDatagrama(pl);
}

struct mensaje* Respuesta::getRequest(void){
	PaqueteDatagrama paqueteRecibo(sizeof(struct mensaje));

	socketLocal->recibe(paqueteRecibo);
	memcpy((char*)&Recibido, paqueteRecibo.obtieneDatos(), sizeof(struct mensaje));
	dirIP = socketLocal->getClientIP();
	port = (int)(socketLocal->getClientPort());

	return &Recibido;
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