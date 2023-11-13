#include<stdio.h>
#include<string.h>
int main()
{
    int i,j;
    char a[30],b[40]="",start,end,x[3],y[3],s[3],t[3],d[3];
    printf("enter character array:");
    scanf("%s",a);
    printf("\nenter starting delimiter :");
    scanf(" %c",&start);
    printf("\nenter ending delimiter :");
    scanf(" %c",&end);

    x[0]=s[0]=s[1]=start;
    x[1]=s[2]='\0';
    y[0]=d[0]=d[1]=end;
    d[2]=y[1]='\0';
    strcat(b,x);
    for(i=0;i<strlen(a);i++)
    {
        t[0]=a[i];
        t[1]='\0';
        if(t[0]==start)
            strcat(b,s);
        else if(t[0]==end)
            strcat(b,d);
        else
            strcat(b,t);
    }
    strcat(b,y);
    printf("\nAfter stuffing:%s",b);
}
