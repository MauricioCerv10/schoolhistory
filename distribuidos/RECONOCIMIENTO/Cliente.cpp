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

struct registro{
	char celular[11];
	char CURP[19];
	char partido[4];
};

using namespace std;

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
	int archivoLeer;
	mensajeEnvio.messageType = 0;
	mensajeEnvio.requestId = 0;

	if((archivoLeer = open(argv[2], O_RDONLY)) == -1){
		cout << "--!! ERROR: Error al leer." << endl;
		exit(-1);
	}
	
	
	for(int j = 0; j < 40; j++){
		
		read(archivoLeer, &reg, sizeof(reg));
		memcpy(&mensajeEnvio.archivo,(char*)&reg,sizeof(reg));
		memcpy((char*)&mensajeRecibo, s.doOperation(argv[1], 7200, (char*)(&mensajeEnvio)), sizeof(struct mensaje));
		if(mensajeRecibo.messageType != flipBit(mensajeEnvio.messageType) ){cout << "Ups, error de messageType en iteración: " << j << endl; break;}
		if(mensajeRecibo.requestId != mensajeEnvio.requestId){cout << "Ups, error de requestId en iteración: " << j << endl; break;}
		//if(mensajeRecibo.pesos != verificar){cout << "Ups, error de pesos en iteración: " << f << endl; break;}
		cout << ";;========================================" << endl;
		cout << "Mensaje recibido dentro de Cliente.cpp." << endl;
		cout << "IP de quién lo envió: " << s.getIP() << endl;
		cout << "Tipo de mensaje: " << mensajeRecibo.messageType << endl;
		cout << "ID: " << mensajeRecibo.requestId << endl;
		cout << ";;========================================" << endl;
		mensajeEnvio.requestId = (mensajeRecibo.requestId)+1;
		
		/*read(archivoLeer, &reg, sizeof(reg));
		cout << reg.celular << endl;
		cout << reg.CURP << endl;
		cout << reg.partido << endl;
		
		s.doOperation(argv[1],7200,(char*)&reg);*/
	}
	
	return 0;
}
int flipBit(int bit){
	if(bit == 0) return 1;
	else return 0;
}
