#include<stdio.h>
int main(void)
{
    int x,y,n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    while((a>0)&&(b<10));
    {
      --a;
      --b;
    }
    printf("%d%d",a,b);
    while((a<=n)&&(b<=n))
    {
      printf("(%d,%d)",a,b);
      a++;
      b++;
    }
    printf("\n");
    return 0;
    scanf("%d",a);
}
