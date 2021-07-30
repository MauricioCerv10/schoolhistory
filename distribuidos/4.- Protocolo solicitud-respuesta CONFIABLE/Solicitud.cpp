#include <iostream>
#include "Solicitud.h"
#include "PaqueteDatagrama.h"

using namespace std;

Solicitud::Solicitud(){
	socketLocal = new SocketDatagrama(0);
	request = 0;
}

char* Solicitud::doOperation(char *IP, int puerto, char* args){
	PaqueteDatagrama paqueteEnvio(args, sizeof(struct mensaje), IP, puerto);
	PaqueteDatagrama paqueteRecibo(sizeof(struct mensaje));
	int n;
	for(int it = 0; it < 7; it++){
		socketLocal->envia(paqueteEnvio);
		n = socketLocal->recibeTimeout(paqueteRecibo, 1, 500000);
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
			request++;
			break;
		}
	}
	return (char*)&Recibido;
}

Solicitud::~Solicitud(){delete socketLocal;}

char* Solicitud::getIP(){return dirIP;}