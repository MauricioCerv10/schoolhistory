#ifndef UDPCLIENT_H_
#define UDPCLIENT_H_

#include <stdio.h>
#include <iostream>
#include <string.h>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"

class UDPClient{
	private:
		char buffer[450];
		int numpcs;
		char ips[40][30];
		char opc[10];
		char numt[4];
	public:
		UDPClient(int numPcs);
		void inicializaObj(char* argv[]);
		int getLastOct(char* cadena);
		char* intToS(int x, char* num);
		void asignaIps(char* cadena, int length, int lastOct);
		void inicializarCads();
		void descargaImagenes();
		char* obtenerDatos();
};

#endif
