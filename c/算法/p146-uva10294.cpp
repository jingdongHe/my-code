#include<stdio.h>
int gcd(int a,int b)
{
    int t;
    if(b==0)
    return a;
    while(t=a%b)
    {
        a=b;
        b=t;
    }
    return b;
}
int main()
{
	int pow[30];
	int t,n;
	while(scanf("%d%d",&n,&t))
	{
		pow[0]=1;
		int i;
		for(i=1;i<=n;i++)
			pow[i]=pow[i-1]*t;
		int a=0,d;
		for(i=0;i<n;i++)
		{
			d=gcd(n,i);
			a+=pow[d];
		}
		int b=0;
		if(b%2==0)
			b=n/2*(pow[n/2+1]+pow[n/2]);
		else
			b=n*pow[(n+1)/2];
		printf("%d %d\n",a/n,(a+b)/n);
	}
	return 0;
}