#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<stdlib.h>
#define MAX 100

int main()
{
 int welcomeSocket,newSocket,n;
 char buffer[MAX];
 char receive[MAX];
 int pid;
 struct sockaddr_in serverAddr,clientAddr;
 struct sockaddr_storage serverStorage;
 socklen_t addr_size;

 welcomeSocket=socket(AF_INET,SOCK_STREAM,0);
 serverAddr.sin_family=AF_INET;
 serverAddr.sin_port=htons(7891);
 serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
 memset(serverAddr.sin_zero,'\0',sizeof serverAddr.sin_zero);
 bind(welcomeSocket,(struct sockaddr*)&serverAddr,sizeof serverAddr);
 
 if(listen(welcomeSocket,5)==0)
   {
     printf("Server is Listening\n");
   }
 else
   {
     printf("Error\n");
   }

 while(1)
 {
  printf("Server is Waiting for requests\n");
   addr_size=sizeof serverStorage;
  newSocket=accept(welcomeSocket,(struct sockaddr*)&serverStorage,&addr_size);
  pid=fork();
  if(pid==0)
  {
  while(1)
  {
   n=recv(newSocket,buffer,MAX,0);
   if(n==0)
   {
    close(newSocket);
    break;
   }
    buffer[n]=0;
    int x=atoi(buffer);
    //printf("\n%d",x);
    
    printf("\nMessage received from client: %s\n",buffer);
           
    //printf("%s\n",receive);
    //send(newSocket,buffer,n,0);
    //receive[n]=0;
    strcpy(receive,"Success..");
    send(newSocket,receive,strlen(receive),0);
    }
    exit(0);
   }
    else
    {
     close(newSocket);
    }
  }
 
 return 0;
}
