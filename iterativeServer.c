#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

void main(){
   
	int welcomeSocket,newSocket;
	char buffer[100];
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;
    int n;

	welcomeSocket = socket(PF_INET,SOCK_STREAM,0);
	
	serverAddr.sin_family = AF_INET;

	serverAddr.sin_port = htons(7891);

	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	memset(serverAddr.sin_zero, '\0',sizeof serverAddr.sin_zero);

	bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

	if(listen(welcomeSocket,5)==0)
		printf("Listening\n");
	else
		printf("Error\n");

	addr_size = sizeof serverStorage;
	
    while(1){
        printf("Server is waiting for connect from client");
        newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);
        while(1){
            n = recv(newSocket, buffer, 100, 0);
            if(n == 0){
                close(newSocket);
                break;
            }
            send(newSocket, buffer, n, 0);
            printf("message sent to client %s", buffer);
        }
    }
}