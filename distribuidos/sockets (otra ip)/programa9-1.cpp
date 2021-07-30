#include <iostream>
#include <math.h>
#include <arpa/inet.h>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"

using namespace std;

#define MAXTAM 4096

int main(void){
	SocketDatagrama socketS(0);

   	PaqueteDatagrama paqueteRecibo(20);

   	while(1){
      		socketS.recibe(paqueteRecibo);
		
     	 	cout << "Mensaje recibido: " << paqueteRecibo.obtieneDatos() << endl;
      		cout << "IP cliente: " << paqueteRecibo.obtieneDireccion() << endl;
      		cout << "Puerto cliente: " << paqueteRecibo.obtienePuerto() << endl;
      		cout << ";;======================================" << endl;
		if(paqueteRecibo.obtieneDatos()[0] == 'b'){
			system("rm myimage.jpg");
			system("scrot myimage.jpg -u -q 10");		
		}else if(paqueteRecibo.obtieneDatos()[0] == 'm'){
                        system("rm myimage.jpg");
                        system("scrot myimage.jpg -u -q 50");                
                }else {
                        system("rm myimage.jpg");
                        system("scrot myimage.jpg -u -q 100");                
                } 
		
   		
		/*mandar archivo*/
		
  		FILE * pFile;
		long lSize;
		char * buffer;
		size_t result;
	
		pFile = fopen ( "myimage.jpg" , "rb" );
		if (pFile==NULL) {fputs ("File error",stderr); exit (1);}
	
		fseek (pFile , 0 , SEEK_END);
		lSize = ftell (pFile);
		rewind (pFile);

		buffer = (char*) malloc (sizeof(char)*lSize);
		if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}
	
		result = fread (buffer,1,lSize,pFile);
		if (result != lSize) {fputs ("Reading error",stderr); exit (3);}
	
		char parte[MAXTAM];
		int bytes = lSize;
		int index = 0;
		int con = 0;
		
		/*Enviar numero de paquetes que debe recibir*/
		
		int numpackets = ceil((float)lSize/(float)MAXTAM);
		char data[1];
		data[0] = numpackets;
		PaqueteDatagrama enviaNum(1);
		enviaNum.inicializaDatos(data);
		enviaNum.inicializaIp(paqueteRecibo.obtieneDireccion());
		enviaNum.inicializaPuerto(htons(paqueteRecibo.obtienePuerto()));
		socketS.envia(enviaNum);

		while(bytes > 0){
			con++;
			int tam = 0;
			for(int i = 0; i<MAXTAM; i++,tam++){
				if(index == lSize){ break;}
				parte[i] = buffer[index++];
			}
			bytes -= tam;
			//fwrite (parte , sizeof(char), tam, output);
			PaqueteDatagrama paqueteEnvio(tam);
			paqueteEnvio.inicializaDatos(parte);
			paqueteEnvio.inicializaIp(paqueteRecibo.obtieneDireccion());
      			paqueteEnvio.inicializaPuerto(htons(paqueteRecibo.obtienePuerto()));
		
      			socketS.envia(paqueteEnvio);
      			//cout << "Ya lo envie, hehe." << endl;
			PaqueteDatagrama confirm(20);
			socketS.recibe(confirm);
      			
			
		}
		// terminate
		fclose (pFile);
		free (buffer);
   	}
   	return 0;
}
