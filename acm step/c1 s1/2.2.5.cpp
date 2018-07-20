#include<stdio.h>
int n;
int s(int a)
{
	return (1+a*(a+1)/2)*(1+(n-a)*(n-a+1)/2);
}
int main()
{
	
	while(scanf("%d",&n)!=EOF)
	{
		int k=0;
		for(int i=1;i<=n;i++)
		{
			int f=s(i);
			//printf("%d...\n",f);
			k=f>k?f:k;
		}
		printf("%d\n",k);
	}
	return 0;
}
