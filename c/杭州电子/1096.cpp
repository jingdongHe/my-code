#include<stdio.h>
int main()
{
    int n,m,sum=0,i,a;
    scanf("%d",&n);
    while(n>0)
    {scanf("%d",&m);
    for(i=1;i<=m;i++)
    {scanf("%d",&a);
    sum+=a;}
    printf("%d\n",sum);
    sum=0;
    n--;
    if(n>0)printf("\n");
    }
}
