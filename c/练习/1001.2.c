#include<stdio.h>
int main(void)
{
  int a,b,r,i,m,n;
  scanf("%d%d",&a,&b);
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
  printf("%d",(m*n)/b);
  return 0;
}
