#include<stdio.h>
int main()
{
    int m,n,i,d;
    
    scanf("%d%d",&m,&n);
    if(m<n){ d=m;m=n;n=d;}
    i=m%n;
    if(i==0)
    printf("%d",n);
    else{
    while(i==0)
    {m=n;n=i;i=m%n;}
    printf("%d",n);}
    return 0;
}
