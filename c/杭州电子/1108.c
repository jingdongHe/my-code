#include<stdio.h>
int main()
{
    int a,b,r,k,m,n;
     
    while(scanf("%d%d",&a,&b)!=EOF&&a>=0&&b>=0&&a<=1000&&b<=1000)
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
    }
    return 0;
}