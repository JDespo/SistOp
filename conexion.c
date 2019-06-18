#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "funciones.h"

int conex(STR_avion *AVION, char *datos)
{
    struct sockaddr_in direccionServidor;
    direccionServidor.sin_family = AF_INET;
    direccionServidor.sin_addr.s_addr = inet_addr("127.0.0.1");
    direccionServidor.sin_port = htons(8080);


  int cliente = socket(AF_INET, SOCK_STREAM, 0);
  if(connect(cliente, (void*) &direccionServidor, sizeof(direccionServidor)) !=0){
    perror("no se puede conectar");
    //return 1;
  }else{printf("Se conector con el servidor \n");}

  
    	
	//char* bufferRecev = malloc(1000);
	//char* bufferSend = malloc(1000);
	//send(cliente, AVION->id, id_Len, 0);

   /*  while(1){
	int bytesRecibidos = recv(cliente, bufferRecev, 1000, 0);
	if (bytesRecibidos <= 0) {
		perror("El servidor se desconecto.");
		//return 1;
	}

	bufferRecev[bytesRecibidos] = '\0';
	printf("SERVIDOR: %s\n", bufferRecev);


	printf("\nCLIENTE: ");
	fgets(bufferSend, 20, stdin);
	printf("\n");
    send(cliente, bufferSend, strlen(bufferSend), 0);
  } */

	/* free(bufferRecev);
	free(bufferSend); */
    return cliente;
}
void sendMSJ(int cliente, char *sendMsj)
{   
    int LEN=0;
    //LEN=strlen(sendMSJ);
    //char* bufferSend = malloc(1000);
	send(cliente, sendMsj, 50, 0);
}

void recevMSJ(int cliente)
{   
    char* bufferRecev = malloc(1000);
    /* while(1)
    { */
	    int bytesRecibidos = recv(cliente, bufferRecev, 1000, 0);
	    if (bytesRecibidos <= 0) 
        {
		    perror("El servidor se desconecto.");
		    //return 1;
	    }

	bufferRecev[bytesRecibidos] = '\0';
	printf("SERVIDOR: %s\n", bufferRecev);
    /* } */
}