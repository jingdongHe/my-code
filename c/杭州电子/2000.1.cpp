#include<stdio.h>
int main()
{
  char a,b,c,d;
  while(scanf("%c%c%c",&a,&b,&c)!=EOF)
  {getchar();
  if(a>b){d=a;a=b;b=d;}
  if(c>a){if(b>c){d=b;b=c;c=d;}}
  if(c<a){d=a;a=c;c=d;d=b;b=c;c=d;}
  printf("%c %c %c\n",a,b,c);}
  return 0;
}
