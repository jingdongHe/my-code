#include<stdio.h>
int main()
{
    int a,b;
    long f1,f2,n,i,k,d;
    while(scanf("%d%d%ld",&a,&b,&n)!=EOF&&(a&&b&&n))
    {
        f1=1;f2=1;
        if((n==1)||(n==2))
            k=1;
        if(n>=3)
        {
            for(i=3;i<=n;i++)
            {
                if(i%2!=0)
                {d=f2;f2=(a*f1+b*f2)%7;f1=d;printf("%d:%ld    %ld\n",i,f1,f2);}
                else
                {f1=(a*f1+b*f2)%7;printf("%d:%ld    %ld\n",i,f1,f2);}
            }
            if(n%2==0)
                k=f2;
            else
                k=f1;
        }
        printf("%ld\n",k);
    }
    return 0;
}