#include<stdio.h>
int main()
{
	long n,i;
	int f0,f1;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		{f0=7;printf("no\n");continue;}
		if(n==1)
		{f0=11;printf("no\n");continue;}
		f0=7;f1=11;
		for(i=2;i<=n;i++)
		{
			if(i%2==0)
			{
				f0=f1+f0;
				while(f0>=3)
					f0-=3;
			}
			else
			{
				f1=f1+f0;
				while(f1>=3)
					f1-=3;
			}
		}
		if(n%2==0)
		{
			if(f0==0)
				printf("yes\n");
			else
				printf("no\n");
		}
		else
		{
			if(f1==0)
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0;
}