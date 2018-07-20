#include<stdio.h>
int main()
{
  char a,b,c,x,y,z;
  while(scanf("%d%d%d",&a,&b,&c)!=EOF)
  {getchar();printf("%c%c%c\n",a,b,c);
  z=a>b?a:b;
  z=b>c?b:c;
  z=a>c?a:c;
  x=a<b?a:b;
  x=b<c?b:c;
  x=a<c?a:c;
  y=a+b+c-x-z;
  putchar(x);printf(" ");putchar(y);printf(" ");putchar(z);printf(" *\n");}

}
