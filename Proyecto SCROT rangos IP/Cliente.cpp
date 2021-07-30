#include <iostream>
#include <fstream>
#include "Solicitud.h"

using namespace std;

int main(int argc, char* argv[]){
	if(argc != 4){
		cout << "--!! ERROR: Mala invocación del programa. Intente:" << endl;
		cout << "./cliente direccion_ip_del_servidor_inicial direccion_ip_del_servidor_final calidad_de_captura" << endl;
		return 0;
	}
	if(strlen(argv[1])>16){
		cout << "--!! ERROR: IP inicial inválida. Inténtelo de nuevo." << endl;
		return 0;
	}
	if(strlen(argv[2])>16){
		cout << "--!! ERROR: IP final inválida. Inténtelo de nuevo." << endl;
		return 0;
	}

	Solicitud s;
	int res = 1;
	int tam = 0;
	int numeroDeIPs = 0;
	
	char* archivoRecibo;
	char nombre[9] = "ss00.png";
	char nombreGuardar[16] = "ss00_RECIBO.png";
	char contadorD = 48;
	char contadorI = 48;
	char contadorII = 48;
	struct mensaje mensajeRecibo;
	ofstream archivoGuardar;
	//-------------------------------------------------
	if(argv[3][0] == 'b' && argv[3][1] == 'a' && argv[3][2] == 'j' && argv[3][3] == 'a') res = 1;
	else if(argv[3][0] == 'm' && argv[3][1] == 'e' && argv[3][2] == 'd' && argv[3][3] == 'i' && argv[3][4] == 'a') res = 4;
	else if(argv[3][0] == 'a' && argv[3][1] == 'l' && argv[3][2] == 't' && argv[3][3] == 'a') res = 7;
	else{
		cout << "--!! ADVERTENCIA: Resolución inválida. Auto-asigne: 'media'." << endl;
		res = 4;
	}
	int listSize;
	for(listSize = strlen(argv[1])-1; argv[1][listSize] != '.'; listSize--) tam++;
	char numInicio[3];
	char numFinal[3];
	int p = 0;
	for(int x = listSize+1; x < strlen(argv[1]); x++){
		numInicio[p] = argv[1][x];
		p++;
	}
	p = 0;
	for(int x = listSize+1; x < strlen(argv[2]); x++){
		numFinal[p] = argv[2][x];
		p++;
	}
	numeroDeIPs = atoi(numFinal) - atoi(numInicio) + 1;
	listSize = (strlen(argv[1])-1);
	contadorD = argv[1][strlen(argv[1])-1];
	int loop = strlen(argv[1])-tam;
	if(tam == 1) contadorI = 48;
	else if(tam == 2) contadorI = argv[1][strlen(argv[1])-2];
	else{
		contadorI = argv[1][strlen(argv[1])-2];
		contadorII = argv[1][strlen(argv[1])-3];
	}
	char listaIP[numeroDeIPs][16];
	for(int i = 0; i < numeroDeIPs; i++){
		for(int j = 0; j < loop; j++){
			listaIP[i][j] = argv[1][j];
		}
		listaIP[i][loop+tam] = '\0';
		if(tam == 1){
			listaIP[i][listSize] = contadorD;
		}
		else if(tam == 2){
			listaIP[i][listSize] = contadorD;
			listaIP[i][listSize-1] = contadorI;
		}
		else if (tam == 3){
			listaIP[i][listSize] = contadorD;
			listaIP[i][listSize-1] = contadorI;
			listaIP[i][listSize-2] = contadorII;
		}
		contadorD++;
		
		if(contadorD == 58 && tam == 1){contadorD = 48; contadorI++; tam++; listSize++;}
		else if(contadorD == 58){contadorD = 48; contadorI++;}

		if(contadorI == 58 && tam == 3){contadorI = 48; contadorII++;}
		else if(contadorI == 58 && tam == 2){contadorI = 48; tam++; contadorII++; listSize++;}
		
		listaIP[i][listSize+1] = '\0';
	}
	contadorD = 48;
	contadorI = 48;
	//-------------------------------------------------
	for(int j = 0; j < numeroDeIPs; j++){
		if(j < 10){nombre[3] = contadorD; nombreGuardar[3] = contadorD;}
		else{nombre[2] = contadorI; nombre[3] = contadorD; nombreGuardar[2] = contadorI; nombreGuardar[3] = contadorD;}
		contadorD++;
		if(contadorD == 58){contadorD = 48; contadorI++;}
		if(contadorI == 58){cout << "--!! ADVERTENCIA: Alcanzado el límite de archivos para recibir, el programa va a cerrarse." << endl; return 0;}

		memcpy((char*)&mensajeRecibo, s.doOperation(listaIP[0], 7200, nombre, res), sizeof(struct mensaje));

		cout << ";;========================================" << endl;
		cout << "Mensaje recibido dentro de Cliente.cpp." << endl;
		cout << "IP de quién lo envió: " << s.getIP() << endl;
		cout << "Nombre de la captura de pantalla: " << mensajeRecibo.nombreArchivo << endl;
		cout << "Tamaño de la captura de pantalla: " << mensajeRecibo.tamanio << " bytes." << endl;
		cout << "Calidad de la captura de pantalla: " << mensajeRecibo.calidad << endl;
		cout << ";;========================================" << endl;
		if(mensajeRecibo.tamanio > 64999)
			cout << "--!! ERROR: No se pudo enviar captura número "<< nombre[2] << nombre[3] <<", tamaño superior a la tolerancia (64999)." << endl;
		else {
			archivoRecibo = new char[mensajeRecibo.tamanio];
			memcpy(archivoRecibo, mensajeRecibo.archivo, mensajeRecibo.tamanio);
			archivoRecibo[mensajeRecibo.tamanio] = '\0';
			archivoGuardar.open(nombreGuardar);
			archivoGuardar.write(archivoRecibo, mensajeRecibo.tamanio);
			archivoGuardar.close();
			delete[] archivoRecibo;
		}
	}
	return 0;
}