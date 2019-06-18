#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444

int main()
{

	// --------- STRUCT SERVER--------
	struct sockaddr_in serverAddr;
	struct sockaddr_in newAddr;
	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	// --------- SERVER SOCKET--------
	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(serverSocket < 0)
	{
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Server Socket is created.\n");

	if(bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) != 0)
	{
		printf("[-]Error in binding.\n");
		exit(1);
	}
	printf("[+]Bind to port %d\n", 4444);

	if(listen(serverSocket, 10) == 0)
	{
		printf("[+]Listening....\n");
	}
	else
	{
		printf("[-]Error in binding.\n");
	}
	// --------- END--SERVER SOCKET--------

	int newSocket;
	socklen_t addr_size;
	pid_t sond;
	char* bufferRecev = malloc(1000);
	char* bufferSend = malloc(1000);

	while(1)
	{
		newSocket = accept(serverSocket, (struct sockaddr*)&newAddr, &addr_size);
		if(newSocket < 0)
		{
			exit(1);
		}
		printf("Connection accepted from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
		//printf("FORK id: %d\n",getgid()); //getid me indica el id del Fork

		if((sond = fork()) == 0)
		{
			close(serverSocket);
			
			while(1)
			{
				recv(newSocket, bufferRecev, 1024, 0);
				if(strcmp(bufferRecev, ":exit") == 0)
				{
					printf("Disconnected from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
					break;
				}
				else
				{
					printf("Client: \t%s\n", bufferRecev);
					printf("Server: \t");
					fgets(bufferSend, 20, stdin);
					send(newSocket, bufferSend, strlen(bufferSend), 0);
					bzero(bufferRecev, sizeof(bufferRecev));
				}
			}
		}

	}

	close(newSocket);


	return 0;
}