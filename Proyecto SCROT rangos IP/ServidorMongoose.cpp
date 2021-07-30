#define MG_ENABLE_HTTP_STREAMING_MULTIPART 1
#include "mongoose.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

static const char *s_http_port = "8000";
static struct mg_serve_http_opts s_http_server_opts;

char ipIni[256];
char ipFin[256];
char calidad[256];

static void handle_size(struct mg_connection *nc, struct http_message *hm) {
		char* comando;
		string str1(ipIni);
		string str2(ipFin);
		string str3(calidad);
		stringstream strs;
		string a;
		int numeroDeIPs;
		int listSize = 0;
		int tam = 0;
		for(listSize = strlen(ipIni)-1; ipIni[listSize] != '.'; listSize--) tam++;
		char numInicio[3];
		char numFinal[3];
		int p = 0;
		for(int x = listSize+1; x < strlen(ipIni); x++){
			numInicio[p] = ipIni[x];
			p++;
		}
		p = 0;
		for(int x = listSize+1; x < strlen(ipFin); x++){
			numFinal[p] = ipFin[x];
			p++;
		}
		numeroDeIPs = atoi(numFinal) - atoi(numInicio) + 1;

		string str = "./PEDIR_SS " + str1 + " " + str2 + " " + str3;
		comando = new char[str.length()+1];
		strcpy(comando, str.c_str());
		cout << "Comando a realizar: '" << comando << "'" << endl;
		system(comando);
		delete[] comando;

		for(int i = 0; i < numeroDeIPs; i++){
			strs << i;
			a = strs.str();
			strs.str(std::string());
			if(i < 10) str = "rm www/ss0"+a+"_RECIBO.png";
			else str = "rm www/ss"+a+"_RECIBO.png";
			comando = new char[str.length()+1];
			strcpy(comando, str.c_str());
			cout << "Comando a realizar: '" << comando << "'" << endl;
			system(comando);
			delete[] comando;
		}

		for(int i = 0; i < numeroDeIPs; i++){
			strs << i;
			a = strs.str();
			strs.str(std::string());
			if(i < 10) str = "mv ss0"+a+"_RECIBO.png www/ss0"+a+"_RECIBO.png";
			else str = "mv ss"+a+"_RECIBO.png www/ss"+a+"_RECIBO.png";
			comando = new char[str.length()+1];
			strcpy(comando, str.c_str());
			cout << "Comando a realizar: '" << comando << "'" << endl;
			system(comando);
			delete[] comando;
		}
		strs << numeroDeIPs;
		str = strs.str();
		strs.str(std::string());
		comando = new char[str.length()+1];

		strcpy(comando, str.c_str());
		//comando[str.length()] = '\0';
		cout << comando << endl;
		mg_send_head(nc,200,strlen(comando), "Content-Type: text/plain");
		mg_printf(nc, "%s", comando);
		delete[] comando;
}

static void ev_handler(struct mg_connection *nc, int ev, void *p) {
 	struct http_message *hm = (struct http_message *) p;


	if (ev == MG_EV_HTTP_REQUEST) {
		if (mg_vcmp(&hm->uri, "/search") == 0) { 
			
			mg_get_http_var(&hm->body, "ipIni", ipIni,sizeof(ipIni));
			printf("IP inicial: %s\n",ipIni);

			mg_get_http_var(&hm->body, "ipFin", ipFin,sizeof(ipFin));
			printf("IP final: %s\n",ipFin);

			mg_get_http_var(&hm->body, "calidad", calidad,sizeof(calidad));
			printf("Calidad: %s\n",calidad);

			handle_size(nc, hm);
		}else{
			mg_serve_http(nc, (struct http_message *) p, s_http_server_opts);
		}
	}

}

int main(void) {
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
	s_http_server_opts.document_root = "www"; // Serve current directory
	s_http_server_opts.enable_directory_listing = "yes";
	for (;;) {
		mg_mgr_poll(&mgr, 1000);
	}
	mg_mgr_free(&mgr);
	return 0;
}
