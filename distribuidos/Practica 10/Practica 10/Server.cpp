#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include "SocketDatagrama.h"
#include "Datagrama.h"

using namespace std;
int puerto = 7200;
unsigned int longitud = 300;

int main(){
    SocketDatagrama sd(puerto);
    PaqueteDatagrama pd(longitud);
    sd.recibe(&pd);
}