#include<stdio.h>
#include<string.h>
void main()
{
    int a[30],b[40],i,j,k,count,n;
    printf("enter frame length:");
    scanf("%d",&n);
    printf("\nenter frame:");
    for(i=0;i<n;i++)
       scanf("%d",&a[i]);
       i=0;j=0;count=1;
    while(i<n)
    {
        if(a[i]==1)
        {
            b[j]=a[i];
            for(k=i+1;a[k]==1&&k<n&&count<5;k++)
            {     
                    j++;
                    b[j]=a[k];
                    count++;
                    if(count==5)
                    {
                        j++;
                        b[j]=0;
                    }
                i=k;
            }
        }
        else{
             b[j]=a[i];   
         }
         i++;
         j++;
    }
    printf("\n After stuffing:");
    for(i=0;i<j;i++)
        printf("%d",b[i]);
}
