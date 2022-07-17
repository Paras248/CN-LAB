/*This is program for batch s4 A division */
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
int main()
{

int sd1,sd2;
char buffer[500];

struct sockaddr_in6 serverAddr,clientAddr;

socklen_t addr_size;

sd1=socket(AF_INET6,SOCK_STREAM,0);


serverAddr.sin6_family=AF_INET6;
serverAddr.sin6_port=htons(7689);
inet_pton(AF_INET6, "::1", &serverAddr.sin6_addr);

bind(sd1, (struct sockaddr *) &serverAddr,sizeof(serverAddr));

if (listen(sd1,6)==0)
printf(" Server is Listening ");
else 
printf("Error");

addr_size=sizeof(clientAddr);

sd2=accept(sd1,(struct sockaddr *) &clientAddr,&addr_size);

strcpy(buffer,"welcome you all\n");

send(sd2,buffer,20,0);


return 0;
}
