
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include <string>

using namespace std;

class PaqueteDatagrama { 
	public:
		PaqueteDatagrama();
		PaqueteDatagrama(string, unsigned int, string , int ); 
		PaqueteDatagrama(unsigned int );
		string obtieneDireccion();
		unsigned int obtieneLongitud(); 
		int obtienePuerto();
		string obtieneDatos();

		void inicializaPuerto(int); 
		void inicializaIp(string );
		void inicializaDatos(string );
	private:
		string datos;
		string ip;
		unsigned int longitud; 
		int puerto;
};