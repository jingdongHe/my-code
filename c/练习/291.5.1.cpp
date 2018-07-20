#include<stdio.h>
#define n 6
int main()
{
    int d,a[n],*p,i=1,j;
    p=a;
    d=n;
    
    while(d>1)
    {for(j=0;j<n;j++)
      {if((i%3)==0)
        {while(*(p+j)==0) {j++;}
        *(p+j)=0;i++;}
      }
     if(d>3)
     d=d-d/3;
     else
     d--;
     i=i%3+1;
    }
    for(j=0;j<d;j++)
    {if(*(p+j)!=0)
      printf("%d\n",j);}
    return 0;
}
