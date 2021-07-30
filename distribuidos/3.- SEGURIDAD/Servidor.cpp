#include <iostream>
#include <fstream>
#include <string>
#include <fcntl.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include "Respuesta.h"
#include "Registros.h"

using namespace std;
typedef long long ll;
vector<ll> numeros;

ll getNum(char* nums){
	ll num = 0;
	for(int i = 0; i<10; i++){
		ll n = nums[i] - '0';
		num = 10*num + n;
		
	}
	return num;
}

int main(void){
	Respuesta r(7200);

	struct timeval timestamp;
	struct mensaje mensajeEnvio;
	struct mensaje mensajeRecibo;
	
	vector<Registros> baseDeDatos;
	vector<Registros>::iterator j, k;

	char *archivoRecibo;
	int destino;

	if(( destino = open("copia.txt",O_WRONLY|O_TRUNC|O_CREAT,0666) )  == -1){
		cout << "Error al escribir en el archivo\n";
		exit(-1);
	}

	while(1){
		cout << "Esperando mensaje..." << endl;
		memcpy(&mensajeRecibo, r.getRequest(), sizeof(struct mensaje));
		if(mensajeRecibo.messageType != -1){ /// Duda en esta linea
			gettimeofday(&timestamp, NULL);
			struct registro reg;
			cout << "==================================" << endl;
			memcpy(&reg, mensajeRecibo.archivo,sizeof(reg));
			//cout<<reg.celular<<endl;
			cout<<getNum(reg.celular)<<endl;
			ll telefono = getNum(reg.celular);
			if( binary_search( numeros.begin(),numeros.end(),telefono )  ){
				/*Mandar mensaje con numeros inicializados en 0*/
				timestamp.tv_sec = 0;
				timestamp.tv_usec = 0;
				cout<<"--------------------------------------------------Numero telefonico existente--------------------------------------------------\n";
			}else{
				numeros.push_back(telefono);
				sort(numeros.begin(), numeros.end());
				write(1,&reg,sizeof(reg));
				cout<<endl;
				write(destino,&reg,sizeof(reg));
				baseDeDatos.push_back(Registros((char*)&reg, (char*)&timestamp));
			}
			cout<<"TIMESTAMP enviado : "<<endl;
			cout<< timestamp.tv_sec  <<endl;
			cout<< timestamp.tv_usec <<endl;
			memcpy(&mensajeEnvio.TIMESTAMP, (char*)&timestamp, sizeof(struct timeval));
			mensajeEnvio.estatus = 0;
		}
		r.sendReply((char *)&mensajeEnvio);
	}
	return 0;
}
