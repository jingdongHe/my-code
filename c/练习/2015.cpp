#include<stdio.h>
int main()
{
    int n,m,i,d,k,j;
    float a,r;
    while(scanf("%d%d",&n,&m)!=EOF){ 
    j=n%m;d=0;k=0;
    for(i=1;i<=n-j;i++)
    {d+=2;
    k+=d;
    if(i%m==0)
    {a=k/m;k=0;printf("%0.0f",a);if(i<n) printf(" ");}}
    if(j!=0)
    {
    for(i=j;i<m;i++)
    {d+=2;k+=d;}
    r=k/(n-m);
    printf("%0.0f",r);}
    printf("\n");}
    return 0;
}
