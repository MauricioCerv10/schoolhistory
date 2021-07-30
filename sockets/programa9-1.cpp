#include <iostream>
#include <arpa/inet.h>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"

using namespace std;

int main(void){
   SocketDatagrama socketS(0);

   PaqueteDatagrama paqueteRecibo(20);
   PaqueteDatagrama paqueteEnvio(15);

   paqueteEnvio.inicializaDatos((char*)"Hola, cliente.");

   while(1){
      socketS.recibe(paqueteRecibo);

      cout << "Mensaje recibido: " << paqueteRecibo.obtieneDatos() << endl;
      cout << "IP cliente: " << paqueteRecibo.obtieneDireccion() << endl;
      cout << "Puerto cliente: " << paqueteRecibo.obtienePuerto() << endl;
      cout << ";;======================================" << endl;
   
      paqueteEnvio.inicializaIp(paqueteRecibo.obtieneDireccion());
      paqueteEnvio.inicializaPuerto(htons(paqueteRecibo.obtienePuerto()));
      cout << "Mensaje a enviar: " << paqueteEnvio.obtieneDatos() << endl;
      cout << "Mi IP: " << paqueteEnvio.obtieneDireccion() << endl;
      cout << "Mi puerto: " << paqueteEnvio.obtienePuerto() << endl;
      cout << ";;======================================" << endl << endl << endl;

      socketS.envia(paqueteEnvio);
      cout << "Ya lo envie, hehe." << endl;
   }
   return 0;
}