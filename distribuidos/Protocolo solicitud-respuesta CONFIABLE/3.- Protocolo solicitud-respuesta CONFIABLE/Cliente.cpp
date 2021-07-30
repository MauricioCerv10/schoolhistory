#include <iostream>
#include "Solicitud.h"

using namespace std;

int main(int argc, char* argv[]){
	if(argc != 3){
		cout << "Mala invocación del programa. Intente:" << endl;
		cout << "./cliente direccion_ip_del_servidor iteraciones" << endl;
		return 0;
	}
	Solicitud s;
	
	struct mensaje mensajeRecibo;
	int n;
	int verificar = 0;

	for(int f = 0; f < atoi(argv[2]); f++){
		n = (int)(rand()%(9-1+1)+1);
		verificar += n;
		memcpy((char*)&mensajeRecibo, s.doOperation(argv[1], 7200, n), sizeof(struct mensaje));
		if(mensajeRecibo.pesos != verificar){cout << "Ups, error en iteración: " << f << endl; break;}
		//cout << ";;========================================" << endl;
		//cout << "Mensaje recibido dentro de Cliente.cpp." << endl;
		//cout << "IP de quién lo envió: " << s.getIP() << endl;
		//cout << "Tipo de mensaje: " << mensajeRecibo.messageType << endl;
		//cout << "ID: " << mensajeRecibo.requestId << endl;
		//cout << "Respuesta del servidor: " << mensajeRecibo.pesos << endl;
		//cout << ";;========================================" << endl;
	}
	cout << "Valor final:" << verificar << endl;
	return 0;
}