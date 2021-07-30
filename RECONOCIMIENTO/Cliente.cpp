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
	ifstream archivoEnviar;
	char* nombreLeer;
	string linea;
	int tamArchivo;
	int tamString;
	string convertir;
	stringstream strs;
	char nombreArchivo[5] = "voto";
	int contNom = 0;

	mensajeEnvio.tam[0] = '3';
	mensajeEnvio.tam[1] = '4';
	mensajeEnvio.tam[2] = '\0';

	if((archivoLeer = open(argv[2], O_RDONLY)) == -1){
		cout << "--!! ERROR: Error al leer." << endl;
		exit(-1);
	}
	for(int j = 0; j < 40; j++){
		read(archivoLeer, &reg, sizeof(reg));
		cout << reg.celular << endl;
		cout << reg.CURP << endl;
		cout << reg.partido << endl;
	}

	return 0;
}