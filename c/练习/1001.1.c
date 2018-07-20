#include<stdio.h>
int main(void)
{
  long a,b,r,i,k;
  scanf("%l%l",&a,&b);
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
  return 0;
}
  
