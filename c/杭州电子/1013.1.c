#include<stdio.h>
int main()
{
	long n,m=0;
	while(scanf("%ld",&n)!=EOF,n!=0)
	{
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
		printf("%ld\n",n);
	}
	return 0;
}
