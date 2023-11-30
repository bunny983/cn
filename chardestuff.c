#include<stdio.h>
#include<string.h>
int main()
{
	char a[]="ncnnlaaba",b[30]="";
	char start='n',end='a';
	int i=0,j=0,n;
	if(a[i]==start)
	 i++;
	while(i<strlen(a))
	{
		if(i==strlen(a)-1 && a[i]==end)
		break;
		if(a[i]==start && a[i+1]==start)
		{
			b[j]=a[i];
			j++;
			i+=2;
		}
		else if(a[i]==end && a[i+1]==end)
		{
			b[j]=a[i];
			j++;
			i+=2;
		}
		else
		{
			b[j]=a[i];
			j++;
			i++;
		}
	}
	printf("%s ",b);
	
}
