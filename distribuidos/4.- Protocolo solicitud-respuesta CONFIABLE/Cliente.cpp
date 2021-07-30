#include <iostream>
#include "Solicitud.h"

using namespace std;

int flipBit(int bit);

int main(int argc, char* argv[]){
	if(argc != 3){
		cout << "Mala invocación del programa. Intente:" << endl;
		cout << "./cliente direccion_ip_del_servidor iteraciones" << endl;
		return 0;
	}
	srand(time(NULL));
	Solicitud s;
	struct mensaje mensajeRecibo;
	struct mensaje mensajeEnvio;
	mensajeEnvio.messageType = 0;
	mensajeEnvio.requestId = 0;
	mensajeEnvio.pesos = 0;
	int verificar = 0;

	for(int f = 0; f < atoi(argv[2]); f++){
		mensajeEnvio.pesos += (int)(rand()%(9-1+1)+1);
		verificar += mensajeEnvio.pesos;
		memcpy((char*)&mensajeRecibo, s.doOperation(argv[1], 7200, (char*)(&mensajeEnvio)), sizeof(struct mensaje));
		if(mensajeRecibo.messageType != flipBit(mensajeEnvio.messageType)){cout << "Ups, error de messageType en iteración: " << f << endl; break;}
		if(mensajeRecibo.requestId != mensajeEnvio.requestId){cout << "Ups, error de requestId en iteración: " << f << endl; break;}
		if(mensajeRecibo.pesos != verificar){cout << "Ups, error de pesos en iteración: " << f << endl; break;}
		cout << ";;========================================" << endl;
		cout << "Mensaje recibido dentro de Cliente.cpp." << endl;
		cout << "IP de quién lo envió: " << s.getIP() << endl;
		cout << "Tipo de mensaje: " << mensajeRecibo.messageType << endl;
		cout << "ID: " << mensajeRecibo.requestId << endl;
		cout << "Respuesta del servidor: " << mensajeRecibo.pesos << endl;
		cout << ";;========================================" << endl;
		mensajeEnvio.requestId = (mensajeRecibo.requestId)+1;
	}
	cout << "Valor final:" << verificar << endl;
	return 0;
}

int flipBit(int bit){
	if(bit == 0) return 1;
	else return 0;
}