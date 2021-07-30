#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include "Datagrama.h"
using namespace std;

class SocketMulticast{
public:
	SocketMulticast();
	int recibe(PaqueteDatagrama & p, unsigned char TTL);
	int envia(PaqueteDatagrama & p, char *ipE);
private:
	struct sockaddr_in direccionLocal;
    struct sockaddr_in direccionMulticast;
    struct ip_mreq multicast;

    int s;
};
