#include <iostream>
#include <fstream>
#include <string>
#include "Respuesta.h"

using namespace std;

int main(void){
	Respuesta r(7200);
	struct mensaje mensajeEnvio;
	struct mensaje mensajeRecibo;

	ifstream file;
	string str, str1, str2;
	char *comando;

	while(1){
		cout << "Esperando mensaje..." << endl;
		memcpy(&mensajeRecibo, r.getRequest(), sizeof(struct mensaje));
		cout << ";;==================================" << endl;
		cout << "Mensaje recibido dentro de Servidor.cpp." << endl;
		cout << "IP del cliente: " << r.getIP() << endl;
		str1 = mensajeRecibo.nombreArchivo;
		mensajeEnvio.calidad = mensajeRecibo.calidad;
		switch(mensajeRecibo.calidad){
			case 1: str2 = "1"; break;
			case 4: str2 = "4"; break;
			case 7: str2 = "7"; break;

			default:
				cout << "--!! ADVERTENCIA: Resolución no válida. Auto-asigne: 'media'." << endl;
				str2 = "4";
				mensajeEnvio.calidad=4;
			break;
		}
		str = "scrot " + str1 + " -u -q " + str2;
		comando = new char[str.length()+1];
		strcpy(comando, str.c_str());
		cout << "Comando a realizar: '" << comando << "'" << endl;
		system(comando);

		file.open(mensajeRecibo.nombreArchivo);
		file.seekg(0, ios::end);
		mensajeEnvio.tamanio = file.tellg();
		memcpy(mensajeEnvio.nombreArchivo, mensajeRecibo.nombreArchivo, 9);
		cout << "Tamaño de la captura de pantalla: " << mensajeEnvio.tamanio << " bytes." << endl;
		cout << "Nombre de la captura de pantalla: " << mensajeEnvio.nombreArchivo << endl;
		cout << "Calidad de la captura de pantalla: " << mensajeEnvio.calidad << endl;
		if(mensajeEnvio.tamanio > 64999)
			cout << "--!! ERROR: No se puede enviar captura, tamaño superior a la tolerancia (64999)." << endl;
		else{
			file.seekg(0, ios::beg);
			file.read(mensajeEnvio.archivo, mensajeEnvio.tamanio);
			mensajeEnvio.archivo[mensajeEnvio.tamanio] = '\0';
		}
		cout << ";;==================================" << endl;

		r.sendReply((char *)&mensajeEnvio);
		file.close();
		delete[] comando;
	}
	return 0;
}