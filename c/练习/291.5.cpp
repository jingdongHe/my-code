#include<stdio.h>
#define n 9
int main()
{
    int a[n],*p,i=1,j,d=n,k;
    p=a;
    
    while(d>1)
    {for(j=0;j<d;j++)
    i=1;
    if(*(p+j)!=0){
      {if((j+1)%3==0)
        {*(p+j)=0;i++;printf("(%d)\n",*(p+j));}
     if(d>3)
     d=d-d/3;
     else
     d--;
     i=i%3+1;
     printf("%d****%d\n",d,i);
     }
    }
    for(j=0;j<d;j++)
    {if(*(p+j)!=0)
      printf("%d",j+1);}}}
    printf("*******");
    return 0;
}
