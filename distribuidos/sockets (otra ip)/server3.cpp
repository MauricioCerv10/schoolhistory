#define MG_ENABLE_HTTP_STREAMING_MULTIPART 1
#include "mongoose.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"

using namespace std;

#define MAXTAM 4096

static const char *s_http_port = "8000";
static struct mg_serve_http_opts s_http_server_opts;
int numpcs = 3;
char ips[40][30];
char opc[10];
char numt[4];
int getLastOct(char* cadena){
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
char* intToS(int x, char* num){
        string s = to_string(x);
        char const *pchar = s.c_str();  
        strcpy(num,pchar);
	return num;
}
void asignaIps(char* cadena, int length, int lastOct){
	for(int i = 0; i<length; i++){
		char buffer[30];
		int con = 0;
		for(int i = 0; cadena[i] != 0 ;i++){
                	if(cadena[i] == '.') con++;
                	if(con == 3 && cadena[i] != '.'){
				buffer[i] = 0;
				char num[4];
				intToS(lastOct,num); lastOct++;
				strcat(buffer,num);
				break;
                	}else{
				buffer[i] = cadena[i];
			}
        	} 
		strcat(ips[i],buffer);
	}
}
void inicializarCads(){
	for(int i = 0; i<numpcs; i++){ 
		ips[i][0] = 0;
	}
}

static void handle_size(struct mg_connection *nc, struct http_message *hm) {
		char query[450];
		char buffer[450];
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

		mg_get_http_var(&hm->body, "query", query,sizeof(query));
		sprintf(query, buffer);
		printf("Cadena enviada: %s\n", query);

		mg_send_head(nc,200,strlen(query), "Content-Type: text/plain");
		mg_printf(nc, "%s", query);
}

static void ev_handler(struct mg_connection *nc, int ev, void *p) {
	char query[256];
 	struct http_message *hm = (struct http_message *) p;

	
	if (ev == MG_EV_HTTP_REQUEST) {
		if (mg_vcmp(&hm->uri, "/search") == 0) { 
			
			mg_get_http_var(&hm->body, "query", query,sizeof(query));
			printf("Cadena introducida: %s\n",query);

		    handle_size(nc, hm);  
		}else{
			mg_serve_http(nc, (struct http_message *) p, s_http_server_opts);
		}
	}

}
int main(int argc, char* argv[]){
        if(argc != 5){
                cout<<"primera_PC ultima_PC calidad tiempo_t";
                return 0;
        }
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

	
	struct mg_mgr mgr;
	struct mg_connection *nc;
	mg_mgr_init(&mgr, NULL);

	printf("Starting web server on port %s\n", s_http_port);
	nc = mg_bind(&mgr, s_http_port, ev_handler);
	if (nc == NULL) {
		printf("Failed to create listener\n");
		return 1;
	}
	// Set up HTTP server parameters
	mg_set_protocol_http_websocket(nc);
	s_http_server_opts.document_root = "."; // Serve current directory
	s_http_server_opts.enable_directory_listing = "yes";
	for (;;) {
		mg_mgr_poll(&mgr, 1000);
	}
	mg_mgr_free(&mgr);
	return 0;
}
