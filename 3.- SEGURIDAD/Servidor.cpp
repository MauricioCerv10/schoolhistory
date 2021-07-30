#include <iostream>
#include <fstream>
#include <string>
#include <fcntl.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include "Respuesta.h"
#include "Registros.h"

using namespace std;

int main(void){
	Respuesta r(7200);

	struct timeval timestamp;
	struct mensaje mensajeEnvio;
	struct mensaje mensajeRecibo;
	
	vector<Registros> baseDeDatos;
	vector<Registros>::iterator j, k;

	char *archivoRecibo;
	int destino;

	if(( destino = open("copia.txt",O_WRONLY|O_TRUNC|O_CREAT,0666) )  == -1){
		cout << "Error al escribir en el archivo\n";
		exit(-1);
	}

	while(1){
		cout << "Esperando mensaje..." << endl;
		memcpy(&mensajeRecibo, r.getRequest(), sizeof(struct mensaje));
		if(mensajeRecibo.messageType != -1){ /// Duda en esta linea
			gettimeofday(&timestamp, NULL);
			struct registro reg;
			cout << "==================================" << endl;
			memcpy(&reg, mensajeRecibo.archivo,sizeof(reg));
			write(1,&reg,sizeof(reg));
			write(destino,&reg,sizeof(reg));
			baseDeDatos.push_back(Registros((char*)&reg, (char*)&timestamp));
			/*archivoRecibo = new char[atoi(mensajeRecibo.tam)];
			memcpy(archivoRecibo, mensajeRecibo.archivo, atoi(mensajeRecibo.tam));
			archivoRecibo[atoi(mensajeRecibo.tam)] = '\0';
			archivoGuardar.open(mensajeRecibo.nombreArchivo);
			archivoGuardar.write(archivoRecibo, atoi(mensajeRecibo.tam));

			if(archivoGuardar.is_open()){mensajeEnvio.estatus = '0'; cout << "Guardado." << endl;}
			else{mensajeEnvio.estatus = '1'; cout << "Fallo en escritura." << endl;}

			memcpy(mensajeEnvio.nombreArchivo, mensajeRecibo.nombreArchivo, sizeof(mensajeEnvio.nombreArchivo));
			archivoGuardar.close();
			delete[] archivoRecibo;*/
			memcpy(mensajeEnvio.TIMESTAMP, (char*)&timestamp, sizeof(struct timeval));
			mensajeEnvio.estatus = 0;
		}
		r.sendReply((char *)&mensajeEnvio);
	}
	return 0;
}