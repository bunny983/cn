#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<errno.h>
int main(int argc,char*argv[])
{
    struct hostent*hen;
    if(argc!=2)
    {
        fprintf(stderr,"enter host name:");
    }
    hen=gethostbyname(argv[1]);
    if(hen==NULL)
    {
      fprintf(stderr,"hostname not found");
    }
    printf("\nHostname:%s",hen->h_name);
    printf("\nIP Address:%s",inet_ntoa(*((struct in_addr*)hen->h_addr)));
}

