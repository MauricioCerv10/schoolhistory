#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include "SocketDatagrama.h"
using namespace std;

int main(){}

SocketDatagrama::SocketDatagrama(int port){ 
    s = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *)&direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(port);
    bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
}

SocketDatagrama::SocketDatagrama()
{ }

int SocketDatagrama::recibe(PaqueteDatagrama p){
    char num[p.obtieneLongitud()];
    int i = 0;
    while(i == 0) {
        int tam = sizeof(direccionForanea);
        i = recvfrom(s, (char *) num, p.obtieneLongitud()*sizeof(char), 0, (struct sockaddr *)&direccionForanea,&tam);
        cout << "Te lo envio: " << inet_ntoa(direccionForanea.sin_addr) << ": "<< ntohs(direccionForanea.sin_port) << endl;
        envia(p);
    }
}

int SocketDatagrama::envia(PaqueteDatagrama p){
    int tam = sizeof(direccionForanea);
    return sendto(s, char(*) p.obtieneDatos(), p.obtieneLongitud()*sizeof(char), 0, (struct sockaddr *)&direccionForanea, &tam);
}