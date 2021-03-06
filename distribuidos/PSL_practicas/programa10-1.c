#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>

int puerto = 7200;

int main(void)
{
   struct sockaddr_in msg_to_server_addr, client_addr;
   int s, num[2], res;
   
   s = socket(AF_INET, SOCK_DGRAM, 0);
   /* rellena la dirección del servidor */
   bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
   msg_to_server_addr.sin_family = AF_INET;
   msg_to_server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
   msg_to_server_addr.sin_port = htons(puerto);
   
   /* rellena la direcciòn del cliente*/
   bzero((char *)&client_addr, sizeof(client_addr));
   client_addr.sin_family = AF_INET;
   client_addr.sin_addr.s_addr = INADDR_ANY;
   
   /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
   client_addr.sin_port = htons(0);
   bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));
   num[0] = 2;
   num[1] = 5; /*rellena el mensaje */
   sendto(s, (char *)num, 2 * sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
   
   /* se bloquea esperando respuesta */
   recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
   char arreglo[4];
   memcpy(arreglo,&msg_to_server_addr.sin_addr.s_addr,4);
   printf("%x ",arreglo[0]);
   printf("%x ",arreglo[1]);
   printf("%x ",arreglo[2]);
   printf("%x\n",arreglo[3]);
   /*u_long div = 1000000000000;
   u_long addrl = msg_to_server_addr.sin_addr.s_addr;
   while(div > addrl) div /= 10;
   while(div > 0){
	u_long dig = addrl/div;
	printf("%lu\n",dig);
	addrl -= div*dig;
	div /= 10;
   }
   printf("%lu\n",msg_to_server_addr.sin_addr.s_addr);*/
   close(s);
}

