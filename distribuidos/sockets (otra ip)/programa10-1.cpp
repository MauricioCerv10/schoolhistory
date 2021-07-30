#include <iostream>
#include <string.h>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"

using namespace std;

#define MAXTAM 4096


int main(int argc, char* argv[]){
   	if(argc != 4){
		cout<<"ip_cliente numero_de_pcs calidad";
      		return 0;
	}
   	char* args[] = {"127.0.0.1","127.0.0.1","127.0.0.1"};
	/*TODO
	
	Rescibir el rango de direcciones
	convertir cada direccion en un char const *
	crear arreglo args 
	*/
   	int numIps = 3;
	for(int i = 0; i<numIps; i++){
   		SocketDatagrama socketC(0);
		PaqueteDatagrama paqueteEnvio((char*)argv[3], 15, args[i], 7200);   
   		cout << ";;======================================" << endl;
   		cout << "Mensaje a enviar: " << paqueteEnvio.obtieneDatos() << endl;
   		cout << "Mi IP: " << paqueteEnvio.obtieneDireccion() << endl;
   		cout << "Mi puerto: " << paqueteEnvio.obtienePuerto() << endl;
   		cout << ";;======================================" << endl;
	
   		socketC.envia(paqueteEnvio);
		string s = to_string(i);
		char const *pchar = s.c_str(); 
		char src[50], name[50], num[50];
   		strcpy(name,"copia");
   		strcpy(src, ".jpg");
		strcpy(num,pchar);

   		strcat(name,num);
		strcat(name,src);


		FILE * output	;
        	output = fopen (name, "wb");
		int con = 0;
		int npackets = 0;
	
		/*recibir el numero de paquetes que voya recibir*/
		PaqueteDatagrama numPackets(1);
		socketC.recibe(numPackets);
		npackets = (int) numPackets.obtieneDatos()[0];
		while(npackets--){
			PaqueteDatagrama paqueteRecibo(MAXTAM);
   			socketC.recibe(paqueteRecibo);
			fwrite (paqueteRecibo.obtieneDatos() , sizeof(char), paqueteRecibo.obtieneLongitud(), output);
		
   			cout << "IP servidor: " << paqueteRecibo.obtieneDireccion() << endl;
   			cout << ";;======================================" << endl;
			socketC.envia(paqueteEnvio);
		}
		fclose (output);
	}

   	return 0;
}
