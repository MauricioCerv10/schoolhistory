#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "SocketMulticast.h"
#include "PaqueteDatagrama.h"
#include "Mensaje.h"
using namespace std;

SocketMulticast::SocketMulticast(int a){
	s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if(s < 0){
		cout << "--!!ERROR FATAL: Error al llamar a la función socket." << endl;
		exit(0);
	}

	if(a == 0){ /*Es emisor*/
		unsigned char TTL = 1;
		if(setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *) &TTL, sizeof(TTL)) < 0){
			cout << "--!!ERROR FATAL: Error al llamar a la función setsockopt." << endl;
			exit(0);
		}
	}
	else{ /*Es receptor*/
		int reuse = 1;
		if (setsockopt(s, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse)) == -1) {
			cout << "--!!ERROR FATAL: Error al llamar a la función setsockopt." << endl;
			exit(0);
		}
	}

	grupoMulticast.sin_family = AF_INET;
	grupoMulticast.sin_port = htons(a);
	grupoMulticast.sin_addr.s_addr = inet_addr("224.0.0.1");
	if(a != 0) /*Es receptor*/ bind(s, (struct sockaddr*)&grupoMulticast, sizeof(grupoMulticast));

	multicast.imr_multiaddr.s_addr = grupoMulticast.sin_addr.s_addr;
	multicast.imr_interface.s_addr = htonl(INADDR_ANY);
	con = 0;
	aa = a;
	
}

SocketMulticast::~SocketMulticast(){
	close(s);
}

int SocketMulticast::recibe(PaqueteDatagrama &p){
	char dat[p.obtieneLongitud()];
	unsigned int clileng = sizeof(grupoMulticast);
	recvfrom(s, dat, p.obtieneLongitud()*sizeof(char), 0, (struct sockaddr *) &grupoMulticast, &clileng);
	p.inicializaDatos(dat);
	char str[16];
	inet_ntop(AF_INET, &grupoMulticast.sin_addr.s_addr, str, 16);
	p.inicializaIp(str);
	p.inicializaPuerto(grupoMulticast.sin_port);
	return 0;
}

int SocketMulticast::envia(PaqueteDatagrama &p, unsigned char ttl){
	inet_pton(AF_INET, p.obtieneDireccion(), &grupoMulticast.sin_addr);
	grupoMulticast.sin_port = htons(p.obtienePuerto());
	sendto(s, p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *) &grupoMulticast, sizeof(grupoMulticast));
	return 0;
}

void SocketMulticast::unirseGrupo(char * dir){
	multicast.imr_multiaddr.s_addr = inet_addr(dir);
	setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *) &multicast, sizeof(multicast));
}

void SocketMulticast::salirseGrupo(char * dir){
	multicast.imr_multiaddr.s_addr = inet_addr(dir);
	setsockopt(s, IPPROTO_IP, IP_DROP_MEMBERSHIP, (void *) &multicast, sizeof(multicast));
}
int SocketMulticast::enviaU(PaqueteDatagrama &p){
	SocketDatagrama sUE(7202);
	sUE.envia(p);
	return 0;
}
void SocketMulticast::inisU(int p){
	sU.iniS(p);
}
int SocketMulticast::recibeU(PaqueteDatagrama &p){
	struct mensaje mensajeRecibo;
	int n;
	int maxIt = 2;
	int it = 0;
	int recibidos = 0;
	while(1){
		n = sU.recibeTimeout(p, 2, 500000);
		if(n == -1){
			//if(it != maxIt){ cout << "Esperando nuevos mensajes...\n" << endl; it++;}
			//else {
				cout << "--!! ADVERTENCIA: Servidor no disponible.\n" << endl;
				break;
			//}
		}
		else if (n == -2){
			cout << "--!! ERROR: Error en recvfrom." << endl;
			exit(0);
		}
		else{
			//cout<<"\nRecibi el mensaje..."<<endl;
			memcpy((char*)&mensajeRecibo, p.obtieneDatos(), sizeof(struct mensaje));
                	cout<<"Recibí mensaje de IP :"<<p.obtieneDireccion() << endl;
                	//cout<<"Id de Mensaje : "<< mensajeRecibo.requestId << endl;
                	//cout<<"Recibí resultado: " << mensajeRecibo.argumentos[0] << "\n\n";
			if(mensajeRecibo.requestId == noMensaje){ recibidos++; }
			if(recibidos == noRecep) break;
			//break;
		}
		
	}
	return recibidos;
}
int SocketMulticast::enviaConfiable(PaqueteDatagrama & p, unsigned char ttl, int num_receptores){
	struct mensaje mensajeEnvio;
	memcpy((char*)&mensajeEnvio, p.obtieneDatos(), sizeof(struct mensaje));
	noMensaje = mensajeEnvio.requestId;
	
	inet_pton(AF_INET, p.obtieneDireccion(), &grupoMulticast.sin_addr);
        grupoMulticast.sin_port = htons(p.obtienePuerto());
        sendto(s, p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *) &grupoMulticast, sizeof(grupoMulticast));
       	
	noRecep = num_receptores;
	PaqueteDatagrama paqueteRecibo(sizeof(struct mensaje));
	con = recibeU(paqueteRecibo);
	cout << "Mensajes recibidos hasta ahora: " << con << endl;
	if(con == num_receptores){
		con = 0;
		return 1;
	}
	return -1;
}
int recibeConfiable(PaqueteDatagrama & p){
	
	return -1;
}

//char* SocketMulticast::getClientIP(){return inet_ntoa(multicast.imr_multiaddr.s_addr);}
//unsigned short SocketMulticast::getClientPort(){return multicast.imr_interface.s_addr;}
