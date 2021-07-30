#ifndef SOCKETDATAGRAMA_H_
#define SOCKETDATAGRAMA_H_
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "PaqueteDatagrama.h"

class SocketDatagrama{
	private:
		struct sockaddr_in direccionLocal;
		struct sockaddr_in direccionForanea;
		int s; //ID socket

	public:
		SocketDatagrama(int a);
		~SocketDatagrama();
		//~SocketDatagrama();

		//Recibe un paquete tipo datagrama proveniente de este socket
		int recibe(PaqueteDatagrama &p);

		//Envía un paquete tipo datagrama desde este socket
		int envia(PaqueteDatagrama &p);
};

#endif