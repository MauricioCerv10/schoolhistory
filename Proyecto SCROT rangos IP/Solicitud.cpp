#include <iostream>
#include <stdlib.h>
#include "Solicitud.h"
#include "PaqueteDatagrama.h"

using namespace std;

Solicitud::Solicitud(){
	socketLocal = new SocketDatagrama(0);
}

char* Solicitud::doOperation(char *IP, int puerto, char *arguments_, int calidad_){
	struct mensaje mensajeEnvio;
	memcpy(mensajeEnvio.nombreArchivo, arguments_, sizeof(mensajeEnvio.nombreArchivo));
	mensajeEnvio.calidad = calidad_;
	PaqueteDatagrama paqueteEnvio((char*)&mensajeEnvio, sizeof(struct mensaje), IP, puerto);
	PaqueteDatagrama paqueteRecibo(sizeof(struct mensaje));

	socketLocal->envia(paqueteEnvio);

	socketLocal->recibe(paqueteRecibo);
	memcpy((char*)&Recibido, paqueteRecibo.obtieneDatos(), sizeof(struct mensaje));
	dirIP = socketLocal->getClientIP();

	return (char*)&Recibido;
}

Solicitud::~Solicitud(){delete socketLocal;}

char* Solicitud::getIP(){return dirIP;}