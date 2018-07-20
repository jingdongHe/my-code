#include<stdio.h>
int res(int n)
{
	if(n==1) return 2;
	return res(n-1)+n*(n-1)/2+1;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",res(n));
	}
	return 0;
}
