#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include <string>
#include "PaqueteDatagrama.h"

int puerto = 7200;

using namespace std;
int main(){}

PaqueteDatagrama::PaqueteDatagrama(string cad, unsigned int tam, string ipa, int port)
{
	struct sockaddr_in msg_to_server_addr, client_addr, info;
	int s, num[2], res;
	unsigned int size;
	const char * ipaux = ipa.c_str();
	datos = cad;
	ip = ipaux;
	longitud = tam;
	puerto = port;

	s = socket(AF_INET, SOCK_DGRAM, 0);
	/* rellena la dirección del servidor */
	bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
	msg_to_server_addr.sin_family = AF_INET;
	msg_to_server_addr.sin_addr.s_addr = inet_addr(ipaux);
	//msg_to_server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	msg_to_server_addr.sin_port = htons(puerto);

	/* rellena la direcciòn del cliente*/
	bzero((char *)&client_addr, sizeof(client_addr));
	client_addr.sin_family = AF_INET;
	client_addr.sin_addr.s_addr = INADDR_ANY;

	/*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
	client_addr.sin_port = htons(6666);
	bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));
	datos = cad;

	bzero((char *)&info, sizeof(info));

	recvfrom(s, (char *)&datos, sizeof(int), 0, (struct sockaddr *) &info, &tam);

}

PaqueteDatagrama::PaqueteDatagrama(unsigned int tam): longitud(tam){}

string PaqueteDatagrama::obtieneDireccion(){return ip; }

unsigned int PaqueteDatagrama::obtieneLongitud(){return longitud; }

int obtienePuerto(){return puerto; }

string PaqueteDatagrama::obtieneDatos(){return datos; }

void PaqueteDatagrama::inicializaPuerto(int port){puerto = port; }

void PaqueteDatagrama::inicializaIp(string cad){ip = cad; }

void PaqueteDatagrama::inicializaDatos(string cadena){datos = cadena; }
