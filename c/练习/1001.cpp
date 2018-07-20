#include<stdio.h>
int main(void)
{
  long long int a=0,b=0,r=0,i=0,m=0,n=0;
  scanf("%lld%lld",&a,&b);
  while(a!=0&&b!=0)
  {
  m=a;
  n=b;
  if(b>a)
  {
    i=a;
    a=b;
    b=i;
  }
  r=a%b;
  while(r!=0)
  {
    a=b;
    b=r;
    r=a%b;
  }
  printf("%lld\n",(m*n)/b);
  scanf("%lld%lld",&a,&b);
  }
  return 0;
}
