//ECHO CLIENT CODE 

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>

int main()
{
	int clientSocket;
	char ip[32];
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

	int ch = 0;
	printf("\n 1. Dotted Decimal  2. Binary\n Choose type of IP:");
	scanf("%d",&ch);
		
	if(ch == 1){
		printf("\n Enter IP :");
		scanf("%s",ip);
	}else if(ch == 2){
		printf("\n Enter IP :");
		scanf("%s",ip);
	}else{
		printf("\n Wrong Choice!!!");
	}
	
	send(clientSocket,ip,32,0);
	recv(clientSocket, className, 1,0);
	printf("\nClass of IP : %s",className);
	
	return 0;
}

