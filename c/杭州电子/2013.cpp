#include<stdio.h>
#include<math.h>
int main()
{
    int n,i;
    long d=1;
    while(scanf("%d",&n)!=EOF){
    for(i=1;i<n;i++)
    d=2*(d+1);
    printf("%ld\n",d);
    d=1;}
    return 0;
}
