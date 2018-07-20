#include<stdio.h>
int main()
{
    int m,n,i,j,k=1;
    float d;
    double t;
    
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {d=0;scanf("%d",&n);
    for(j=1;j<=n;j++)
    {  if(j%2==0)k=-1;
       else k=1;
       t=(double)1/j;t=k*t;d+=t;}
    printf("%0.2f\n",d);}
    return 0;
}
