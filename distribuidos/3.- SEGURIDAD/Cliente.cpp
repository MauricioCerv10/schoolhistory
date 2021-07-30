#include <iostream>
#include <fstream>
#include <sstream>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "Solicitud.h"

/*
Variables foráneas:
	->LIMITE_ARCHIVO
	->Ubicación: Mensaje.h

Entidades foráneas:
	->struct mensaje
	->Ubicación: Mensaje.h

	->Solicitud
	->Ubicación: Solicitud.h
*/

int flipBit(int bit);

using namespace std;

struct registro{
	char celular[11];
	char CURP[19];
	char partido[4];
};

int main(int argc, char* argv[]){
	if(argc != 3){
		cout << "Modo de uso: " << argv[0] << " direccion_ip_del_servidor nombre_del_archivo" << endl;
		return 0;
	}
	else if(strlen(argv[1])>16){
		cout << "--!! ERROR: IP inválida. Inténtelo de nuevo." << endl;
		return 0;
	}
	Solicitud s;
	struct registro reg;
	struct mensaje mensajeEnvio;
	struct mensaje mensajeRecibo;
	struct timeval timestamp;

	
	int archivoLeer;
	mensajeEnvio.messageType = 0;
	mensajeEnvio.requestId = 0;

	if((archivoLeer = open(argv[2], O_RDONLY)) == -1){
		cout << "--!! ERROR: Error al leer." << endl;
		exit(-1);
	}
	
	
	for(int j = 0; j < 1000; j++){
		
		read(archivoLeer, &reg, sizeof(reg));
		memcpy(&mensajeEnvio.archivo,(char*)&reg,sizeof(reg));
		memcpy(&mensajeRecibo, s.doOperation(argv[1], 7200, (char*)(&mensajeEnvio)), sizeof(struct mensaje));
		memcpy(&timestamp,&mensajeRecibo.TIMESTAMP,sizeof(struct timeval));
		cout<< "TIMESTAMP recibido : " <<endl;
		cout << timestamp.tv_sec << endl;
		cout << timestamp.tv_usec << endl;

		cout << ";;========================================" << endl;
		cout << "Mensaje recibido dentro de Cliente.cpp." << endl;
		cout << "IP de quién lo envió: " << s.getIP() << endl;
		cout << "Tipo de mensaje: " << mensajeRecibo.messageType << endl;
		cout << "ID: " << mensajeRecibo.requestId << endl;
		cout << ";;========================================" << endl;
		mensajeEnvio.requestId = (mensajeRecibo.requestId)+1;
		
	}
	
	return 0;
}
int flipBit(int bit){
	if(bit == 0) return 1;
	else return 0;
}
