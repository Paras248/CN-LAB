/*This is program for batch s4 A division */
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
int main()
{

int csd1;
char buffer[500];

struct sockaddr_in6 serverAddr,clientAddr;

socklen_t addr_size;

csd1=socket(AF_INET6,SOCK_STREAM,0);


serverAddr.sin6_family=AF_INET6;
serverAddr.sin6_port=htons(7689);
inet_pton(AF_INET6, "::1", &serverAddr.sin6_addr);

addr_size=sizeof(clientAddr);

connect(csd1,(struct sockaddr *) &serverAddr,addr_size);

recv(csd1,buffer,20,0);

printf("Received from server:%s",buffer);

return 0;
}
