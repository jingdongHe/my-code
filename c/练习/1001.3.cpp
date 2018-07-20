#include<stdio.h>
int main(void)
{
  int a,b,r,i,m,n;
  scanf("%d%d",&a,&b);
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
  printf("%l",(m*n)/b);
  scanf("%d%d",&a,&b);
  }
  return 0;
}
