#include <iostream>
#include "Solicitud.h"
#include "PaqueteDatagrama.h"

using namespace std;

Solicitud::Solicitud(){
	socketLocal = new SocketDatagrama(0);
}

char* Solicitud::doOperation(char *IP, int puerto, int arguments_){
	struct mensaje mensajeEnvio;
	mensajeEnvio.messageType=0;
	mensajeEnvio.requestId=0;
	mensajeEnvio.pesos = arguments_;

	PaqueteDatagrama paqueteEnvio((char*)&mensajeEnvio, sizeof(struct mensaje), IP, puerto);
	PaqueteDatagrama paqueteRecibo(sizeof(struct mensaje));

	int n;
	for(int it = 0; it < 7; it++){
		socketLocal->envia(paqueteEnvio);
		n = socketLocal->recibeTimeout(paqueteRecibo, 2, 500000);
		if(n == -1){
			if(it != 6) cout << "No se recibió ningún mensaje. Intentando de nuevo..." << endl;
			else {
				cout << "--!! ADVERTENCIA: Servidor no disponible." << endl;
				cout << "Imposible contactar con el servidor. Inténtelo de nuevo más tarde." << endl;
				exit(0);
			}
		}
		else if (n == -2){
			cout << "--!! ERROR: Error en recvfrom." << endl;
			exit(0);
		}
		else {
			memcpy((char*)&Recibido, paqueteRecibo.obtieneDatos(), sizeof(struct mensaje));
			dirIP = socketLocal->getClientIP();
			break;
		}
	}
	memcpy((char*)&Recibido, paqueteRecibo.obtieneDatos(), sizeof(struct mensaje));
	dirIP = socketLocal->getClientIP();
	return (char*)&Recibido;
}

Solicitud::~Solicitud(){delete socketLocal;}

char* Solicitud::getIP(){return dirIP;}