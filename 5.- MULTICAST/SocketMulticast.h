#ifndef SOCKETMULTICAST_H_
#define SOCKETMULTICAST_H_
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"

class SocketMulticast{
	private:
		struct sockaddr_in grupoMulticast;
		struct ip_mreq multicast;
		int s; //ID socket
		int aa;
		int con;
		int noMensaje;
		int noRecep;
		SocketDatagrama sU;
	public:
		SocketMulticast(int a);
		~SocketMulticast();
		int recibe(PaqueteDatagrama &p);
		int envia(PaqueteDatagrama &p, unsigned char ttl);
		//Se une a un grupo multicast, recibe la IP multicast
		void unirseGrupo(char * dir);
		//Se sale de un grupo multicast, recibe la IP multicast
		void salirseGrupo(char * dir);
		void inisU(int p);
		int enviaU(PaqueteDatagrama &p);
		char* getClientIP();
		unsigned short getClientPort();
		int recibeU(PaqueteDatagrama &p);
		int enviaConfiable(PaqueteDatagrama & p, unsigned char ttl, int num_receptores);
		int recibeConfiable(PaqueteDatagrama & p);
};

#endif
