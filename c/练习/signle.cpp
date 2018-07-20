#include<stdio.h>
int main()
{
    int t,n,i,j=0,m,d;
    scanf("%d",&t);
    for(i=1;i<t;i++)
    {
      scanf("%d",&n);
      m=n;
      if(n-4>0)
      {
      j++;
      n=n-4;
      }
      if(n==3)
      j++;
      d=((n*365+j)%7)+3;
      if(d>7)
      d=d-7;
      printf("%d\n",d);
    }
    return 0;
}
      
        
