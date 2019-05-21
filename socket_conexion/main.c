#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(void) {
	struct sockaddr_in direccionServidor;
	direccionServidor.sin_family = AF_INET;
	direccionServidor.sin_addr.s_addr = INADDR_ANY;
	direccionServidor.sin_port = htons(8080);

	int servidor = socket(AF_INET, SOCK_STREAM, 0);

	int activado = 1;
	setsockopt(servidor, SOL_SOCKET, SO_REUSEADDR, &activado, sizeof(activado));

	if (bind(servidor, (void*) &direccionServidor, sizeof(direccionServidor)) != 0) {
		perror("Fallo el bind");
		return 1;
	}

	printf("A la espera de un cliente\n");
	listen(servidor, 100);

	//------------------------------

	struct sockaddr_in direccionCliente;
	unsigned int tamanodireccion;
	int cliente = accept(servidor, (void*) &direccionCliente, &tamanodireccion);

	printf("Conexion OK!! %i\n", cliente);
	//send(cliente, "Hola NetCat!", 13, 0);
	//send(cliente, ":)\n", 4, 0);

	//------------------------------

	char* bufferRecev = malloc(1000);
	char* bufferSend = malloc(1000);
	while (1) {
		int bytesRecibidos = recv(cliente, bufferRecev, 1000, 0);
		if (bytesRecibidos <= 0) {
			perror("El cliente se desconecto.");
			return 1;
		}

		bufferRecev[bytesRecibidos] = '\0';
		printf("CLIENTE:  %s\n", bufferRecev);

	printf("\nSERVIDOR: ");
	fgets(bufferSend, 20, stdin);
	printf("\n");
    send(cliente, bufferSend, strlen(bufferSend), 0);
	}

	free(bufferRecev);
	free(bufferSend);
	return 0;
}
