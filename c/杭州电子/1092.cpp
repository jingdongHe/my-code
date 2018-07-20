#include<stdio.h>
int main()
{
    int t,i,sum=0,a;
    scanf("%d",&t);
    while(t!=0){
    for(i=1;i<=t;i++)
    {scanf("%d",&a);
    sum+=a;}
    printf("%d\n",sum);scanf("%d",&t);sum=0;}
}
    
              
