#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include "SocketMulticast.h"
using namespace std;

int main(){}

SocketMulticast::SocketMulticast(int port,){ 
    u_int yes = 1;
    int s = socket(PF_INET, SOCK_DGRAM, 0);
    bzero((char *)&direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(port);
    setsockopt(s, SOL_SOCKET, SO_REUSEADDR, (char*) &yes, sizeof(yes));
    multicast.imr_multiaddr.s_addr = inet_addr(multicastIP); 
    multicast.imr_interface.s_addr = htonl(INADDR_ANY);
    bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
}

SocketMulticast::SocketMulticast()
{ }

int SocketMulticast::recibe(PaqueteDatagrama &p, unsigned char TTL){
    
    setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *) &multicast, sizeof(multicast));

    char num[p.obtieneLongitud()];
    int i = 0;
    while(i == 0) {
        int tam = sizeof(direccionForanea);
        i = recvfrom(s, (char *) num, p.obtieneLongitud()*sizeof(char), 0, (struct sockaddr *)&direccionForanea,&tam);
        cout << "Te lo envio: " << inet_ntoa(direccionForanea.sin_addr) << ": "<< ntohs(direccionForanea.sin_port) << endl;
        envia(p);
    }
}

int SocketMulticast::envia(PaqueteDatagrama p, char *ipE){
    unsigned char TTL;
    setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *) &TTL, sizeof(TTL))
    int tam = sizeof(direccionForanea);
    return sendto(s, char(*) p.obtieneDatos(), p.obtieneLongitud()*sizeof(char), 0, (struct sockaddr *)&direccionForanea, &tam);
}