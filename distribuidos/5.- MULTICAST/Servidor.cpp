#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <fcntl.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include "PaqueteDatagrama.h"
#include "SocketMulticast.h"
#include "Mensaje.h"
#include "Registros.h"

using namespace std;

const int NUMERIC_SIZE = 10;

string getNum(char* nums){
	string num = "";
	for(int i = 0; i<10; i++){
		num += nums[i];
	}
	return num;
}

struct TrieNode{
	struct TrieNode *children[NUMERIC_SIZE];
	// isEndOfWord is true if the node represents
	// end of a word
	bool isEndOfWord;
};

struct TrieNode *getNode(void){ 
	struct TrieNode *pNode =  new TrieNode;
	pNode->isEndOfWord = false;
	for(int i = 0; i < NUMERIC_SIZE; i++)
		pNode->children[i] = NULL;
	return pNode;
}

void insert(struct TrieNode *root, string key) {
	struct TrieNode *pCrawl = root;
    for(int i = 0; i < key.length(); i++){
		int index = key[i] - '0';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();
		pCrawl = pCrawl->children[index];
	} 
	// mark last node as leaf
	pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode *root, string key){
	struct TrieNode *pCrawl = root;
	for (int i = 0; i < key.length(); i++){
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			return false;
		pCrawl = pCrawl->children[index];
	}
	return (pCrawl != NULL && pCrawl->isEndOfWord);
}

int main(int argc, char argv[]){
	if(argc != 2){
		cout << "" << endl;
		exit(0);
	}

	SocketMulticast socketLocal(7200);
        socketLocal.unirseGrupo("224.0.0.1");
	struct mensaje mensajeRecibo;
	struct mensaje mensajeEnvio;
	int noMensaje = 0;
	int nb = 0;
	while(1){
		cout << "Esperando mensaje con ID :"<< noMensaje << "\n\n";
		
		PaqueteDatagrama paqueteRecibo(sizeof(struct mensaje));
        	socketLocal.recibe(paqueteRecibo);
        	cout <<  "Mensaje Recibido\n";
		cout << "Direccion: " << paqueteRecibo.obtieneDireccion() << endl;
		
		memcpy((char*)&mensajeRecibo, paqueteRecibo.obtieneDatos(), sizeof(struct mensaje));
		if(argv[1] == '1'){
                        if(reg.celular[9] == '4' || reg.celular[9] == '5' || reg.celular[9] == '6' || 
                                reg.celular[9] == '7' || reg.celular[9] == '8' || reg.celular[9] == '9'){
                                if(mensajeRecibo.requestId < noMensaje ){
                                        cout << "Mensaje Ignorado. Repetido. Decartando...  \nEsperando Nuevo Mensaje" << endl;
                                        continue;
                                }
                                noMensaje++;
				continue;

                        }
                }
                else if(argv[1] == '2'){
                        if(reg.celular[9] == '0' || reg.celular[9] == '1' || reg.celular[9] == '2' || 
                                reg.celular[9] == '3' || reg.celular[9] == '7' || reg.celular[9] == '8' || reg.celular[9] == '9'){
                                if(mensajeRecibo.requestId < noMensaje ){
                                        cout << "Mensaje Ignorado. Repetido. Decartando...  \nEsperando Nuevo Mensaje" << endl;
                                        continue;
                                }
                                noMensaje++;
				continue;

                        }
                }

		else {
			if(reg.celular[9] == '0' || reg.celular[9] == '1' || reg.celular[9] == '2' || 
                                reg.celular[9] == '3' || reg.celular[9] == '4' || reg.celular[9] == '5' || reg.celular[9] == '6'){
                                if(mensajeRecibo.requestId < noMensaje ){
                                        cout << "Mensaje Ignorado. Repetido. Decartando...  \nEsperando Nuevo Mensaje" << endl;
                                        continue;
                                }
                                noMensaje++;
				continue;

                        }
		}

		cout << "ID recibido : " << mensajeRecibo.requestId << endl;
		
		if(mensajeRecibo.requestId < noMensaje ){
			cout << "Mensaje Repetido. Decartando...  \nEsperando Nuevo Mensaje" << endl;
			
			//mensajeEnvio.argumentos[0] = 0; 
                	PaqueteDatagrama pEnvia((char*)&mensajeEnvio, sizeof(struct mensaje) ,paqueteRecibo.obtieneDireccion(),
                                                7201);
                	socketLocal.enviaU(pEnvia);

			continue;
		}
		/*TODO 
			Hacer validacion trie
			Escribir el registro
			hacer validacion de timestamp
			
		*/
		//cout << "Mensaje nuevo recibido: "<< mensajeRecibo.requestId <<endl;
		//nb += mensajeRecibo.argumentos[0];
		//cout << "Saldo: " << nb << endl;
		
		memcpy((char*)&mensajeEnvio, (char*)&mensajeRecibo, sizeof(struct mensaje));
		//mensajeEnvio.argumentos[0] = 0;
		mensajeEnvio.requestId = noMensaje; noMensaje++;
		PaqueteDatagrama pEnvia((char*)&mensajeEnvio, sizeof(struct mensaje) ,paqueteRecibo.obtieneDireccion(),
						7201);
		//sleep(1);
		socketLocal.enviaU(pEnvia);
	}
	
	return 0;
}
