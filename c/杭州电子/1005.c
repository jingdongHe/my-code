#include<stdio.h>
#include<string.h>
int c[1000001];
int main()
{
    long n;
    int a,b,x=0,i=0;
    scanf("%d%d%d",&a,&b,&n);
    while(a&&b&&n)
    {
        c[0]=1;c[1]=1;
		n=n%48;
        for(i=2;i<n;i++)
        {
            c[i]=(a*c[i-1]+b*c[i-2])%7;
        }
        printf("%d\n",c[n-1]);
        while(c[x]!='\0')
            x++;
        memset(c,'\0',x);
        x=0;
        scanf("%d%d%d",&a,&b,&n);
    }
    return 0;
}
