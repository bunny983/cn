#include<stdio.h>
int rem(int,int);
int i,j,k,n,dl,dil;
int data[30],div[20],newdata[30],revdata[30],crc[20],datacrc[20],remd[20];
int main()
{
    printf("enter data length:");
    scanf("%d",&dl);

    printf("\nenter divisor length:");
    scanf("%d",&dil);

    printf("\nenter data :");
    for(i=0;i<dl;i++)
         scanf("%d",&data[i]);

    printf("\nenter divisor :");
    for(i=0;i<dil;i++)
         scanf("%d",&div[i]);

    printf("\nThe new data is: ");
    for(i=0;i<(dl+dil-1);i++)
    {
        if(i<dl)
           newdata[i]=data[i];
        else
           newdata[i]=0;
        printf("%d",newdata[i]);
    }
    for(j=0;j<=dl;j++)
    {
        for(i=0;i<dil;i++)
        {
            crc[i]=newdata[i+j];
            if(crc[0]==1)
                 newdata[i+j]=rem(newdata[i+j],div[i]);
            else
                 newdata[i+j]=rem(newdata[i+j],0);
        }
        printf("\nThe crc is:");
        for(i=0;i<dil-1;i++)
            printf("%d",crc[i]);
    }
    printf("\nThe data to be send:");
    for(i=0;i<(dl+dil-1);i++)
    {
        if(i<dl)
           datacrc[i]=data[i];
        else
           datacrc[i]=crc[i-dl];
        printf("%d",datacrc[i]);
    }
    printf("\nenter receiver data:");
    for(i=0;i<(dl+dil-1);i++)
          scanf("%d",&revdata[i]);
    for(j=0;j<=dl;j++)
    {
        for(i=0;i<dil;i++)
        {
            remd[i]=revdata[i+j];
            if(remd[0]==1)
                 revdata[i+j]=rem(revdata[i+j],div[i]);
            else
                 revdata[i+j]=rem(revdata[i+j],0);
        }
        printf("\nThe remainder is:");
        k=0;
        for(i=0;i<dil-1;i++)
            printf("%d",remd[i]);
        if(remd[k]==0)
            k++;
    }
    if(k==dil-1)
          printf("\n no error found");
    else
          printf("\n error");
}
int rem(int x,int y)
{
    if(x==y)
       return 0;
    else
       return 1;
}
