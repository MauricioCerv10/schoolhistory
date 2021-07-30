#include <iostream>
#include "Solicitud.h"

using namespace std;

int main(int argc, char* argv[]){
	if(argc != 4){
		cout << "Mala invocación del programa. Intente:" << endl;
		cout << "./cliente direccion_ip_del_servidor puerto_del_servidor iteraciones" << endl;
		return 0;
	}
	srand(time(NULL));
	Solicitud s;
	struct mensaje mensajeRecibo;
	struct mensaje mensajeEnvio;
	mensajeEnvio.pesos = 0;
	int verificar = 0;

	for(int f = 0; f < atoi(argv[3]); f++){
		mensajeEnvio.pesos = (int)(rand()%(9-1+1)+1);
		cout << ";;========================================" << endl;
		cout << "Quiero depositar: " << mensajeEnvio.pesos << endl;
		cout << "-----------> Según yo, saldo actual en cuenta: " << verificar << " <-----------" << endl;
		verificar += mensajeEnvio.pesos;
		memcpy((char*)&mensajeRecibo, s.doOperation(argv[1], atoi(argv[2]), (char*)(&mensajeEnvio)), sizeof(struct mensaje));
		if(mensajeRecibo.pesos != verificar){cout << "Ups, error de pesos en iteración: " << f << endl; break;}
		cout << "Mensaje recibido dentro de Cliente.cpp." << endl;
		cout << "IP de quién lo envió: " << s.getIP() << endl;
		cout << "Tipo de mensaje: " << mensajeRecibo.messageType << endl;
		cout << "ID: " << mensajeRecibo.requestId << endl;
		cout << "Respuesta del servidor: " << mensajeRecibo.pesos << endl;
		cout << ";;========================================" << endl;
	}
	cout << "Saldo final:" << verificar << endl;
	return 0;
}