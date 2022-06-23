#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>

int main()
{
	int clientSocket;
	char msg[100];
	char recv_msg[100];
	struct sockaddr_in serverAddr;
	socklen_t addr_size;
	char className[32];

	clientSocket = socket(PF_INET, SOCK_STREAM, 0);

	serverAddr.sin_family = AF_INET;

	serverAddr.sin_port = htons(7891);

	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

	addr_size= sizeof serverAddr;
	connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

    while(1){
        printf("Enter the message: ");
        fgets(msg, 99, stdin);
        if(msg[0] == '#'){
            break;
        }
        send(clientSocket, msg, 99, 0);
        recv(clientSocket, recv_msg, 99,0);
		printf("message from server: %s", recv_msg);
    }
}