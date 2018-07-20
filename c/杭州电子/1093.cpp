#include<stdio.h>
int main()
{
    int n,t,sum=0,i,a;
    scanf("%d",&n);
    while(n>0)
    {scanf("%d",&t);
    for(i=1;i<=t;i++)
    {scanf("%d",&a);
    sum+=a;}
    printf("%d\n",sum);
    sum=0;
    n--;
    }
}
