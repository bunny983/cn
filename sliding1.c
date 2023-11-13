#include<stdio.h>
int main()
{
	int w,f,i,frames[20];
	printf("enter window size:");
	scanf("%d",&w);
	printf("\n enter no of frames:");
	scanf("%d",&f);
	printf("\n enter frames:\n");
	for(i=1;i<=f;i++)
	   scanf("%d",&frames[i]);
	printf("\nafter sending data %d from the receiver\n",w);
	for(i=1;i<=f;i++)
	{
		if(i%w==0)
		{
			printf("%d\t",frames[i]);
			printf("\nacknowledgement sent is received by sender\n");
		}
		else
		{
			printf("%d\t",frames[i]);
		}
	}
	if(f%w!=0)
	{
		printf("\nacknowledgement sent is received by sender\n");
	}
}
