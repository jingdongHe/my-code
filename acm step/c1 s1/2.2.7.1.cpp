#include<stdio.h>
int main()
{
    int m=0,i=0,n=0,j;
    char a[1000];
    while(gets(a)!=NULL,a[0]>'0')
    {
    while(a[i]!='\0')
    {
        n+=a[i]-48;
        i++;
    }
    while(n>=10)
    {
        m+=n%10;
        n/=10;
        if(n<10)
        {
            m+=n;
            n=m;
            m=0;
        }
    }
    printf("%d\n",n);
    for(j=0;j<i;j++)
        a[j]='\0';
    i=0;m=0;n=0;
    }
    return 0;
}

