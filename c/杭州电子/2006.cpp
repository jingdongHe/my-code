#include<stdio.h>
int main()
{
    int n,a[100],i;
    long p=1;
    while(scanf("%d",&n)!=EOF){
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        if(a[i]%2!=0)
        p*=a[i];
    }
    printf("%ld\n",p);p=1;}
    return 0;
}
    
