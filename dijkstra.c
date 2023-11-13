#include<stdio.h>
#define INFINITY 9999
void dijkstra(int graph[10][10],int n,int start);
void dijkstra(int graph[10][10],int n,int start)
{
	int i,j,mindistance,count,nextnode;
	int costmat[20][20],dist[20],visited[20],pred[20];
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(graph[i][j]==0)
			     costmat[i][j]=INFINITY;
			else
			    costmat[i][j]=graph[i][j];
		}
	}
	
	for(i=0;i<n;i++)
	{
		dist[i]=costmat[start][i];
		pred[i]=start;
		visited[i]=0;
	}
	visited[start]=1;
	dist[start]=0;
	count=1;
	while(count<n-1)
	{
		mindistance=INFINITY;
		for(i=0;i<n;i++)
		if(mindistance>dist[i]&&!visited[i])
		{
			mindistance=dist[i];
			nextnode=i;
		}
	visited[nextnode]=1;
	for(i=0;i<n;i++)
	if(mindistance+costmat[nextnode][i]<dist[i])
	{
		dist[i]=mindistance+costmat[nextnode][i];
		pred[i]=nextnode;
	}
	 count++;
	}
	
	for(i=0;i<n;i++)
	{
		if(i!=start)
		{
			printf("distance from source to %d is %d\n",i,dist[i]);
		}
	}
}
int main()
{
	int graph[10][10],i,j,n,u;
	n=6;
	printf("enter graph:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	u=0;
	dijkstra(graph,6,u);
	return 0;
}
