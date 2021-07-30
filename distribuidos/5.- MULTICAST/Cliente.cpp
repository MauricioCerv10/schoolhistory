#include <iostream>
#include "PaqueteDatagrama.h"
#include "SocketMulticast.h"
#include "Mensaje.h"
#include <string.h>

using namespace std;

struct registro{
	char celular[11];
	char CURP[19];
	char partido[4];
};

int main(int argc, char* argv[]){
	if(argc != 4){
		cout << "Mala invocación del programa. Intente:" << endl;
		cout << "./cliente direccion_multicast puerto nombre_del_archivo" << endl;
		return 0;
	}

	srand(time(NULL));
	SocketMulticast socketLocal(0);

	struct registro reg;
	struct mensaje mensajeEnvio;
	struct mensaje mensajeRecibo;

	mensajeEnvio.argumentos[0] = 0;
	mensajeEnvio.argumentos[1] = 0;

	int noMensaje = 0;
	int nb = 0;
	int archivoLeer;

	socketLocal.inisU(7201);

	if((archivoLeer = open(argv[3], O_RDONLY)) == -1){
		cout << "--!! ERROR: Error al leer." << endl;
		exit(-1);
	}

	for(;;){
		read(archivoLeer, &reg, sizeof(reg));
		memcpy(&mensajeEnvio.archivo,(char*)&reg,sizeof(reg));
		//int deposito = rand()%10;
		//nb += deposito;
		mensajeEnvio.requestId = noMensaje;
		//mensajeEnvio.argumentos[0] = deposito;
		//cout << "========================================" << endl;
		//cout << "Quiero enviar:	 " << mensajeEnvio.argumentos[0] << endl;
		cout << "ID del mensaje: " << mensajeEnvio.requestId << endl << endl;
		
		PaqueteDatagrama paqueteEnvio((char*)&mensajeEnvio, sizeof(struct mensaje), argv[1], atoi(argv[2]));
        	
		//cout << "Depositado: " << (int)mensajeEnvio.argumentos[0] << endl;
		//cout << "Saldo : " << nb << endl << endl;

		int intentos = 5;
		for(int i = 1; i<=intentos; i++){
			if(socketLocal.enviaConfiable(paqueteEnvio, 1, 1) != -1){
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
