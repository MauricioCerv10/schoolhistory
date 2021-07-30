#include <iostream>
#include "Respuesta.h"

using namespace std;

int main(void){
	Respuesta r(7200);
	struct mensaje mensajeEnvio;
	struct mensaje mensajeRecibo;
	mensajeEnvio.pesos = 0;
	int nbd = 0;

	while(1){
		cout << "Esperando mensaje..." << endl;
		cout << "-----------> Saldo actual: " << nbd << " <-----------"<< endl;
		memcpy(&mensajeRecibo, r.getRequest(), sizeof(struct mensaje));
		if(mensajeRecibo.requestId != -1){
			cout << ";;==================================" << endl;
			cout << "Mensaje recibido dentro de Servidor.cpp." << endl;
			cout << "IP del cliente: " << r.getIP() << endl;
			cout << "Tipo de mensaje: " << mensajeRecibo.messageType << endl;
			cout << "ID: " << mensajeRecibo.requestId << endl;
			cout << "Saldo a agregar: " << mensajeRecibo.pesos << endl;
			cout << ";;==================================" << endl;
			nbd += mensajeRecibo.pesos;
			mensajeEnvio.pesos = nbd;
		}
		r.sendReply((char *)&mensajeEnvio);
	}
	return 0;
}