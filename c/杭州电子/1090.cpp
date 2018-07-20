#include<stdio.h>
int main()
{
    int N,a,b,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
      scanf("%d%d",&a,&b);
      printf("%d\n",a+b);
    }
    return 0;
}
