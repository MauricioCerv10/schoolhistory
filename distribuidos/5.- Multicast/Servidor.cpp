#include <iostream>
#include "PaqueteDatagrama.h"
#include "SocketMulticast.h"
#include <string.h>
#include "Mensaje.h"


using namespace std;

int main(void){
	SocketMulticast socketLocal(7200);
        socketLocal.unirseGrupo("224.0.0.1");
	struct mensaje mensajeRecibo;
	struct mensaje mensajeEnvio;
	int noMensaje = 0;
	int nb = 0;
	while(1){
		cout << "Esperando mensaje con ID :"<< noMensaje << "\n\n";
		
		PaqueteDatagrama paqueteRecibo(sizeof(struct mensaje));
        	socketLocal.recibe(paqueteRecibo);
        	cout <<  "Mensaje Recibido\n";
		cout << "Direccion: " << paqueteRecibo.obtieneDireccion() << endl;
		
		memcpy((char*)&mensajeRecibo, paqueteRecibo.obtieneDatos(), sizeof(struct mensaje));
		cout << "ID recibido : " << mensajeRecibo.requestId << endl;
		
		if(mensajeRecibo.requestId < noMensaje ){
			cout << "Mensaje Repetido. Decartando...  \nEsperando Nuevo Mensaje" << endl;
			
			mensajeEnvio.argumentos[0] = 0; 
                	PaqueteDatagrama pEnvia((char*)&mensajeEnvio, sizeof(struct mensaje) ,paqueteRecibo.obtieneDireccion(),
                                                7201);
                	//sleep(1);
                	socketLocal.enviaU(pEnvia);

			continue;
		}
		
		//cout << "Mensaje nuevo recibido: "<< mensajeRecibo.requestId <<endl;
		nb += mensajeRecibo.argumentos[0];
		cout << "Saldo: " << nb << endl;
		
		memcpy((char*)&mensajeEnvio, (char*)&mensajeRecibo, sizeof(struct mensaje));
		mensajeEnvio.argumentos[0] = 0;
		mensajeEnvio.requestId = noMensaje; noMensaje++;
		PaqueteDatagrama pEnvia((char*)&mensajeEnvio, sizeof(struct mensaje) ,paqueteRecibo.obtieneDireccion(),
						7201);
		//sleep(1);
		socketLocal.enviaU(pEnvia);
	}
	
	return 0;
}
