//ECHO---Server Code

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>

int convertToInt(int n){
	int res = 0, base = 1;
	
	while(n != 0){
		int rem = n % 10;
		res = res + rem * base;
		base *= 2;
		n /= 10;
	}
	return res;
}

int getNo(char ip[]){
	
	int n = 0, count = 0;
	
	for(int i=0;i<32;i++){
		if(ip[i] != '.'){
			n *= 10;
			n += ip[i] - '0';
			count++;
		}else
			break;
	}
	
	if(count > 3)
		return convertToInt(n);
	else
		return n;
}

char getClassOfIp(char ip[]){
	
	int n = getNo(ip);
	
	if(n >= 0 && n <= 127)
		return 'A';
	else if(n >= 128 && n <= 191)
		return 'B';
	else if(n >= 192 && n <= 223)
		return 'C';
	else if(n >= 224 && n <= 239)
		return 'D';
	else
		return 'E';
}

int main()
{
	int welcomeSocket,newSocket;
	char buffer[32];
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;

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
	newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);

	recv(newSocket, buffer, 32,0);
	char c[32];
	c[0] = getClassOfIp(buffer);
	printf("%s",c);
	send(newSocket,c,32,0);

	return 0;
}
