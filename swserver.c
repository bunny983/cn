#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include <unistd.h>
#define SIZE 4
int main()
{
int sfd,lfd,len,i,j,status;
char str[20],frame[20],temp[20],ack[20];
struct sockaddr_in saddr,caddr;
sfd=socket(AF_INET,SOCK_STREAM,0);
if(sfd<0)
perror("Error");
bzero(&saddr,sizeof(saddr));
saddr.sin_family=AF_INET;
saddr.sin_addr.s_addr=htonl(INADDR_ANY);
saddr.sin_port=htons(5465);
if(bind(sfd,(struct sockaddr*)&saddr,sizeof(saddr))<0)
perror("Bind Error");
listen(sfd,5);
len=sizeof(&caddr);
lfd=accept(sfd,(struct sockaddr*)&caddr,&len);
printf(" Enter the text : \n");
scanf("%s",str);
