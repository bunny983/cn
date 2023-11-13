#include<stdio.h>
#include<string.h>
int main()
{
int costmat[20][20],flag[20],dist[20],last[20];
int i,j,k,v,w,count,src_router,min;
printf("enter no of routers:");
scanf("%d",&count);

printf("\n enter matrix:\n");
for(i=0;i<count;i++)
{
 for(j=0;j<count;j++)
	{
	 printf("%d->%d:",i,j);
	 scanf("%d",&costmat[i][j]);
	if(costmat[i][j]<0)
	    costmat[i][j]=1000;
	}
}
printf("\n enter source router");
scanf("%d",&src_router);
for(v=0;v<count;v++)
{
	flag[v]=0;
	last[v]=src_router;
	dist[v]=costmat[src_router][v];
}
flag[src_router]=1;
for(i=0;i<count;i++)
{
	min=1000;
	for(w=0;w<count;w++)
	{
		if(!flag[w])
		if(dist[w]<min)
		{
			v=w;
			min=dist[w];
		}
	}
	flag[v]=1;
	for(w=0;w<count;w++)
	{
		if(!flag[w])
		if(min+costmat[v][w]<dist[w])
		{
		    dist[w]=min+costmat[v][w];
		    last[w]=v;
		}
	}
}
for(i=0;i<count;i++)
{
	printf("%d==>%d path taken:%d",src_router,i,i);
	w=i;
	while(w!=src_router)
	{
		printf("<--%d",last[w]);
		w=last[w];
	}
	printf("\nshortest path cost:%d",dist[i]);
}
}
