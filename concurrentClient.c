#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#define MAX 100

int main()
{
 int welcomeSocket,newSocket,n;
 char buffer[MAX];
 char receive[MAX];
 char receive1[MAX];
 struct sockaddr_in serverAddr,clientAddr;
 socklen_t addr_size;

 welcomeSocket=socket(AF_INET,SOCK_STREAM,0);
 serverAddr.sin_family=AF_INET;
 serverAddr.sin_port=htons(7891);
 serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
 memset(serverAddr.sin_zero,'\0',sizeof serverAddr.sin_zero);
 
 addr_size=sizeof serverAddr;
 connect(welcomeSocket,(struct sockaddr*)&serverAddr,addr_size);
 while(1)
 { 
  printf("\nEnter the message\n");
  fgets(buffer,MAX,stdin);
 
  //recv(welcomeSocket,receive,100,0);
  //printf("%s\n",receive);
 if(buffer[0]=='#')
 {
  break;
 }
  n=strlen(buffer)+1;
  send(welcomeSocket,buffer,n,0); 

  //n=recv(welcomeSocket,receive,MAX,0);
  //printf("Entered year:%s\n",receive);

  n=recv(welcomeSocket,receive1,MAX,0);
 printf("Result received from server for %s\n",buffer);
  printf("%s\n",receive1);
  
 }

 return 0;
}
