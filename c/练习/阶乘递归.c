#include<stdio.h>
int jc(int n)
{
	if(n==0||n==1)
		return 1;
	else
		return n*jc(n-1);
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",jc(n));
	return 0;
}