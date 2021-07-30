#include <iostream>
#include "Respuesta.h"

using namespace std;

int flipBit(int bit);

int main(void){
	Respuesta r(7200);
	struct mensaje mensajeEnvio;
	struct mensaje mensajeRecibo;

	int *numeros;
	int retorno;
	int nbd = 0;

	while(1){
		//cout << "Esperando mensaje..." << endl;
		//cout << "-----------> Saldo actual: " << nbd << " <-----------"<< endl;
		memcpy(&mensajeRecibo, r.getRequest(), sizeof(struct mensaje));
		//cout << ";;==================================" << endl;
		//cout << "Mensaje recibido dentro de Servidor.cpp." << endl;
		//cout << "IP del cliente: " << r.getIP() << endl;
		//cout << "Tipo de mensaje: " << mensajeRecibo.messageType << endl;
		//cout << "ID: " << mensajeRecibo.requestId << endl;
		//cout << "Saldo a agregar: " << mensajeRecibo.pesos << endl;
		//cout << ";;==================================" << endl;
		nbd += mensajeRecibo.pesos;
		mensajeEnvio.pesos = nbd;
		mensajeEnvio.messageType = flipBit(mensajeRecibo.messageType);
		mensajeEnvio.requestId = (mensajeRecibo.requestId)+1;
		r.sendReply((char *)&mensajeEnvio);
	}
	return 0;
}

int flipBit(int bit){
	if(bit == 0) return 1;
	else return 0;
}