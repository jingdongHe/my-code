#include<stdio.h>
int main(void)
{
    int a,b,r,k,m,n;
     
    scanf("%d%d",&a,&b);
    while(a!=0&&b!=0)
    {
      m=a;
      n=b;
      if(b>a)
      {
        k=a;
        a=b;
        b=k;
      }
      r=a%b;
      while(r!=0)
      {
        a=b;
        b=r;
        r=a%b;
      }
      printf("%d\n",(m*n)/b);
      scanf("%d%d",&a,&b);
    }
    return 0;
}
