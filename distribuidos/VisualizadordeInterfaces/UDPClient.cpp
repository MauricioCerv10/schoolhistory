#include "UDPClient.h"
using namespace std;
#define MAXTAM 4096
UDPClient::UDPClient(int numPcs):numpcs(numPcs){
}

void UDPClient::inicializaObj(char* argv[]){
	strcpy(opc,argv[3]);
        int firstIp = getLastOct(argv[1]);
        int secondIp = getLastOct(argv[2]);
        numpcs = secondIp - firstIp + 1;

        /*
        numpcs = 2;
        ips[0] = "127.0.0.1";
        ips[0] = "192.168.1.1;"
        */

        asignaIps(argv[1],numpcs,firstIp);

        int t = 0;
        for(int i = 0; argv[4][i] != 0 ;i++){
                t = t*(10) + (argv[4][i] - '0'); 
        }

        intToS(t,numt);

}
void UDPClient::asignaIps(char* cadena, int length, int lastOct){
	for(int i = 0; i<length; i++){
                char ip[30];
                int con = 0;
                for(int i = 0; cadena[i] != 0 ;i++){
                        if(cadena[i] == '.') con++;
                        if(con == 3 && cadena[i] != '.'){
                                ip[i] = 0;
                                char num[4];
                                intToS(lastOct,num); lastOct++;
                                strcat(ip,num);
                                break;
                        }else{
                                ip[i] = cadena[i];
                        }
                } 
                strcat(ips[i],ip);
        }
}
void UDPClient::inicializarCads(){
	for(int i = 0; i<numpcs; i++){ 
                ips[i][0] = 0;
        }
}
char* UDPClient::intToS(int x, char* num){
	string s = to_string(x);
        char const *pchar = s.c_str();  
        strcpy(num,pchar);
        return num;
}
int UDPClient::getLastOct(char* cadena){
	int num = 0;
        int con = 0;
        for(int i = 0; cadena[i] != 0 ;i++){
                if(cadena[i] == '.') con++;
                if(con == 3 && cadena[i] != '.'){ 
                        num = num*(10) + (cadena[i] - '0'); 
                }
        }
        return num;
}
void UDPClient::descargaImagenes(){
	char num[4];
        intToS(numpcs,num);
        strcpy(buffer,numt);

        string s = "$";
        char separa[2];
        char const *pchar = s.c_str();

        strcpy(separa,pchar);
        strcat(buffer,separa);
        strcat(buffer,num);
        strcat(buffer,separa);
	
	for(int i = 0; i< numpcs; i++){ 
        	strcat(buffer,ips[i]);
        	strcat(buffer,separa);
        }

	/*Recibir todas las capturas*/
        for(int i = 0; i<numpcs; i++){
        	SocketDatagrama socketC(0);
        	PaqueteDatagrama paqueteEnvio((char*)opc, 15, ips[i], 7200);   
        	cout << ";;======================================" << endl;
        	cout << "Mensaje a enviar: " << paqueteEnvio.obtieneDatos() << endl;
         	cout << "Mi IP: " << paqueteEnvio.obtieneDireccion() << endl;
        	cout << "Mi puerto: " << paqueteEnvio.obtienePuerto() << endl;
        	cout << ";;======================================" << endl;

       		socketC.envia(paqueteEnvio);
         	string s = to_string(i);
         	char const *pchar = s.c_str();
         	char name[50];
         	int j;
         	for( j = 0; ips[i][j] != 0; j++){
                	if(ips[i][j] == '.') name[j] = '-';
                	else name[j] = ips[i][j];
                }
          	name[j] = 0;

          	strcat(name,".jpg");
          	char sentencia[40];
                strcpy(sentencia,"rm ");
                strcat(sentencia,name);

                system(sentencia);

		FILE * output;
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
}
char* UDPClient::obtenerDatos(){
	return buffer;
}
