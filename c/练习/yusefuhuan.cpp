#include<stdio.h>
#define n=9
int main()
{
    int a[n-1],*p,i=1,j;
    
    for(i=0;i<(n-1);i++)
    a[i]=i+1;
    *p=a[0];
    while(n>1)
    {
      for(j=0;j<n;j++)
      {if((i%3)==0)
      *(p+j)=0;i++;}
      if(n>3)
      n-=n/3;
      else
      n--;
      i=i%3+1;
    }
    for(j=0;j<n;j++)
    {if(*(p+j)!=0)
    printf("%d",j+1);}
}
      
    
