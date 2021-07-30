#define MG_ENABLE_HTTP_STREAMING_MULTIPART 1
#include "mongoose.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include "UDPClient.h"
using namespace std;

#define MAXTAM 4096

static const char *s_http_port = "8000";
static struct mg_serve_http_opts s_http_server_opts;

UDPClient udpC(0);

static void handle_size(struct mg_connection *nc, struct http_message *hm) {
		char query[450];
		/*Recibir todas las capturas*/
		udpC.descargaImagenes();
		
		mg_get_http_var(&hm->body, "query", query,sizeof(query));
		/*Obtiene la cadena, con los datos que debe mandar*/
		sprintf(query, udpC.obtenerDatos());
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
	
	udpC.inicializaObj(argv);
	
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
