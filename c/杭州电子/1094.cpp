#include<stdio.h>
int main()
{
    int i,t,sum=0,a;
    while(scanf("%d",&t)!=EOF)
    {

      for(i=0;i<t;i++)
      {scanf("%d",&a);sum+=a;}
      printf("%d\n",sum);
      sum=0;
    }
}
