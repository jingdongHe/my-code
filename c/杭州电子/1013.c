#include<stdio.h>
int main()
{
	int n,sum=0,m;
	scanf("%d",&n);
	while(n!=0)
	{
	while(n>=10)
	{
		sum+=n%10;
		m=n/10;
		n=m%10;
	}
	sum+=n;
	while(sum>=10)
	{
		n=sum;
		sum=0;
		while(n>=10)
		{
			sum+=n%10;
			m=n/10;
			n=m%10;
		}
		sum+=n;
	}
	printf("%d\n",sum);
	sum=0;
	scanf("%d",&n);
	}
	return 0;
}

