#include <iostream>
#include "PaqueteDatagrama.h"
#include "SocketMulticast.h"
#include "Mensaje.h"
#include <string.h>

using namespace std;

int main(int argc, char* argv[]){
	if(argc != 4){
		cout << "Mala invocación del programa. Intente:" << endl;
		cout << "./cliente direccion_multicast puerto numero_de_receptores" << endl;
		return 0;
	}
	srand(time(NULL));
	SocketMulticast socketLocal(0);
	struct mensaje mensajeEnvio;
	struct mensaje mensajeRecibo;
	mensajeEnvio.argumentos[0] = 0;
	mensajeEnvio.argumentos[1] = 0;
	int noMensaje = 0;
	int nb = 0;
	socketLocal.inisU(7201);
	for(int j = 0; j < 200; j++){
		int deposito = rand()%10;
		nb += deposito;
		mensajeEnvio.requestId = noMensaje;
		mensajeEnvio.argumentos[0] = deposito;
		//cout << "========================================" << endl;
		//cout << "Quiero enviar:	 " << mensajeEnvio.argumentos[0] << endl;
		cout << "ID del mensaje: " << mensajeEnvio.requestId << endl << endl;
		
		PaqueteDatagrama paqueteEnvio((char*)&mensajeEnvio, sizeof(struct mensaje), argv[1], atoi(argv[2]));
        	
		//cout << "Depositado: " << (int)mensajeEnvio.argumentos[0] << endl;
		cout << "Saldo : " << nb << endl << endl;

		int intentos = 5;
		for(int i = 1; i<=intentos; i++){
			if(socketLocal.enviaConfiable(paqueteEnvio, 1, atoi(argv[3])) != -1){
				cout<<"Mensajes enviados Exitosamente\n\n";
				break;
			}
			if(i == intentos){
				cout<<"Error Servidor(es) caido(s)\n\n";
				exit(0);
			} 
			cout << "Esperando todas las respuestas.. \n Intentando de nuevo... \n\n";
			//sleep(1);
		}
		noMensaje++;
		//sleep(.05);
	}

	return 0;
}
