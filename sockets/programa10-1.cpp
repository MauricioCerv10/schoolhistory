#include <iostream>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"

using namespace std;

int main(int arg,char* args[]){
	if(arg != 2) return 0;
   SocketDatagrama socketC(0);
   
   PaqueteDatagrama paqueteEnvio((char*)"Hola, servidor.", 15, args[1], 7200);
   PaqueteDatagrama paqueteRecibo(20);
   
   cout << ";;======================================" << endl;
   cout << "Mensaje a enviar: " << paqueteEnvio.obtieneDatos() << endl;
   cout << "Mi IP: " << paqueteEnvio.obtieneDireccion() << endl;
   cout << "Mi puerto: " << paqueteEnvio.obtienePuerto() << endl;
   cout << ";;======================================" << endl;

   socketC.envia(paqueteEnvio);
   socketC.recibe(paqueteRecibo);

   cout << "Mensaje recibido: " << paqueteRecibo.obtieneDatos() << endl;
   cout << "IP servidor: " << paqueteRecibo.obtieneDireccion() << endl;
   cout << "Puerto servidor: " << paqueteRecibo.obtienePuerto() << endl;
   cout << ";;======================================" << endl;

   return 0;
}
