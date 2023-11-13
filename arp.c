#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include<math.h>
#include<complex.h>
#include<inet/arpa.h>
#include<net/ethernet.h>
#include<net/if_arp.h>
#include<netinet/in.h>
#include<netinet/if_ether.h>
int main(int argc,char*argv[])
{
	struct sockaddr_in sin={0};
	struct arpreq myarp={{0}};
	unsigned char*ptr;
	int sd;
	sin.sin_family=AF_INET;
	if(inet_aton(argv[1],&sin.sin_addr)==0)
	{
		printf("IP address %s not valid\n",argv[1]);
		exit(0);
	}
	memcpy(&myarp.arp_pa,&sin,sizeof(myarp.arp_pa));
	strcpy(myarp.arp_dev,"echo");
	sd=socket(AF_INET,SOCK_DGRAM,0);
	if(ioctl(sd,SIOCGARP,&myarp)==1)
	{
		printf("No entry in ATP cache for %s\n",argv[1]);
		exit(0);
	}
	ptr=&myarp.arp_pa.sa_data[0];
	printf("MAC address for %s:\n",argv[1]);
	printf("%x:%x:%x:%x:%x:%x\n",*ptr,(*ptr+1),(*ptr+2),(*ptr+3),(*ptr+4),(*ptr+5));
	return 0;
}
