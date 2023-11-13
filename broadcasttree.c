#include<stdio.h>
#include<stdlib.h>
int p,q,i,j,n,u,v;
int min=99,mincost=0;
int t[50][2],parent[50],edge[50][50];
void Sunion(int l,int m)
{
	parent[l]=m;
}
int find(int k)
{
	if(parent[k]>0)
	   k=parent[k];
	   return k;
}
int main()
{
	printf("enter no of nodes:");
	scanf("%d",&n);
	
	printf("enter edge matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&edge[i][j]);
	}
	
	for(i=0;i<n;i++)
	{
     for(j=0;j<n;j++)
	 if(edge[i][j]!=99)
	  if(min>edge[i][j])
	  {
	  	min=edge[i][j];
	  	u=i;
	  	v=j;
	  }
	  	p=find(u);
	  	q=find(v);
	  	if(p!=q)
	  	{
	  		t[i][0]=u;
	  		t[i][1]=v;
	  		mincost=mincost+edge[i][j];
	  		Sunion(p,q);
		  }
		  else
		  {
		  	t[i][0]=-1;
	  		t[i][1]=-1;
		  }
		  min=99;
	  }
	printf("\nminimum cost %d\n minimum spanning tree:\n",mincost);
	  for(i=0;i<n;i++)
	  if(t[i][0]!=-1 && t[i][1]!=-1)
	  {
	  	printf("%c %c %d",65+t[i][0],65+t[i][1],edge[t[i][0]][t[i][1]]);
	  	printf("\n");
	  }
}
