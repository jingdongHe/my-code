#include<stdio.h>
int main(void)
{
    int f[100000000],n,j=0,k;
    
    f[0]=0;
    f[1]=1;
    scanf("%d",&n);
    while(j+2>=n)
    {
    f[j+2]=f[j]+f[j+1];
    j++;
    }
    k=f[j+2];
    printf("%d",k%10000);
    return 0;
}
    
    
    
    
