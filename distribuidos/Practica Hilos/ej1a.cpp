#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <time.h>
#include <stdio.h>
//#define BUFSIZ 7030400
using namespace std;

//char buffer[BUFSIZ];

int main(int argc, char *argv[])
{

	
	

	int destino;
	string linea;

	if(argc != 2)
	{
		cout << "Forma de uso: " << argv[0] << " nombre_del_archivo\n";
		exit(0);
	}
	cout << "Introduce texto para guardar en el archivo y ENTER PARA TERMINAR. Longitud máxima de caracteres= " << BUFSIZ << endl;



	


	//getline(cin, linea);
	//strcpy(buffer, linea.c_str());
	//strcpy(buffer, cad.c_str());
	//Abre un archivo para la escritura, si no existe lo crea, si existe lo trunca, con permisos rw-
	if((destino = open(argv[1], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1)
	{
		perror(argv[1]);
		exit(-1);
	}
	
	//Aquí se genera la cadena
	srand (time(NULL));
	long int n = 0;
	string cad = "";
	//5272800
	long int tam = 26*26*26*100;
	char h;
	//Generación de la cadena
	for(n = 0; n < tam; n++)
	{
		h = (rand()%25)+65;
		cad = h;
		write(destino, cad.c_str(), strlen(cad.c_str()));
		h = (rand()%25)+65;
		cad = h;
		write(destino, cad.c_str(), strlen(cad.c_str()));
		h = (rand()%25)+65;
		cad = h;
		write(destino, cad.c_str(), strlen(cad.c_str()));
		cad = ' ';
		write(destino, cad.c_str(), strlen(cad.c_str()));
		
	}
	//Aqui termina la generación de la cadena
	write(destino, cad.c_str(), strlen(cad.c_str()));
	fsync(destino);
	close(destino);
}
