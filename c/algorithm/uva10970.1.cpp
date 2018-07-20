#include<stdio.h>
int main()
{
	int m,n;
	int sum;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		sum=0;
		sum+=m-1;
		sum+=m*(n-1);
		printf("%d\n",sum);
	}
	return 0;
}